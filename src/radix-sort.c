#include "./array.h"
#include <stdlib.h>

static void	counting_sort_two(Array *array, int place)
{
	int	freq[10] = {0};
	int	*output;

	output = (int *)malloc(array->size * sizeof(int));
    if (!output)
    {
        fprintf(stderr, "Error: memory allocation failed.\n");
        exit(1);
    }
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
