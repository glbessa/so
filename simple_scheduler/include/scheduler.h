#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdlib.h>

#include "virtual_machine.h"
#include "task.h"

typedef struct Scheduler Scheduler;
struct Scheduler {
    int num_tasks;
    int quantum;
    int quantum_left;
    int total_exec_time;
    Task **tasks;
    int (*policy) (const void *t1, const void *t2);
};

void schedule(Scheduler *scheduler);
void dispatch(Vm *vm, Scheduler *Scheduler);
void dispatch_core(int core_id, Core *core, Scheduler *scheduler);

#endif