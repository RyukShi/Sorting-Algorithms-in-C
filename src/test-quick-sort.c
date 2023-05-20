#include "./quick-sort.h"
#include <assert.h>
#include <stdbool.h>

int	main(void)
{
	Array	*random_arr;

	random_arr = random_array(1000);
	find_min_and_max(random_arr);
	quick_sort(random_arr, 0, random_arr->size - 1);
	assert(is_sorted(random_arr) == true);
	destroy_array(random_arr);
	return (0);
}
