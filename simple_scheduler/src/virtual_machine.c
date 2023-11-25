#include "virtual_machine.h"

void core_insert_task(Core *core, Task *task) {
    if (core == NULL || task == NULL) 
        return;

    core->task = task;
}