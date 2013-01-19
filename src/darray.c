#include <assert.h>
#include "darray.h"
#include "dbg.h"

darray *darray_create(size_t size, size_t expand_rate)
{
	check(size >= 0, "Size should be non-negative but is value: %lu", 
		size);
	check(expand_rate > 0, 
		"Expand rate should be positive but is value %lu", expand_rate);

	darray *array = malloc(sizeof(darray));
	check_memory(array);

	array->contents = calloc(size, sizeof(void *));
	check_memory(array);

	array->end = 0;
	array->expand_rate = expand_rate;
	array->size = size;

	return array;
error:
	if (array)
		free(array);
	return NULL;
}

void darray_destroy(darray *array)
{
	int i;

	for (i = 0; i < array->size; i++)
		if (array->contents[i])
			free(array->contents[i]);

	free(array);
}

int darray_resize(darray *array, size_t newsize)
{
	check(array, "Array is not well-defined.");
	check(newsize >= 0, "Newsize should be non-negative, but has value %lu",
		newsize);
	
	void *contents = realloc(array->contents, newsize * sizeof(void *));
	check_memory(contents);

	array->size = newsize;
	array->contents = contents;

	return 0;
error:
	return -1;
}

int darray_expand(darray *array)
{
	check(array, "Array is not well-defined.");
	
	int ret = darray_resize(array, 
		darray_get_size(array) + darray_get_expand_rate(array));
	check(ret == 0, "Failed to expand array to new size.");

	return 0;
error:
	return -1;
}

int darray_contract(darray *array)
{
	check(array, "Array is not well-defined.");
	
	int contraction_size = 
		darray_get_size(array) - darray_get_expand_rate(array);
	check(contraction_size > darray_get_end(array), 
		"Cannot contract array because the array is too full");
	int ret = darray_resize(array, contraction_size);
	check(ret == 0, "Could not retract array.");

	return 0;
error:
	return -1;
}

int darray_set(darray *array, size_t i, void *elm)
{
	check(array, "Array is not well-defined.");
	check(0 <= i && i <= darray_get_end(array), 
		"Darray list index (%lu) is out of range [0:%lu]", 
		i, darray_get_end(array));

	array->contents[i] = elm;
	array->end = i > array->end ? i : array->end;

	return 0;
error:
	return -1;
}

void *darray_get(darray *array, size_t i)
{
	check(array, "Array is not well-defined.");
	check(i <= darray_get_end(array), 
		"Darray list index (%lu) is out of range [0:%lu]", 
		i, darray_get_end(array));

	return array->contents[i];
error:
	return NULL;
}

void *darray_remove(darray *array, size_t i)
{
	check(array, "Darray is not well-defined.");
	check(0 <= i && i <= array->end, 
		"Darray list index (%lu) is out of range [0:%lu]", i, array->end)
	
	void *elm = array->contents[i];
	array->contents[i] == NULL;

	if (i == array->end - 1)
		array->end--;

	return elm;
error:
	return NULL;
}

size_t darray_get_size(darray *array)
{
	check(array, "Darray is not well-defined.");

	return array->size;
error:
	return 0;
}

size_t darray_get_expand_rate(darray *array)
{
	check(array, "Darray is not well-defined.");

	return array->expand_rate;
error:
	return 0;
}

size_t darray_get_end(darray *array)
{
	check(array, "Darray is not well-defined.");

	return array->end;
error:
	return 0;
}

int darray_push(darray *array, void *elm)
{
	check(array, "Darray is not well-defined.");
	
	int ret;
	if (darray_get_size(array) == darray_get_end(array))
		ret = darray_expand(array);
	check(ret == 0, "Cannot push element on array.");

	array->contents[array->end] = elm;
	array->end++;

	return 0;
error:
	return -1;
}

void *darray_pop(darray *array)
{
	check(darray_get_end(array) > 0, "Cannot pop an empty list.");

	void *elm = darray_remove(array, array->end - 1);
	array->end--;

	if (darray_get_end(array) > darray_get_expand_rate(array)
		&& darray_get_end(array) % darray_get_expand_rate(array)) 
		darray_contract(array);

	return elm;
error:
	return NULL;
}
