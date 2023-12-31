#ifndef TASK_H
#define TASK_H

#include <stdlib.h>
#include <stdio.h>

typedef enum State State;
enum State {
    NEW,
    READY,
    RUNNING,
    WAITING,
    FINISHED
};

typedef struct Task Task;
struct Task {
    char * id;
    State state;
    int core_id;
    int execution_time;
    int time_left;
    int arrival_time;
    int started_time;
    int finished_time;
};

Task * task_create(char * id, int execution_time, int time_left);
int has_tasks_not_finished(Task **tasks, int length);
void task_print(Task *task);
void task_destroy(Task *task);
void tasks_destroy(Task **tasks, int length);
void tasks_print(Task **tasks, int length);
void tasks_print_running(Task **tasks, int length);

#endif