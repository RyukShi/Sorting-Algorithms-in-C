#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int	*random_array(unsigned int size)
{
	int	*array;

	array = (int *)malloc(size * sizeof(int));
	for (unsigned int i = 0; i < size; i++)
	{
		array[i] = rand();
	}
	return (array);
}

void	destroy_array(int *array)
{
	free(array);
}

void	print_array(int *array, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}

void	bubble_sort(int *array, unsigned int size)
{
	int	temp;

	for (unsigned int i = 0; i < size - 1; i++)
	{
		for (unsigned int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

bool	is_sorted(int *array, int size)
{
	unsigned int	i;

	for (i = 0; i < size - 1; i++)
	{
		if (array[i] > array[i + 1])
		{
			return (false);
		}
	}
	return (true);
}

int	main(void)
{
	int				*array;
	unsigned int	size;
	bool			sorted;

	size = 20;
	array = random_array(size);
	print_array(array, size);
	bubble_sort(array, size);
	printf("%s", "\n\n");
	print_array(array, size);
	/* check if the array is sorted */
	sorted = is_sorted(array, size);
	/* print a message based on the sorted variable */
	printf("The array is %s\n", sorted ? "sorted" : "not sorted");
	destroy_array(array);
	return (EXIT_SUCCESS);
}
