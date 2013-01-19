#ifndef __darray_h_
#define __darray_h_

#include<stdlib.h>

typedef struct darray {
	size_t size;
	size_t expand_rate;
	size_t end;
	void **contents;
} darray;

darray *darray_create(size_t size, size_t expand_rate);
void darray_destroy(darray *array);
int darray_resize(darray *array, size_t newsize);
int darray_expand(darray *array);
int darray_contract(darray *array);
int darray_set(darray *array, size_t i, void *elm);
void *darray_get(darray *array, size_t i);
void *darray_remove(darray *array, size_t i);
size_t darray_get_size(darray *array);
size_t darray_get_expand_rate(darray *array);
size_t darray_get_end(darray *array);
int darray_push(darray *array, void *elm);
void *darray_pop(darray *array);

#endif /* __darray_h_ */
