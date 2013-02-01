/* 
 * src/dllist.h
 * 
 * Double linked list header file 
 *
 * Author: Noud Aldenhoven
 */

#ifndef _DLLIST_H_
#define _DLLIST_H_

#include <stdlib.h>

typedef struct dllist_node {
	struct dllist_node *next;
	struct dllist_node *prev;
	void *value;
} dllist_node;

typedef struct dllist {
	size_t length;
	dllist_node *first;
	dllist_node *last;
} dllist;

dllist *dllist_create();
void dllist_destroy(dllist *list);
void dllist_clear(dllist *list);
void *dllist_remove(dllist *list, dllist_node *node);
void dllist_push(dllist *list, void *value);
void *dllist_pop(dllist *list);
void *dllist_get_first(dllist *list);
void *dllist_get_last(dllist *list);
size_t dllist_get_length(dllist *list);

#define dllist_foreach(L, C)						   \
	dllist_node *_node = NULL;					   \
	dllist_node *C = NULL;						   \
	for (C = _node = L->first; _node != NULL; C = _node = _node->next) \

#endif /* _DLLIST_H_ */
