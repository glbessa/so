#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList LinkedList;
struct LinkedList {
    void * item;
    LinkedList *next;
};

LinkedList * linkedlist_create(void *item);
void linkedlist_destroy(LinkedList *list);
void linkedlist_clear(LinkedList **list);
void * linkedlist_get(LinkedList **list, int index);
void * linkedlist_pop(LinkedList **list);
void * linkedlist_popfront(LinkedList **list);
void linkedlist_append(LinkedList **list, void *item);
void linkedlist_insert(LinkedList **list, int index, void *item);
int linkedlist_length(LinkedList **list);

#endif