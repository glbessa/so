// Compile command: gcc -Wall -lpthread -o hello_pthread hello_pthread.c

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>

void * hello_from(void *arg) {
    printf("Hello from thread %u of process %d (for os it is %ld)\n", (unsigned int) pthread_self(), getpid(), syscall(__NR_getpid));
    fflush(stdout);
}

int main(int argc, char **argv) {
    pthread_t thread;
    pthread_create(&thread, NULL, hello_from, NULL);

    sleep(3);

    pthread_exit(NULL);

    return 0;
}