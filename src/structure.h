#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_

#include <stdlib.h>
#include <time.h> 
#include <darray.h>
#include <dbg.h>

#define NOSTATUS 0
#define NOID 0

typedef struct ctodo_item {
	size_t id;
	size_t status;
	struct tm *creation_date;

	char *name;
	char *short_summary;
	char *long_summary;

	darray *items;
} ctodo_item;

ctodo_item *ctodo_item_create(size_t id, size_t status, 
	struct tm *creation_date, char *name, char *short_summary, 
	char *long_summary, darray *items);
void ctodo_item_clear(ctodo_item *item);
void ctodo_item_destroy(ctodo_item *item);
size_t ctodo_item_get_id(ctodo_item *item);
size_t ctodo_item_get_status(ctodo_item *item);
struct tm *ctodo_item_get_creation_date(ctodo_item *item);
char *ctodo_item_get_name(ctodo_item *item);
char *ctodo_item_get_short_summary(ctodo_item *item);
char *ctodo_item_get_long_summary(ctodo_item *item);
darray *ctodo_item_get_items(ctodo_item *item);

#endif /* _STRUCTURE_H_ */
