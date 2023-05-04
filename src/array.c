#include "./array.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool	is_sorted(Array *array)
{
	if (array->size == 1)
		return (true);
	for (unsigned int i = 0; i < array->size - 1; i++)
	{
		if (array->data[i] > array->data[i + 1])
		{
			return (false);
		}
	}
	return (true);
}

void	find_min_and_max(Array *array)
{
	array->min = array->data[0];
	array->max = array->data[0];
	for (unsigned int i = 1; i < array->size; i++)
	{
		if (array->data[i] < array->min)
			array->min = array->data[i];
		if (array->data[i] > array->max)
			array->max = array->data[i];
	}
}

void	print_array(Array *array)
{
	for (unsigned int i = 0; i < array->size; i++)
	{
		printf("%d ", array->data[i]);
	}
	printf("%s", "\n");
	printf("min = %d, max = %d, size = %d\n", array->min, array->max,
			array->size);
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
