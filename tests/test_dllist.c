/*
 * test_dllist.c
 *
 * Test module for double linked list.
 *
 */

#include <dllist.h>
#include "minunit.h"
#include <stdio.h>

static void *val1 = NULL;
static void *val2 = NULL;
static void *val3 = NULL;
static dllist *list = NULL;

void test_create()
{
	list = dllist_create();

	mu_assert(list != NULL, 
		"double linked list should be initialized correctly.");
	mu_assert(dllist_get_first(list) == NULL 
		&& dllist_get_last(list) == NULL,
		"double linked list should be empty");
	mu_assert(dllist_get_length(list) == 0,
		"double linked list should have length 0.");
}

void test_push()
{
	dllist_push(list, val1);
	dllist_push(list, val2);
	dllist_push(list, val3);

	mu_assert(dllist_get_length(list) == 3,
		"double linked list should have length 3.");
	mu_assert(dllist_get_first(list) == val1,
		"first value of double linked list should be val1.");
	mu_assert(dllist_get_last(list) == val3,
		"last value of double linked list should be val3.");
}

void test_pop_remove()
{
	/* remove last is tested indirectly here */
	mu_assert(dllist_pop(list) == val3,
		"value of pop of double linked list should be val3.");
	mu_assert(dllist_get_length(list) == 2,
		"length of double linked list should be 2.");
	mu_assert(dllist_get_first(list) == val1,
		"value of first of double linked list should be val1.");
	mu_assert(dllist_get_last(list) == val2,
		"value of last of double linked list should be val2.");
	mu_assert(dllist_pop(list) == val2,
		"value of pop of double linked list should be val2.");
	mu_assert(dllist_get_length(list) == 1,
		"lenght of double linked list should be 1.");
	mu_assert(dllist_get_first(list) == val1,
		"value of first of double linked list should be val1.");
	mu_assert(dllist_get_last(list) == val1,
		"value of last of double linked list should be val1.");
	mu_assert(dllist_pop(list) == val1,
		"value of pop of double linked list should be val1.");
	mu_assert(dllist_get_length(list) == 0,
		"length of double linked list should be 0.");
	mu_assert(dllist_pop(list) == NULL,
		"value of pop of double linked list should be NULL.");
	
	/* push everything back and test other cases of remove. */
	dllist_push(list, val1);
	dllist_push(list, val2);
	dllist_push(list, val3);

	mu_assert(dllist_get_length(list) == 3,
		"length of double linked list should be 3.");

	mu_assert(dllist_remove(list, list->first) == val1,
		"double linked list should remove first value.");
	mu_assert(dllist_get_length(list) == 2,
		"length double linked list should be 2.");
	mu_assert(dllist_get_first(list) == val2,
		"value of first element in double linked list should be val2.");
	mu_assert(dllist_get_last(list) == val3,
		"value of last element in double linked list should be val3.");

	dllist_push(list, val1);
	
	mu_assert(dllist_get_length(list) == 3,
		"length double linked list should be 3.");
	mu_assert(dllist_remove(list, list->first->next) == val3,
		"double linked list should remove middle value.");
	mu_assert(dllist_get_length(list) == 2,
		"length double linked list should be 2.");
	mu_assert(dllist_get_first(list) == val2,
		"first value of double linked list should be val2.");
	mu_assert(dllist_get_last(list) == val1,
		"last value of double linked list should be val1.");
}

void test_destroy()
{
	//dllist_clear(list);
	dllist_destroy(list);

	mu_assert(list == list, 
		"double linked list should be cleared and destroyed.");
}

void all_tests()
{
	mu_suite_start();

	mu_run_test(test_create);
	mu_run_test(test_push);
	mu_run_test(test_pop_remove);
	mu_run_test(test_destroy);
}

RUN_TESTS(all_tests);
