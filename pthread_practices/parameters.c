// Compile command: gcc -Wall -lpthread -o parameters parameters.c

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>

#define NUM_THREADS 4

typedef struct Args Args;
struct Args {
    int a;
    int b;
};

void * sum(void * raw_args) {
    Args *args = (Args *) raw_args;
    int *result = malloc(sizeof(int));
    *result = args->a + args->b;
    return (void *) result;
}

int main(int argc, char **argv) {
    pthread_t thread;

    Args args;
    args.a = 10;
    args.b = 20;
    int *result;

    pthread_create(&thread, NULL, sum, &args);

    pthread_join(thread, (void **) &result);

    printf("Result of %d + %d = %d\n", args.a, args.b, *result);

    if (result != NULL)
        free(result);

    return 0;
}