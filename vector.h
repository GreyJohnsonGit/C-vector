#include <string.h>
#include <stdlib.h>
#include <stdio.h>


#ifndef VECTOR_T
#define VECTOR_T

struct vector_t {
	int *data;
	size_t size;
	size_t capacity;
};

void	setVector		(struct vector_t *vec,
						 size_t capacity);

void	freeVector		(struct vector_t *vec);

void    push_back		(struct vector_t *vec,
						 int element);
int		pop				(struct vector_t *vec);
#endif //VECTOR_T