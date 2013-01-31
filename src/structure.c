#include <structure.h>

ctodo_item *ctodo_item_create(size_t id, size_t status, 
	struct tm *creation_date, char *name, char *short_summary, 
	char *long_summary, darray *items)
{
	check(name != NULL, 
		"ctodo_item_create: Item should have a name.");
	check(short_summary != NULL,
		"ctodo_item_create: Item should have a short summary.");

	ctodo_item *new_item = (ctodo_item *)malloc(sizeof(ctodo_item));
	check_memory(new_item);

	new_item->id = id;
	new_item->status = status;
	new_item->creation_date = creation_date;
	new_item->name = name;
	new_item->short_summary = short_summary;
	new_item->long_summary = long_summary;
	new_item->items = items;
	
	return new_item;
error:
	return NULL;
}

void ctodo_item_clear(ctodo_item *item)
{
	check(item != NULL,
		"ctodo_item_clear: Item should not be NULL.");

	if (item->creation_date)
		free(item->creation_date);
	if (item->name)
		free(item->name);
	if (item->short_summary)
		free(item->short_summary);
	if (item->long_summary)
		free(item->long_summary);

	ctodo_item_destroy(item);
error:
	return;
}

void ctodo_item_destroy(ctodo_item *item)
{
	debug("ctodo_item_destroy: Freeing item.");

	if (item)
		free(item);

	debug("ctodo_item_destroy: Item freed.");
}

size_t ctodo_item_get_id(ctodo_item *item)
{
	check(item != NULL,
		"ctodo_item_get_id: Item should not be NULL.");

	return item->id;
error:
	return NOID;
}

size_t ctodo_item_get_status(ctodo_item *item)
{
	check(item != NULL,
		"ctodo_item_get_status: Item should not be NULL.");
	
	return item->status;
error:
	return NOSTATUS;
}

struct tm *ctodo_item_get_creation_date(ctodo_item *item)
{
	check(item != NULL,
		"ctodo_item_get_creation_date: Item should not be NULL.");

	return item->creation_date;
error:
	return NULL;
}

char *ctodo_item_get_name(ctodo_item *item)
{
	check(item != NULL,
		"ctodo_item_get_name: Item should not be NULL.");

	return item->name;
error:
	return NULL;
}

char *ctodo_item_get_short_summary(ctodo_item *item)
{
	check(item != NULL,
		"ctodo_item_get_short_summary: Item should not be NULL.");
	
	return item->short_summary;
error:
	return NULL;
}

char *ctodo_item_get_long_summary(ctodo_item *item)
{
	check(item != NULL,
		"ctodo_item_get_long_summary: Item should not be NULL.");

	return item->long_summary;
error:
	return NULL;
}

darray *ctodo_item_get_items(ctodo_item *item)
{
	check(item != NULL,
		"ctodo_item_get_items: Item should not be NULL.");

	return item->items;
error:
	return NULL;
}
