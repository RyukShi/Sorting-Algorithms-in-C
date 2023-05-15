#include "./main.h"

#define VERBOSE 1

static void	merge_sort_wrapper(Array *array)
{
	merge_sort(array, 0, array->size - 1);
}

static void	quick_sort_wrapper(Array *array)
{
	quick_sort(array, 0, array->size - 1);
}

static double	average(double *times, unsigned n)
{
	double	sum;

	sum = 0;
	for (unsigned i = 0; i < n; i++)
		sum += times[i];
	return (sum / n);
}

static void	analytics(char *algorithm_name,
						void (*algorithm)(Array *),
						FILE *f,
						unsigned repeat,
						unsigned start_size,
						unsigned max_size,
						float mult)
{
	Array	*array;
	clock_t	t1;
	double	*times;
	bool	sorted;

	double time_taken, avg;
	times = malloc(repeat * sizeof(double));
	while (start_size <= max_size)
	{
		for (unsigned i = 0; i < repeat; i++)
		{
			array = random_array(start_size);
			sorted = false;
			find_min_and_max(array);
			t1 = start_timer();
			algorithm(array);
			time_taken = get_execution_time(t1);
			times[i] = time_taken;
			sorted = is_sorted(array);
			if (!sorted)
				printf("sorting process failed for %s!\n", algorithm_name);
			destroy_array(array);
		}
		avg = average(times, repeat);
		if (VERBOSE)
			printf("%s: %f second(s), %u random integers\n",
					algorithm_name,
					avg,
					start_size);
		write_in_file(f, avg, algorithm_name, start_size);
		start_size *= mult;
	}
	free(times);
}

int	main(void)
{
	FILE	*data_file;

	data_file = open_file("data_file");
	analytics("merge sort",
				merge_sort_wrapper,
				data_file,
				8,
				10000,
				1500000,
				1.115f);
	analytics("quick sort",
				quick_sort_wrapper,
				data_file,
				8,
				10000,
				1500000,
				1.115f);
	analytics("radix sort",
				radix_sort,
				data_file,
				8,
				10000,
				1500000,
				1.115f);
	analytics("bubble sort",
				bubble_sort,
				data_file,
				4,
				1000,
				250000,
				1.25f);
	analytics("insertion sort",
				insertion_sort,
				data_file,
				4,
				1000,
				450000,
				1.25f);
	analytics("selection sort",
				selection_sort,
				data_file,
				4,
				1000,
				450000,
				1.25f);
	analytics("counting sort",
				counting_sort,
				data_file,
				1,
				1000,
				450000,
				1.25f);
	close_file(data_file);
	return (EXIT_SUCCESS);
}
