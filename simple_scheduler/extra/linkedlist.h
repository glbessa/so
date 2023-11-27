#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define DESTROY_ITEMS 1
#define NO_DESTROY_ITEMS 0

typedef struct LinkedList LinkedList;
struct LinkedList {
    void * item;
    LinkedList *next;
};

LinkedList * linkedlist_create(void *item);
void linkedlist_destroy(LinkedList *list, int destroy_items_flag);
void linkedlist_clear(LinkedList **list);
void * linkedlist_get(LinkedList **list, int index);
void * linkedlist_pop(LinkedList **list);
void * linkedlist_popfront(LinkedList **list);
void linkedlist_append(LinkedList **list, void *item);
void linkedlist_insert(LinkedList **list, int index, void *item);
int linkedlist_length(LinkedList **list);

#endif