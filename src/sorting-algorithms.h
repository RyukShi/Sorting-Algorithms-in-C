#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include "./array.h"

extern void	bubble_sort(Array *array);
extern void	insertion_sort(Array *array);
extern void	selection_sort(Array *array);
extern void	merge_sort(Array *array, unsigned int left, unsigned int right);
extern void	quick_sort(Array *array, int start, int end);

#endif /* SORTING_ALGORITHMS_H */
