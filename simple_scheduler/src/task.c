#include "task.h"

Task * task_create(char * id, int execution_time, int time_left) {
    Task *task = (Task *) malloc(sizeof(Task));
    if (task == NULL) {
        fprintf(stderr, "Error while creating task");
    }

    task->id = id;
    task->execution_time = execution_time;
    task->time_left = time_left;

    return task;
}

int has_tasks_not_finished(Task **tasks, int length) {
    for (int i = 0; i < length; i++) {
        if (tasks[i]->state != FINISHED)
            return 1;
    }

    return 0;
}

void task_print(Task *task) {
    if (task == NULL) 
        return;

    //printf("Task: %d", task->time_left);
    printf("Task: %s - State: %d - Time executed: %d - Time left: %d\n", task->id, task->state, task->execution_time, task->time_left);
}

void task_destroy(Task *task) {
    if (task == NULL)
        return;

    free(task->id);
    free(task);
}

void tasks_destroy(Task **tasks, int length) {
    if (tasks == NULL)
        return;

    for (int i = 0; i < length; i++) {
        if (tasks[i] != NULL)
            task_destroy(tasks[i]);
    }

    free(tasks);
}

void tasks_print_running(Task **tasks, int length) {
    if (tasks == NULL)
        return;

    for (int i = 0; i < length; i++)
        if (tasks[i]->state == RUNNING)
            task_print(tasks[i]);
}

void tasks_print_ready(Task **tasks, int length) {
    if (tasks == NULL)
        return;

    for (int i = 0; i < length; i++)
        if (tasks[i]->state == READY)
            task_print(tasks[i]);
}

void tasks_print(Task **tasks, int length) {
    if (tasks == NULL)
        return;

    printf("\nTasks ------------------------\n");
    for (int i = 0; i < length; i++) {
        task_print(tasks[i]);
    }
    printf("------------------------------\n");
}