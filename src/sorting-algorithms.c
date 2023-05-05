#include "./sorting-algorithms.h"
#include <stdlib.h>

static int	partition(Array *array, int start, int end)
{
	int pivot, temp, i, j;
	pivot = array->data[end];
	i = start - 1;
	for (j = start; j <= end - 1; j++)
	{
		if (array->data[j] < pivot)
		{
			i++;
			temp = array->data[i];
			array->data[i] = array->data[j];
			array->data[j] = temp;
		}
	}
	temp = array->data[i + 1];
	array->data[i + 1] = array->data[end];
	array->data[end] = temp;
	return (i + 1);
}

void	quick_sort(Array *array, int start, int end)
{
	int	p;

	if (start < end)
	{
		p = partition(array, start, end);
		quick_sort(array, start, p - 1);
		quick_sort(array, p + 1, end);
	}
}

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

static void	counting_sort_two(Array *array, int place)
{
	int	freq[10] = {0};
	int	*output;

	output = (int *)malloc(array->size * sizeof(int));
	for (unsigned int i = 0; i < array->size; i++)
		freq[(array->data[i] / place) % 10]++;
	for (int i = 1; i < 10; i++)
		freq[i] += freq[i - 1];
	for (int i = array->size - 1; i >= 0; i--)
	{
		output[freq[(array->data[i] / place) % 10] - 1] = array->data[i];
		freq[(array->data[i] / place) % 10]--;
	}
	for (unsigned int i = 0; i < array->size; i++)
		array->data[i] = output[i];
	free(output);
}

void	radix_sort(Array *array)
{
	int mul, max;
	mul = 1;
	max = array->max;
	while (max)
	{
		counting_sort_two(array, mul);
		mul *= 10;
		max /= 10;
	}
}
