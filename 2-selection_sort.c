#include "sort.h"

/**
 * selection_sort - order an array using the algorithm selection_sort
 * @array: the array
 * @size: the size of the array
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, pos = 0;
	int dancer = 0, count = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		count = 0;
		dancer = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (dancer > array[j])
			{
				dancer = array[j];
				pos = j;
				count++;
			}
		}
		if (count == 0)
			continue;
		array[pos] = array[i];
		array[i] = dancer;
		print_array(array, size);
	}
}
