#ifndef POLICIES_H
#define POLICIES_H

#include "task.h"
#include "utils.h"

int shortest_job_first(const void *t1, const void *t2);
int shortest_job_last(const void *t1, const void *t2);

#endif