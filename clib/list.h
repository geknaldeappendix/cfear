#ifndef __REPOS_CFEAR_CLIB_LIST_H_
#define __REPOS_CFEAR_CLIB_LIST_H_

#include <stdlib.h>

struct List {
    void** items;

    int item_count, current_max_size, growable;
};

void list_create(struct List* list, int size, int growable);
int list_add_item(struct List* list, void* item);
void list_free(struct List* list);

#endif // __REPOS_CFEAR_CLIB_LIST_H_