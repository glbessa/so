#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "policies.h"
#include "scheduler.h"
#include "virtual_machine.h"
#include "task.h"
#include "utils.h"

#define MAX_TASKS 30

int main(int argc, char **argv) {
    if (argc < 4 || strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
        print_help();
        return 0;
    }

    // Creating vm
    Vm *vm = malloc(sizeof(Vm));
    vm->num_cores = atoi(argv[3]);
    vm->cores = malloc(sizeof(Core) * vm->num_cores);

    // Creating scheduler
    Scheduler *scheduler = malloc(sizeof(Scheduler));
    scheduler->tasks = malloc(sizeof(Task *) * MAX_TASKS);
    scheduler->quantum = atoi(argv[2]);
    scheduler->total_exec_time = 0;
    scheduler->policy = &shortest_job_first;

    char *stats_filename = "stats.txt";

    if (argc >= 5) {
        if (strcmp(argv[4], "sjl") == 0) {
            scheduler->policy = &shortest_job_last;
        }
    }
    if (argc == 6) {
        stats_filename = argv[5];
    }
    
    // Reading tasks file
    printf("Reading from file %s\n", argv[1]);
    scheduler->num_tasks = read_tasksfile(argv[1], scheduler->tasks);
    printf("Reading complete. Total tasks: %d\n", scheduler->num_tasks);
    tasks_print(scheduler->tasks, scheduler->num_tasks);

    // Simulating
    printf("\nBegining simulation\n");

    while(has_tasks_not_finished(scheduler->tasks, scheduler->num_tasks)) {
        if (scheduler->total_exec_time % scheduler->quantum == 0) {
            schedule(scheduler);
        }

        dispatch(vm, scheduler);
        vm_run(vm);
        vm_print_cores(vm);
        scheduler->total_exec_time += 1;

        // Check for finished tasks
        for (int i = 0; i < scheduler->num_tasks; i++) {
            if (scheduler->tasks[i]->time_left == 0) {
                if (scheduler->tasks[i]->finished_time == 0)
                    scheduler->tasks[i]->finished_time = scheduler->total_exec_time;
                scheduler->tasks[i]->state = FINISHED;
            }
        }
    }

    printf("\nSimulation finished\n");
    printf("Total execution time: %d\n", scheduler->total_exec_time);

    printf("Saving statistics in %s\n", stats_filename);
    write_statsfile(stats_filename, vm, scheduler);

    // Cleaning everything
    clean_everything(vm, scheduler);

    return 0;
}