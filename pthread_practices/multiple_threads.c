// Compile command: gcc -Wall -lpthread -o multiple_threads multiple_threads.c

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>

#define NUM_THREADS 4

void * hello_from(void *arg) {
    printf("Hello from thread %u of process %d (for os it is %ld)\n", (unsigned int) pthread_self(), getpid(), syscall(__NR_getpid));
    fflush(stdout);
}

int main(int argc, char **argv) {
    pthread_t threads[NUM_THREADS];

    printf("Creating %d threads\n", NUM_THREADS);
    
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, hello_from, NULL);
    }

    printf("All threads created\n");
    printf("Wainting for threads\n");

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Everything done\n");

    return 0;
}