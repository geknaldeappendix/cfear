#include "named_list.h"

int named_list_is_full(struct NamedList* list) {
    return list->item_count == list->current_max_size;
}

void named_list_grow(struct NamedList* list, int size) {
    struct NamedList new_list;
    named_list_create(&new_list, size, list->growable);

    for (int i = 0; i < list->current_max_size; i++) {
        named_list_add_item(&new_list, list->items[i], list->names[i]);
    }

    list->names = new_list.names;
    list->items = new_list.items;
    list->item_count = new_list.item_count;
    list->current_max_size = new_list.current_max_size;
    list->growable = new_list.growable;
}

void named_list_remove_at_index(struct NamedList* list, int index) {
    free(list->names[index]);
    // free(list->items[index]); //TODO: neccecery?

    for (int i = index; i < list->item_count - 1; i++) {
        list->names[i] = list->names[i+1];
        list->items[i] = list->items[i+1];
    }

    list->item_count--;
}

void named_list_remove_all(struct NamedList* list) {
    for (int i = list->item_count-1; i >= 0; i--) {
        named_list_remove_at_index(list, i);
    }
}

void named_list_create(struct NamedList* list, int size, int growable) {
    list->names = (char**)malloc(sizeof(char*) * size);
    list->items = (void**)malloc(sizeof(void*) * size);
    list->item_count = 0;
    list->current_max_size = size;
    list->growable = growable;
}   

int named_list_add_item(struct NamedList* list, void* item, char* name) {
    if (named_list_is_full(list)) {
        if (!list->growable) {
            return -1;
        }

        named_list_grow(list, list->current_max_size*2);
    }

    list->names[list->item_count] = name;
    list->items[list->item_count] = item;
    return list->item_count++; //TODO: check, maybe first ++ and return -1
}

void named_list_free(struct NamedList* list) {
    named_list_remove_all(list);
    free(list->names);
    free(list->items);
}
