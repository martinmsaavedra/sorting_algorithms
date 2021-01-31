#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 * @array: array to sort
 * @size: size of array
 **/

void bubble_sort(int *array, size_t size)
{
	size_t c, d, swap;

	if (array == NULL || size < 2)
		return;

	for (c = 0; c < size - 1; c++)
	{
		for (d = 0; d < size - 1; d++)
		{
			if (array[d] > array[d + 1])
			{
				swap = array[d];
				array[d] = array[d + 1];
				array[d + 1] = swap;
				print_array(array, size);
			}
		}
	}
}
