#include "sort.h"

/**
*quick_sort - sorts an array of integers in ascending
*order using the Quick sort algorithm
*@array: the array
*@size: the size
*Return: Nothing
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}

/**
*partition - define the partition of the array
*order using the Quick sort algorithm
*@array: the array
*@start: start of array
*@next: next number
*@size: the size
*Return: index of pivot
*/

int partition(int *array, ssize_t start, ssize_t next, size_t size)
{
	int pivot = array[next];
	ssize_t j = start, i;

	for (i = start; i < next; i++)
	{
		if (array[i] < pivot)
		{
			if (j != i)
			{
				swap(&array[j], &array[i]);
				print_array(array, size);
			}

			j++;
		}
	}
	if (next != j && array[next] != array[j])
	{
		swap(&array[next], &array[j]);
		print_array(array, size);
	}
	return (j);
}

/**
*quicksort - recursion function of quicksort
*order using the Quick sort algorithm
*@array: the array
*@start: start of array
*@next: next number
*@size: the size
*Return: index of pivot
*/

void quicksort(int *array, ssize_t start, ssize_t next, size_t size)
{
	if (start < next)
	{
		int pivot = partition(array, start, next, size);

		quicksort(array, start, pivot - 1, size);
		quicksort(array, pivot + 1, next, size);
	}
}

/**
 * swap - swap numberrs
 * @a: int a
 * @b: int
 * Return: Nothing
 */

void swap(int *a, int *b)
{
	int t = *a;

	*a = *b;
	*b = t;
}
