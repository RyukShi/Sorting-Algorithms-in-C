#include "./array.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	heapify(int *data, int n, int index)
{
	int	largest;
	int	left;
	int	right;

	largest = index;
	left = 2 * index + 1;
	right = 2 * index + 2;
	if (left < n && data[left] > data[largest])
		largest = left;
	if (right < n && data[right] > data[largest])
		largest = right;
	if (largest != index)
	{
		swap(&data[index], &data[largest]);
		heapify(data, n, largest);
	}
}

void	heap_sort(Array *array)
{
	int	n;

	n = array->size;
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(array->data, n, i);
	for (int i = n - 1; i > 0; i--)
	{
		swap(&array->data[0], &array->data[i]);
		heapify(array->data, i, 0);
	}
}
