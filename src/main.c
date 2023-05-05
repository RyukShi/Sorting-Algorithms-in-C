#include "./analytics.h"
#include "./array.h"
#include "./sorting-algorithms.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define VERBOSE 1
#define ALGO_NUM 7
#define REPEAT 4
#define START_SIZE 1000
#define MAX_SIZE 1000000

static void	merge_sort_wrapper(Array *array)
{
	merge_sort(array, 0, array->size - 1);
}

static void	quick_sort_wrapper(Array *array)
{
	quick_sort(array, 0, array->size - 1);
}

static double	average(double *times)
{
	double	sum;

	sum = 0;
	for (unsigned int i = 0; i < REPEAT; i++)
		sum += times[i];
	return (sum / REPEAT);
}

static void	analytics(char *algorithm_names[],
						void (*sorting_algorithms[])(Array *array),
						FILE *f)
{
	Array			*array;
	unsigned int	size;
	clock_t			t1;
	double			*times;
	double 			time_taken, avg;
	bool			sorted;
	char			*algorithm;

	times = (double *)malloc(REPEAT * sizeof(double));
	size = START_SIZE;
	while (size <= MAX_SIZE)
	{
		for (unsigned int i = 0; i < ALGO_NUM; i++)
		{
			algorithm = algorithm_names[i];
			if (size == MAX_SIZE && (strcmp(algorithm, "bubble sort") == 0 ||
				strcmp(algorithm, "counting sort") == 0))
			{
				/* bypass sorting process cause is too long */
				continue;
			}
			for (unsigned int j = 0; j < REPEAT; j++)
			{
				array = random_array(size);
				sorted = false;
				find_min_and_max(array);
				t1 = start_timer();
				sorting_algorithms[i](array);
				time_taken = get_execution_time(t1);
				times[j] = time_taken;
				sorted = is_sorted(array);
				if (!sorted)
					printf("sorting process failed for %s!\n", algorithm);
			}
			avg = average(times);
			if (VERBOSE)
				printf("%s: %f second(s), %u random integers\n",
						algorithm,
						avg,
						size);
			write_in_file(f, avg, algorithm, size);
		}
		size *= 10;
	}
	free(times);
	destroy_array(array);
}

int	main(void)
{
	FILE	*execution_time_file;

	void (*sorting_algorithms[])(Array * array) = {bubble_sort, insertion_sort,
		selection_sort, merge_sort_wrapper, quick_sort_wrapper, counting_sort,
		radix_sort};

	char *algorithm_names[] = {"bubble sort", "insertion sort", "selection sort",
		"merge sort", "quick sort", "counting sort", "radix sort"};

	execution_time_file = open_file("execution_time");
	analytics(algorithm_names, sorting_algorithms, execution_time_file);
	close_file(execution_time_file);
	return (EXIT_SUCCESS);
}
