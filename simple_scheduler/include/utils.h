#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

typedef struct Task Task;
struct Task {
    char * id;
    int execution_time;
    int time_left;
};

typedef struct Core Core;
struct Core {
    int id;
    Task *running_task;
};

LinkedList * parse_tasksfile(FILE *file);
LinkedList * read_tasksfile(char * filename);

#endif