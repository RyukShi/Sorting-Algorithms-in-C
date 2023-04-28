#include "./sorting-algorithms.h"

void	bubble_sort(Array *array)
{
	int	temp;

	for (unsigned int i = 0; i < array->size - 1; i++)
	{
		for (unsigned int j = 0; j < array->size - i - 1; j++)
		{
			if (array->data[j] > array->data[j + 1])
			{
				temp = array->data[j];
				array->data[j] = array->data[j + 1];
				array->data[j + 1] = temp;
			}
		}
	}
}

void	insertion_sort(Array *array)
{
	int temp, j;
	for (unsigned int i = 1; i < array->size; i++)
	{
		temp = array->data[i];
		j = i - 1;
		while (temp < array->data[j] && j >= 0)
		{
			array->data[j + 1] = array->data[j];
			j--;
		}
		array->data[j + 1] = temp;
	}
}
