#ifndef __REPOS_CFEAR_CLIB_NAMED_LIST_H_
#define __REPOS_CFEAR_CLIB_NAMED_LIST_H_

#include <stdlib.h>

struct NamedList {
    void** items;
    char** names;

    int item_count, current_max_size, growable;
}; 

void named_list_create(struct NamedList* list, int size, int growable);
int named_list_add_item(struct NamedList* list, void* item, char* name);
void named_list_free(struct NamedList* list);

#endif // __REPOS_CFEAR_CLIB_NAMED_LIST_H_