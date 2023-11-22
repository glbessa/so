#include "linkedlist.h"

LinkedList * linkedlist_create(void *item) {
    LinkedList *node = (LinkedList *) malloc(sizeof(LinkedList));
    if (node == NULL) {
        fprintf(stderr, "Error while creating linkedlist node");
        return NULL;
    }

    node->item = item;
    return node;
}

void linkedlist_destroy(LinkedList *list) {
    if (list == NULL) {
        return;
    }
    
    free(list);
}

void linkedlist_clear(LinkedList **list) {

}

void * linkedlist_get(LinkedList **list, int index) {
    if (list == NULL || *list == NULL) {
        return NULL;
    }

    LinkedList *head = *list;
    for (int i = 0; i < index; i++) {
        if (head->next == NULL) {
            return head->item;
        }

        head = head->next;
    }

    return head->item;
}

void * linkedlist_pop(LinkedList **list) {
    if (list == NULL || *list == NULL) {
        return NULL;
    }

    LinkedList *prev = *list;
    if (prev->next == NULL) {
        *list = NULL;
        return prev;
    }

    while (prev->next->next != NULL) {
        prev = prev->next;
    }

    LinkedList *actual = prev->next;
    prev->next = NULL;

    void *item = actual->item;
    linkedlist_destroy(actual);

    return item;
}

void * linkedlist_popfront(LinkedList **list) {
    if (list == NULL || *list == NULL) {
        return NULL;
    }

    LinkedList *actual = *list;
    *list = (*list)->next;

    return actual;
}

void linkedlist_append(LinkedList **list, void *item) {
    if (list == NULL) {
        return;
    }

    LinkedList *new_node = linkedlist_create(item);
    if (*list == NULL) {
        *list = new_node;
        return;
    }

    LinkedList *prev = *list;
    while (prev->next != NULL) {
        prev = prev->next;
    }

    prev->next = new_node;
}

void linkedlist_insert(LinkedList **list, int index, void *item) {
    if (list == NULL) {
        return;
    }

    LinkedList *new_node = linkedlist_create(item);
    if (*list == NULL || index == 0) {
        LinkedList *temp = *list;
        *list = new_node;
        new_node->next = temp;
        return;
    }
    if ((*list)->next == NULL) {
        (*list)->next = new_node;
        return;
    }

    LinkedList *actual = *list;
    for (int i = 0; i < index || actual->next->next == NULL; i++) {
        actual = actual->next;
    }

    LinkedList *temp = actual->next;
    actual->next = new_node;
    new_node->next = temp;
}

int linkedlist_length(LinkedList **list) {
    if (list == NULL || *list == NULL) {
        return 0;
    }

    int counter = 1;
    LinkedList *actual = *list;
    while (actual->next != NULL) {
        counter += 1;
        actual = actual->next;
    }

    return counter;
}