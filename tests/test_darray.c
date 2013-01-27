#include <stdio.h>
#include "darray.h"
#include "minunit.h"

static darray *array = NULL;
static int *val1 = NULL;
static int *val2 = NULL;
static int *val3 = NULL;

void test_create() 
{
	array = darray_create(2, 5);
	mu_assert(array != NULL, "Darray should be created");
	mu_assert(array->contents != NULL, 
		"Darray content should not be NULL.");
	mu_assert(array->end == 0, "Darray end should be 0.");
	mu_assert(array->size == 2, "Darray size should be 2.");
	mu_assert(array->expand_rate == 5, "Darray expand_rate should be 5.");
}

void test_destroy()
{
	darray_destroy(array);
}

void test_resize()
{
	mu_assert(darray_resize((darray *)NULL, 10) == -1, 
		"Darray should fail when darray is not well-defined.");
	mu_assert(darray_resize(array, 10) == 0,
		"Darray should resize (expand) without errors.");
	mu_assert(darray_get_size(array) == 10,
		"Darray should have size 10.");
	mu_assert(darray_resize(array, 5) == 0,
		"Darray should resize (contract) without errors.");
	mu_assert(darray_get_size(array) == 5,
		"Darray should have size 5.");
}

void test_expand()
{
	mu_assert(darray_expand(array) == 0,
		"Darray should expand without errors.");
	mu_assert(darray_get_size(array) == 5 + darray_get_expand_rate(array),
		"Darray should have the correct expand size.");
}

void test_contract()
{
	mu_assert(darray_contract(array) == 0,
		"Darray should contract without errors.");
	mu_assert(darray_get_size(array) == 5,
		"Darray should have the correct contract size.");
}

void test_set_get()
{
	mu_assert(darray_set(array, 0, val1) == 0,
		"Darray should set an element without errors.");
	mu_assert(darray_set(array, 1, val2) == 0,
		"Darray should set an element without errors.");
	mu_assert(darray_get_end(array) == 1,
		"Darray should have correct end.");
	mu_assert(darray_get(array, 0) == val1,
		"Darray should get the correct element.");
	mu_assert(darray_get(array, 1) == val2,
		"Darray should get the correct element.");
}

void test_push_pop()
{
	mu_assert(darray_push(array, val3) == 0,
		"Darray should push without errors.");
	mu_assert(darray_get_end(array) == 2,
		"Darray should have correct size after push.");
	mu_assert(darray_get(array, 2) == val3,
		"Darray should have pushed the correct element.");
	mu_assert(darray_pop(array) == val3,
		"Darray should pop the correct element.");
	mu_assert(darray_get_end(array) == 1,
		"Darray should have correct size after pop.");
}

void test_remove()
{
	mu_assert(darray_remove(array, 0) == val1,
		"Darray should remove without failure.");
	mu_assert(darray_get_end(array) == 1,
		"Darray should have the correct end value.");
	mu_assert(darray_remove(array, 1) == val2,
		"Darray should remove without failure.");
	mu_assert(darray_get_end(array) == 0,
		"Darray must be empty.");
}


void all_tests() 
{
	mu_suite_start();

	mu_run_test(test_create);
	mu_run_test(test_resize);
	mu_run_test(test_expand);
	mu_run_test(test_contract);
	mu_run_test(test_set_get);
	mu_run_test(test_push_pop);
	mu_run_test(test_remove);
	mu_run_test(test_destroy);
}

RUN_TESTS(all_tests);

