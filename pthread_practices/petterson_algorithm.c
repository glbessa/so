// Compile command:
//   gcc -Wall -lpthread -o petterson_algorithm petterson_algorithm.c

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>

#define NUM_THREADS 2

void * silly_function(void * args);
int is_alone(const int id);

int interested[NUM_THREADS];
int turn;

void * silly_function(void * args) {
    int *id = (int *) args;
    interested[*id] = 1;

    while (is_alone(*id) && turn != *id);

    printf("Hello from thread %i of process %d (for os it is %ld)\n", *id, getpid(), syscall(__NR_getpid));

    interested[*id] = 0;
    free(id);
}

int is_alone(const int id) {
    for (int i = 0; i < NUM_THREADS; i++) {
        if (i != id && i == 1)
            return 0;
    }

    return 1;
}

int main(int argc, char **argv) {
    turn = -1;

    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        int *id = malloc(sizeof(int));
        *id = i;
        pthread_create(&threads[i], NULL, silly_function, id);
    }

    turn = 3;

    sleep(2);

    turn = 1;

    sleep(2);

    turn = 2;

    sleep(2);

    turn = 0;

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }   

    return 0;
}