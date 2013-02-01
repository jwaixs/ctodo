/*
 * dllist.c
 *
 * Double linked list source file.
 *
 */

#include <dllist.h>
#include <dbg.h>

dllist *dllist_create()
{
	dllist *new_list = (dllist *)malloc(sizeof(dllist));
	check_memory(new_list);	

	new_list->length = 0;
	new_list->first = NULL;
	new_list->last = NULL;

	return new_list;
error:
	return NULL;
}

void dllist_destroy(dllist *list)
{
	check(list != NULL, "dllist_destroy: list should not be NULL.");

	dllist_foreach (list, cur)
		if (cur->prev)
			free(cur->prev);

	free(list->last);
	free(list);
error:
	return;
}

void dllist_clear(dllist *list)
{
	check(list != NULL, "dllist_clear: list should not be NULL.");

	dllist_foreach (list, cur)
		free(cur->value);
error:
	return;
}

void *dllist_remove(dllist *list, dllist_node *node)
{
	void *result = NULL;
	
	check(list != NULL, "dllist_remove: list should not be NULL.");
	check(list->first != NULL && list->last != NULL,
		"dllist_remove: list cannot be empty.");
	check(node != NULL, "dllist_remove: node should not be NULL.");

	if (node == list->first && node == list->last) {
		list->first = NULL;
		list->last = NULL;
	} else if (node == list->first) {
		list->first = node->next;
		list->first->prev = NULL;
	} else if (node == list->last) {
		list->last = list->last->prev;
		list->last->next = NULL;
	} else {
		dllist_node *after = node->next;
		dllist_node *before = node->prev;
		after->prev = before;
		before->next = after;
	}

	list->length--;
	result = node->value;
	return result;
error:
	return result;
}

void dllist_push(dllist *list, void *value)
{
	check(list != NULL, "dllist_push: list should not be NULL.");

	dllist_node *node = (dllist_node *)malloc(sizeof(dllist_node));
	check_memory(node);

	node->value = value;

	if (list->last == NULL) {
		list->first = node;
		list->last = node;
	} else {
		list->last->next = node;
		node->prev = list->last;
		list->last = node;
	}

	list->length++;
	return;
error:
	if (node)
		free(node);
	return;
}

void *dllist_pop(dllist *list)
{
	check(list != NULL, "dllist_pop: list should not be NULL.");

	dllist_node *node = list->last;
	return node != NULL ? dllist_remove(list, node) : NULL;
error:
	return NULL;
}

void *dllist_get_first(dllist *list)
{
	check(list != NULL, "dllist_get_first: list should not be NULL.");

	return list->first;
error:
	return NULL;
}

void *dllist_get_last(dllist *list)
{
	check(list != NULL, "dllist_get_last: list should not be NULL.");

	return list->last;
error:
	return NULL;
}

size_t dllist_get_length(dllist *list)
{
	check(list != NULL, "dllist_get_length: list should not be NULL.");

	return list->length;
error:
	return 0;
}
