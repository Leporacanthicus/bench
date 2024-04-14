#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct dyn_array
{
    int *ptr;
    int *cap;
    int *end;
} dyn_array;

#define MIN_SIZE 8

void panic(const char* msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

void init(dyn_array *d)
{
    d->ptr = NULL;
    d->cap = NULL;
    d->end = NULL;
}

void destroy(dyn_array *d)
{
    free(d->ptr);
}

void grow(dyn_array *d)
{
    // If we're empty, start with MIN_SIZE;
    size_t size;
    if (!d->cap)
	size = MIN_SIZE;
    else
	size = (d->cap - d->ptr);
    int* new_ptr = malloc(2 * size * sizeof(int));
    if (!new_ptr)
	panic("Out of memory");
    // If we have anything, copy it. 
    if (d->cap) {
	memcpy(new_ptr, d->ptr, size * sizeof(int));
	free(d->ptr);
	d->ptr = new_ptr;
	d->cap = d->ptr + size * 2;
	d->end = d->ptr + size;
    }
    else
    {
	d->ptr = d->end = new_ptr;
	d->cap = d->ptr + size * 2;
    }
}

void push_back(dyn_array *d, int v)
{
    if (d->end == d->cap)
	grow(d);
    *d->end++ = v;
}

int* elem(dyn_array *d, int i)
{
    return &d->ptr[i];
}

#define N 300000000

int main(void)
{
    dyn_array d;
    init(&d);
    for(int i = 0; i < N; i++)
 	push_back(&d, i);
 
    uint64_t sum = 0;
    for (int i = 0; i < N; i++)
	sum += *elem(&d, i);

    printf("Sum is %ld\n", sum);

    destroy(&d);
    return 0;
}
