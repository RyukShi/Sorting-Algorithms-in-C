#include "./array.h"

void	selection_sort(Array *array)
{
	int	temp;

	unsigned int min_index, i, j;
	for (i = 0; i < array->size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < array->size; j++)
		{
			if (array->data[j] < array->data[min_index])
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			temp = array->data[i];
			array->data[i] = array->data[min_index];
			array->data[min_index] = temp;
		}
	}
}
