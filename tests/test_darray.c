#include <stdio.h>
#include "darray.h"
#include "minunit.h"

static darray *array = NULL;
static int *val1 = NULL;
static int *val2 = NULL;

static char *test_create() 
{
	printf("Testing the darray_create function.\n");

	array = darray_create(2, 5);
	mu_assert(array != NULL, "Darray should be created");
	mu_assert(array->contents != NULL, 
		"Darray content should not be NULL.");
	mu_assert(array->end == 0, "Darray end should be 0.");
	mu_assert(array->size == 2, "Darray size should be 2.");
	mu_assert(array->expand_rate == 5, "Darray expand_rate should be 5.");

	return NULL;
}

static char *test_destroy()
{
	printf("Testing the darray_destroy function.\n");

	darray_destroy(array);

	return NULL;
}

static char *test_resize()
{
	printf("Testing the darray_resize function.\n");

	//mu_assert(darray_resize((darray *)NULL, 10) == -1, 
	//	"Darray should fail when darray is not well-defined.");

	return NULL;
}

static char *all_tests() 
{
	mu_suite_start();

	mu_run_test(test_create);
	mu_run_test(test_resize);
	mu_run_test(test_destroy);

	return NULL;
}

RUN_TESTS(all_tests);

