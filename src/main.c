#include "./analytics.h"
#include "./array.h"
#include "./sorting-algorithms.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VERBOSE 0

int	main(void)
{
	Array			*array;
	unsigned int	size;
	bool			sorted;
	clock_t			t1;
	double			time_taken;
	FILE			*execution_time_file;

	size = 1000000;
	array = random_array(size);
	execution_time_file = open_file("execution_time");
	if (VERBOSE)
		print_array(array);
	t1 = start_timer();
	quick_sort(array, 0, array->size - 1);
	time_taken = get_execution_time(t1);
	if (VERBOSE)
		print_array(array);
	write_in_file(execution_time_file, time_taken);
	/* check if the array is sorted */
	sorted = is_sorted(array);
	/* print a message based on the sorted variable */
	printf("The array is %s\n", sorted ? "sorted" : "not sorted");
	destroy_array(array);
	close_file(execution_time_file);
	return (EXIT_SUCCESS);
}
