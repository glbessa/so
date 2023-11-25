#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "linkedlist.h"
#include "utils.h"

int main(int argc, char **argv) {
    if (argc < 3 || (argc <= 2 && (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0))) {
        print_help();
        return 0;
    }

    // Reading tasks file
    time_t begin_io = time(NULL);
    LinkedList *tasks = read_tasksfile(argv[1]);
    time_t end_io = time(NULL);
    printf("Total IO time: %f\n", difftime(end_io, begin_io));

    // Simulating
    time_t begin = time(NULL);
    
    time_t end = time(NULL);
    double ellapsed_time = difftime(end, begin);
    printf("Total time ellapsed: %f\n", ellapsed_time);

    linkedlist_destroy(tasks, DESTROY_ITEMS);

    return 0;
}