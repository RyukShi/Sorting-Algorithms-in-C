#include "./array.h"

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
