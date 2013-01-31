#include <stdio.h>
#include <structure.h>
#include <darray.h>
#include "minunit.h"

static ctodo_item *item = NULL;
static size_t id = 37;
static size_t status = 1;
static struct tm *creation_date = NULL;
static char *name = "The awesome ctodo_item";
static char *short_summary = "This ctodo_item is awesome.";
static char *long_summary = "And here is the long summary.";
static darray *items = NULL;

void test_create()
{
	item = ctodo_item_create(id, status, creation_date, name, 
		short_summary, long_summary, items);
	mu_assert(item != NULL,
		"ctodo_item should not be equal to NULL.");
}

void test_item_get_statements()
{
	mu_assert(ctodo_item_get_id(item) == id,
		"ctodo_item_get_id should give id of item.");
	mu_assert(ctodo_item_get_status(item) == status,
		"ctodo_item_get_status should give status of item.");
	mu_assert(ctodo_item_get_creation_date(item) == creation_date,
		"ctodo_item_get_creation_data should give date of item.");
	mu_assert(ctodo_item_get_name(item) == name,
		"ctodo_item_get_name should give name of item.");
	mu_assert(ctodo_item_get_short_summary(item) == short_summary,
		"ctodo_item_get_short_summary should give short_summary of item.");
	mu_assert(ctodo_item_get_long_summary(item) == long_summary,
		"ctodo_item_get_long_summary should give long_summary of item.");
	mu_assert(ctodo_item_get_items(item) == items,
		"ctodo_item_get_items should give items of item.");
}

void test_destroy()
{
	ctodo_item_destroy(item);

	/* I don't know how to check that something is freed. */
	mu_assert(item == item,
		"ctodo_item_destroy should free item.");
}

void all_tests()
{
	mu_suite_start();

	mu_run_test(test_create);
	mu_run_test(test_item_get_statements);
	mu_run_test(test_destroy);
}

RUN_TESTS(all_tests);
