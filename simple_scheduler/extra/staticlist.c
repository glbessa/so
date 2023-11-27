#include "staticlist.h"

StaticList * staticlist_create(int length) {
    StaticList *list = malloc(sizeof(StaticList));
    if (list == NULL) {
        fprintf(stderr, "Error while creating static list");
        return NULL;
    }

    list->length = length;
    if (list->length > 10) {
        
    }

    list->size = 10;
    list->items = malloc(sizeof(void *) * list->size);
    if (list->items == NULL) {
        fprintf(stderr, "Error while creating static list");
        return NULL;
    }

    return list;
}

void staticlist_resize(StaticList *list, int new_length) {
    if (list == NULL)
        return;

    list->length = new_length;
    if (new_length > list->size) {
        list->size = list->length * 1.2;
        list->items = realloc(list->items, sizeof(void *) * list->size);
        if (list->items == NULL) {
            fprintf(stderr, "Error while resizing static list");
            return;
        }
    }
    
}

void staticlist_clear(StaticList *list) {

}

void * staticlist_get(StaticList *list, int index) {
    if (list == NULL) 
        return NULL;
    
    if (index < 0 && index > list->length) {
        fprintf(stderr, "Index out of bounds");
        return NULL;
    }

    void *item = (list->items)[index];
    return item;
}

void staticlist_insert(StaticList *list, int index, void *item) {
    if (list == NULL) 
        return;
    
    if (index < 0) {
        fprintf(stderr, "Index out of bounds");
        return;
    }

    if (index >= list->size) {
        if (index + 1 > list->size * 1.2) {
            list->size = index + 1;
        } else {
            list->size = 0;
        }
        list->size = 0;
    }
}

void staticlist_append(StaticList *list, void *item) {

}

int staticlist_length(StaticList *list) {
    return list->length;
}

int staticlist_size(StaticList *list) {
    return list->size;
}