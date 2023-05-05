#include "./sorting-algorithms.h"
#include <stdlib.h>

static void	merge(Array *array, unsigned int left, unsigned int middle,
		unsigned int right)
{
	unsigned int i, j, k, n1, n2;
	n1 = middle - left + 1;
	n2 = right - middle;
	int	left_array[n1], right_array[n2];
	for (i = 0; i < n1; i++)
		left_array[i] = array->data[left + i];
	for (j = 0; j < n2; j++)
		right_array[j] = array->data[middle + 1 + j];
	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2)
	{
		if (left_array[i] <= right_array[j])
		{
			array->data[k] = left_array[i];
			i++;
		}
		else
		{
			array->data[k] = right_array[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		array->data[k] = left_array[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		array->data[k] = right_array[j];
		j++;
		k++;
	}
}

void	merge_sort(Array *array, unsigned int left, unsigned int right)
{
	unsigned int	middle;

	if (left < right)
	{
		middle = (left + right) / 2;
		merge_sort(array, left, middle);
		merge_sort(array, middle + 1, right);
		merge(array, left, middle, right);
	}
}

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
