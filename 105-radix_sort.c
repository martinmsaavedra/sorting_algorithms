#include "sort.h"

/**
 * is_in_3 - count how many times appear an element in an array
 * @copy_array: the array
 * @size: the size of the array
 * @num: element to find
 * @divisor: divisor
 * Return: count of times to appear
 */
int is_in_3(int *copy_array, size_t size, int num, int divisor)
{
	size_t i = 0;
	int tmp = 0;

	for (; i < size; i++)
	{
		if ((copy_array[i] / divisor) % 10 == num)
		{
			tmp = copy_array[i];
			copy_array[i] = -1;
			break;
		}
	}
	return (tmp);
}

/**
 * is_in_2 - count how many times appear an element in an array
 * @array: the array
 * @size: the size of the array
 * @num: element to find
 * @divisor: divisor
 * Return: count of times to appear
 */

int is_in_2(int *array, size_t size, int num, int divisor)
{
	size_t i = 0;
	int count = 0;

	for (; i < size; i++)
	{
		if ((array[i] / divisor) % 10 == num)
			count++;
	}
	return (count);
}

/**
 * countingSort - sort an array using counting sort algorithm
 * @array: The array
 * @size: The size of the array
 * @divisor: divisor
 * Return: Nothing
 */

void countingSort(int *array, size_t size, int divisor)
{
	int *count_array = NULL, count = 0;
	int i = 0, j = 0, index = 0;
	int *copy_array = malloc(sizeof(int) * size);

	for (i = 0; i < (int)size; i++)
	{
		copy_array[i] = array[i];
	}
	count_array = malloc(sizeof(int) * 10);
	for (i = 0; i < 10; i++)
	{
		count += is_in_2(array, size, i, divisor);
		count_array[i] = count;
	}

	for (i = 0; i < 10; i++)
	{
		if (count_array[i + 1] > count_array[i] && i + 1 <= 9)
		{
			j = count_array[i + 1] - count_array[i];
			for (; j > 0; j--)
			{
				array[index++] = is_in_3(copy_array, size, i + 1, divisor);
			}
		}
	}
	free(count_array);
	free(copy_array);
}

/**
 * largest_int - return the largest int in array
 * @array: the array
 * @size: the size of the array
 * Return: the largest int
 */

int largest_int(int *array, size_t size)
{
	size_t i = 0;
	int largest = array[0];

	for (; i < size; i++)
	{
		if (largest < array[i + 1] && i + 1 < size)
			largest = array[i + 1];
	}
	return (largest);
}

/**
 * radix_sort - sort array with radix_sort algorithm
 * @array: The array
 * @size: The size of the array
 * Return: Nothing
 */

void radix_sort(int *array, size_t size)
{
	int largest = 0, digits = 0, i = 0, divisor = 1;

	if (array == NULL || size < 2)
		return;
	largest = largest_int(array, size);
	while (largest != 0)
	{
		digits++;
		largest /= 10;
	}
	for (i = 0; i < digits; i++)
	{
		countingSort(array, size, divisor);
		divisor *= 10;
		print_array(array, size);
	}
}
