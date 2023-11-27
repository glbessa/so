#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "virtual_machine.h"
#include "scheduler.h"
#include "task.h"

#define BUFFER_MAX_LEN 30

int parse_tasksfile(FILE *file, Task **tasks);
int read_tasksfile(char * filename, Task **tasks);
void stats_print(FILE *file, Vm *vm, Scheduler *scheduler);
void print_help();

#endif