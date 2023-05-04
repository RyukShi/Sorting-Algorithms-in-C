#ifndef ARRAY_H
#define ARRAY_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _Array	Array;

struct					_Array
{
	unsigned int		size;
	int					*data;
	int min, max;
};

extern bool				is_sorted(Array *array);
extern void				find_min_and_max(Array *array);
extern void				print_array(Array *array);
extern Array			*random_array(unsigned int size);
extern void				destroy_array(Array *array);

#endif /* ARRAY_H */
