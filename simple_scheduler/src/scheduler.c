#include "scheduler.h"

void schedule(Scheduler *scheduler) {
    qsort(scheduler->tasks, scheduler->num_tasks, sizeof(Task *), scheduler->policy);
}

void dispatch(Vm *vm, Scheduler *scheduler) {
    for (int i = 0; i < vm->num_cores; i++) {
        if (vm->cores[i].task == NULL || vm->cores[i].task->state == FINISHED) {
            dispatch_core(i, &vm->cores[i], scheduler);
        }
    }
}

void dispatch_core(int core_id, Core *core, Scheduler *scheduler) {
    for (int j = 0; j < scheduler->num_tasks; j++) {
        if (scheduler->tasks[j]->state == READY) {
            scheduler->tasks[j]->start_exec = scheduler->total_exec_time;
            scheduler->tasks[j]->core_id = core_id;
            core->task = scheduler->tasks[j];
            scheduler->tasks[j]->state = RUNNING;
            break;
        }
    }
}