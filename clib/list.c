#include "list.h"

int list_is_full(struct List* list) {
    return list->item_count == list->current_max_size;
}

void list_grow(struct List* list, int size) {
    struct List new_list;
    list_create(&new_list, size, list->growable);

    for (int i = 0; i < list->current_max_size; i++) {
        list_add_item(&new_list, list->items[i]);
    }

    list->items = new_list.items;
    list->item_count = new_list.item_count;
    list->current_max_size = new_list.current_max_size;
    list->growable = new_list.growable;
}

void list_remove_at_index(struct List* list, int index) {
    // free(list->items[index]); //TODO: neccecery?

    for (int i = index; i < list->item_count - 1; i++) {
        list->items[i] = list->items[i+1];
    }

    list->item_count--;
}

void list_remove_all(struct List* list) {
    for (int i = list->item_count-1; i >= 0; i--) {
        list_remove_at_index(list, i);
    }
}

void list_create(struct List* list, int size, int growable) {
    list->items = (void**)malloc(sizeof(void*) * size);
    list->item_count = 0;
    list->current_max_size = size;
    list->growable = growable;
}   

int ist_add_item(struct List* list, void* item) {
    if (list_is_full(list)) {
        if (!list->growable) {
            return -1;
        }

        list_grow(list, list->current_max_size*2);
    }

    list->items[list->item_count] = item;
    return list->item_count++; //TODO: check, maybe first ++ and return -1
}

void list_free(struct List* list) {
    list_remove_all(list);
    free(list->items);
}
