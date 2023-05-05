#include "./array.h"
#include <stdlib.h>

void	counting_sort(Array *array)
{
	int	range;
	int	*count;
	int	*output;

	range = array->max - array->min + 1;
	count = (int *)calloc(range, sizeof(int));
	output = (int *)malloc(array->size * sizeof(int));
	if (!count || !output)
	{
		fprintf(stderr, "Error: memory allocation failed.\n");
		exit(1);
	}
	for (unsigned int i = 0; i < array->size; i++)
		count[array->data[i] - array->min]++;
	for (int i = 1; i < range; i++)
		count[i] += count[i - 1];
	for (int i = array->size - 1; i >= 0; i--)
	{
		output[count[array->data[i] - array->min] - 1] = array->data[i];
		count[array->data[i] - array->min]--;
	}
	for (unsigned int i = 0; i < array->size; i++)
		array->data[i] = output[i];
	free(count);
	free(output);
}
