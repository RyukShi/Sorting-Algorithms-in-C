#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VERBOSE 0

FILE	*a_begin(char *file_name)
{
	FILE	*fptr;

	fptr = fopen(file_name, "a");
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: could not open file.\n");
		exit(1);
	}
	return (fptr);
}

clock_t	a_start_register(void)
{
	return (clock());
}

void	a_end_register(FILE *fptr, clock_t t1)
{
	clock_t	t2;
	double	time_taken;

	t2 = clock();
	time_taken = ((double)t2 - t1) / CLOCKS_PER_SEC;
	fprintf(fptr, "%f\n", time_taken);
}

void	a_stop(FILE *fptr)
{
	fclose(fptr);
}

int	*random_array(unsigned int size)
{
	int	*array;

	array = (int *)malloc(size * sizeof(int));
	if (array == NULL)
	{
		fprintf(stderr, "Error: memory allocation failed.\n");
		exit(1);
	}
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
	clock_t			t1;
	FILE			*execution_time_file;

	execution_time_file = a_begin("execution_time");
	size = 2000;
	array = random_array(size);
	if (VERBOSE)
		print_array(array, size);
	t1 = a_start_register();
	bubble_sort(array, size);
	a_end_register(execution_time_file, t1);
	if (VERBOSE)
	{
		printf("%s", "\n\n");
		print_array(array, size);
	}
	/* check if the array is sorted */
	sorted = is_sorted(array, size);
	/* print a message based on the sorted variable */
	printf("The array is %s\n", sorted ? "sorted" : "not sorted");
	destroy_array(array);
	a_stop(execution_time_file);
	return (EXIT_SUCCESS);
}
