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
	times = (double *)malloc(repeat * sizeof(double));
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
	FILE	*merge_quick_radix;

	merge_quick_radix = open_file("merge_quick_radix");
	analytics("merge sort",
				merge_sort_wrapper,
				merge_quick_radix,
				8,
				10000,
				1500000,
				1.115f);
	analytics("quick sort",
				quick_sort_wrapper,
				merge_quick_radix,
				8,
				10000,
				1500000,
				1.115f);
	analytics("radix sort",
				radix_sort,
				merge_quick_radix,
				8,
				10000,
				1500000,
				1.115f);
	close_file(merge_quick_radix);
	return (EXIT_SUCCESS);
}
