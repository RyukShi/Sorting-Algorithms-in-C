#include "./array.h"

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
