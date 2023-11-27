#ifndef VIRTUAL_MACHINE_H
#define VIRTUAL_MACHINE_H

#include "task.h"

typedef enum Interruption Interruption;
enum Interruption {
    SYS_EXIT
};

typedef struct Core Core;
struct Core {
    Task *task;
};

typedef struct Vm Vm;
struct Vm {
    int num_cores;
    Core *cores;
    void (*interruption_handler) (Interruption inter);
};

void vm_run(Vm *vm);
void vm_run_quantum(Vm *vm, int quantum);
void vm_print_cores(Vm *vm);

#endif