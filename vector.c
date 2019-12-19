#include "vector.h"

void
setVector	(struct vector_t *vec,
			 size_t capacity)
{
	vec->capacity = capacity;
	vec->size = 0;
	int *newMem = calloc(capacity, sizeof(int));
	assert(newMem != NULL);
	vec->data = newMem;
}

void
freeVector	(struct vector_t *vec)
{
	free(vec->data);
}

void
push_back	(struct vector_t *vec,
			int element)
{
	if(vec->capacity == 0){
		vec->capacity = 1;
		int* newMem = realloc(vec->data, vec->capacity*sizeof(int));
		assert(newMem != NULL);
		vec->data = newMem;
	}
	if(vec->size == vec->capacity){
		vec->capacity = vec->capacity*2;
		int* newMem = realloc(vec->data, vec->capacity*sizeof(int));
		assert(newMem != NULL);
		vec->data = newMem;
	}

	*(vec->data + vec->size) = element;
	vec->size++;
}

int
pop	(struct vector_t *vec)
{
	int val = *(vec->data + vec->size - 1);
	if(vec->size == 0) {
		fprintf(stderr, "VECTOR POP ERROR");
		return 0;
	}
	if(vec->size == 1) {
		int val = vec->data[0];
		free(vec->data);
		vec->capacity = 0;
		vec->size = 0;
		return val;
	}
	if(--(vec->size) <= vec->capacity/2) {
		vec->capacity = vec->capacity/2;
		int* newMem = realloc(vec->data, vec->capacity*sizeof(int));
		assert(newMem != NULL);
		vec->data = newMem;
	}
	return *(vec->data + vec->size);
}

