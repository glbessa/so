#include "virtual_machine.h"

void vm_run(Vm *vm) {
    for (int i = 0; i < vm->num_cores; i++) {
        vm->cores[i].task->execution_time += 1;
        vm->cores[i].task->time_left -= 1;

        if (vm->cores[i].task->time_left == 0)
            vm->cores[i].task->state = FINISHED;
    }
}

void vm_run_quantum(Vm *vm, int quantum) {
    for (int i = 0; i < vm->num_cores; i++) {
        if (vm->cores[i].task->time_left < quantum) {
            vm->cores[i].task->execution_time += vm->cores[i].task->time_left;
            vm->cores[i].task->time_left = 0;
        } else {
            vm->cores[i].task->execution_time += quantum;
            vm->cores[i].task->time_left -= quantum;
        }
    }
}

void vm_print_cores(Vm *vm) {
    printf("---------------------------\n");
    for (int i = 0; i < vm->num_cores; i++) {
        printf("Core %d - Task %s\n", i, vm->cores[i].task->id);       
    }
    printf("---------------------------\n");
}