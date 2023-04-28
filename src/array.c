#include "./array.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool	is_sorted(Array *array)
{
	for (unsigned int i = 0; i < array->size - 1; i++)
	{
		if (array->data[i] > array->data[i + 1])
		{
			return (false);
		}
	}
	return (true);
}

void	print_array(Array *array)
{
	for (unsigned int i = 0; i < array->size; i++)
	{
		printf("%d ", array->data[i]);
	}
	printf("%s", "\n\n");
}

Array	*random_array(unsigned int size)
{
	Array	*array;

	array = (Array *)malloc(sizeof(Array));
	array->size = size;
	array->data = (int *)malloc(size * sizeof(int));
	if (array->data == NULL)
	{
		fprintf(stderr, "Error: memory allocation failed.\n");
		exit(1);
	}
	srand(time(NULL));
	for (unsigned int i = 0; i < size; i++)
	{
		array->data[i] = rand();
	}
	return (array);
}

void	destroy_array(Array *array)
{
	free(array->data);
	free(array);
}
