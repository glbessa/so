#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "linkedlist.h"
#include "utils.h"

int main(int argc, char **argv) {
    if (argc <= 3 || (argc <= 2 && (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0))) {
        print_help();
    }

    LinkedList *tasks = read_tasksfile(argv[1]);

    time_t begin = time(NULL);

    

    time_t end = time(NULL);
    double ellapsed_time = difftime(end, begin);

    return 0;
}