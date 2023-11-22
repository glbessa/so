#ifndef STATICLIST_H
#define STATICLIST_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct StaticList StaticList;
struct StaticList {
    void ** list;
    int size;
    int length;
};

void * staticlist_get(StaticList *list, int index);
void * staticlist_pop(StaticList *list, int index);
void * staticlist_poplast(StaticList *list);
void * staticlist_popfront(StaticList *list);
void staticlist_remove(StaticList *list, int index);
void staticlist_append(StaticList *list, void *item);
void staticlist_insert(StaticList *list, int index, void *item);
int staticlist_length(StaticList *list);
int staticlist_size(StaticList *list);

#endif