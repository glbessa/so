#include "utils.h"

int parse_tasksfile(FILE *file, Task **tasks) {
    if (tasks == NULL) {
        fprintf(stderr, "Error while creating tasks");
    }

    int c;
    int counter = 0;
    int reading_name = 0;
    char *buffer = malloc(sizeof(char) * BUFFER_MAX_LEN);
    int buffer_counter = 0;

    Task *task = malloc(sizeof(Task));
    task->state = READY;

    while ((c = fgetc(file)) != EOF) {
        
        //printf("%c", c);

        if (isalpha(c)) {
            reading_name = 1;
            buffer[buffer_counter++] = c;
        }
        else if (isblank(c) || (buffer_counter >= BUFFER_MAX_LEN - 1 && reading_name)) {
            reading_name = 0;
            buffer[buffer_counter] = '\0';

            task->id = buffer;
            //printf("%s\n", task->id);

            buffer = malloc(sizeof(char) * BUFFER_MAX_LEN);
            buffer_counter = 0;
        }
        else if (reading_name) {
            buffer[buffer_counter++] = c;
        }
        else if (isdigit(c)) {
            buffer[buffer_counter++] = c;
        }
        else if (isspace(c)) {
            buffer[buffer_counter] = '\0';

            task->time_left = atoi(buffer);
            task->execution_time = 0;

            tasks[counter++] = task;

            task = malloc(sizeof(Task));
            task->state = READY;

            buffer = malloc(sizeof(char) * BUFFER_MAX_LEN);
            buffer_counter = 0;
        }
    }

    free(buffer);
    free(task);

    return counter;
}

int read_tasksfile(char * filename, Task **tasks) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error while opening tasks file");
        return -1;
    }

    int len = parse_tasksfile(file, tasks);

    fclose(file);

    return len;
}

void stats_print(FILE *file, Vm *vm, Scheduler *scheduler) {
    for (int i = 0; i < vm->num_cores; i++) {
        fprintf(file, "Processador_%d\n", i);
        for (int j = 0; j < scheduler->num_tasks; j++) {
            if (scheduler->tasks[j]->core_id == i) {
                fprintf(file, "%s;%d;%d\n", scheduler->tasks[j]->id, scheduler->tasks[j]->start_exec, scheduler->tasks[j]->finish_exec);
            }
        }
        fprintf(file, "\n");
    }
}

void print_help() {
    printf("\nUsage:\n");
    printf("    simple_scheduler <tasks_file> <quantum> <num_cores> <sched_policy>\n");
    printf("\nOptions:\n");
    printf("    sched_policy: Schedule policy\n");
    printf("        sjf - shortest job first [default]\n");
    printf("        sjl - shortest job last\n");
    printf("\n\n");
}