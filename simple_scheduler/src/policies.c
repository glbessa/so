#include "policies.h"

int shortest_job_first(const void *t1, const void *t2) {
    Task *task1 = (Task *) *((const void **) t1);
    Task *task2 = (Task *) *((const void **) t2);

    if (task1->time_left < task2->time_left)
        return -1;
    if (task1->time_left > task2->time_left)
        return 1;
    
    return 0;
}

int shortest_job_last(const void *t1, const void *t2) {
    Task *task1 = (Task *) *((const void **) t1);
    Task *task2 = (Task *) *((const void **) t2);

    if (task1->time_left > task2->time_left)
        return -1;
    if (task1->time_left < task2->time_left)
        return 1;
    
    return 0;
}