#include "./bubble-sort.h"
#include <assert.h>
#include <stdbool.h>

int	main(void)
{
	Array	*random_arr;

	random_arr = random_array(1000);
	bubble_sort(random_arr);
	assert(is_sorted(random_arr) == true);
	destroy_array(random_arr);
}
