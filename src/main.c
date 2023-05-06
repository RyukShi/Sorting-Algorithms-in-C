#include "./analytics.h"
#include "./array.h"
#include "./sorting-algorithms.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

static void	analytics(char *algorithm_names[],
						void (*sorting_algorithms[])(Array *array),
						FILE *f,
						unsigned repeat,
						unsigned start_size,
						unsigned max_size,
						float mult,
						unsigned algo_num)
{
	Array	*array;
	clock_t	t1;
	double	*times;
	bool	sorted;
	char	*algorithm;

	double time_taken, avg;
	times = (double *)malloc(repeat * sizeof(double));
	while (start_size <= max_size)
	{
		for (unsigned i = 0; i < algo_num; i++)
		{
			algorithm = algorithm_names[i];
			for (unsigned j = 0; j < repeat; j++)
			{
				array = random_array(start_size);
				sorted = false;
				find_min_and_max(array);
				t1 = start_timer();
				sorting_algorithms[i](array);
				time_taken = get_execution_time(t1);
				times[j] = time_taken;
				sorted = is_sorted(array);
				if (!sorted)
					printf("sorting process failed for %s!\n", algorithm);
				destroy_array(array);
			}
			avg = average(times, repeat);
			if (VERBOSE)
				printf("%s: %f second(s), %u random integers\n",
						algorithm,
						avg,
						start_size);
			write_in_file(f, avg, algorithm, start_size);
		}
		start_size *= mult;
	}
	free(times);
}

int	main(void)
{
	FILE	*execution_time_file;

	void (*fastest_algorithms[])(Array * array) = {
		merge_sort_wrapper, quick_sort_wrapper, radix_sort};
	char *fastest_algo_names[] = {
		"merge sort", "quick sort", "radix sort"};
	void (*slowest_algorithms[])(Array * array) = {
		counting_sort, selection_sort, bubble_sort, insertion_sort};
	char *slowest_algo_names[] = {
		"counting sort", "selection sort", "bubble sort", "insertion sort"};
	execution_time_file = open_file("execution_time");
	analytics(
		fastest_algo_names,
		fastest_algorithms,
		execution_time_file,
		4,
		10000,
		1000000,
		1.50f,
		3);
	analytics(
		slowest_algo_names,
		slowest_algorithms,
		execution_time_file,
		2,
		1000,
		250000,
		1.50f,
		4);
	close_file(execution_time_file);
	return (EXIT_SUCCESS);
}
