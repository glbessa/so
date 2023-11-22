#include "utils.h"

LinkedList * parse_tasksfile(FILE *file) {
    LinkedList *tasks = NULL;

    while (feof(file)) {
        char *buf = (char *) malloc(sizeof(char) * 30);
        int time_left;
        fscanf(file, "%s %d", buf, &time_left);

        Task *task = task_create(buf, 0, time_left);
        linkedlist_append(tasks, task);
    }

    return tasks;
}

LinkedList * read_tasksfile(char * filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error while opening tasks file");
        return NULL;
    }

    LinkedList *tasks = parse_tasksfile(file);

    fclose(file);

    return tasks;
}

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

void print_help() {
    printf("");
}