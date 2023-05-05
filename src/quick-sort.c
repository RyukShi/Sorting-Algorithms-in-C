#include "./array.h"

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
