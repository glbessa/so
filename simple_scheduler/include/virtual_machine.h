#ifndef VIRTUAL_MACHINE_H
#define VIRTUAL_MACHINE_H

#include "utils.h"

typedef struct Core Core;
struct Core {
    int id;
    Task *task;
};

#endif