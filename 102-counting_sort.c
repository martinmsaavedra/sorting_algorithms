#include "sort.h"

/**
 * counting_sort - order an array using the algorithm counting_sort
 * @array: the array
 * @size: the size of the array
 * Return: Nothing
 */

void counting_sort(int *array, size_t size)
{
	size_t j = 0;
	int max = 0, i = 0, *count = NULL, counter = 0, total = 0, l = 0;

	if (array == NULL || size < 2)
		return;
	max = find_max(array, size);
	count = define_array(max, size);
	if (count == NULL)
		return;
	for (i = 0; i < max + 1; i++)
	{
		counter = 0;
		for (j = 0; j < size; j++)
		{
			if (i == (int)array[j])
				counter++;
		} count[i] = counter;
		total = total + counter;
		if (i != max)
			printf("%d, ", total);
		else
			printf("%d", total);
	} printf("\n");
	for (i = 0; i < max + 1; i++)
		if (count[i] != 0)
			for (j = 0; j < (size_t)count[i]; j++)
			{
				array[l] = i;
				l++;
			}
	free(count);
}

/**
 * find_max - find max integer from array given
 * @array: the array
 * @size: the size of the array
 * Return: max int from array
 */
int find_max(int *array, size_t size)
{
	int i = 0, max = 0;

	for (i = 0; i < (int)size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	return (max);
}
/**
 * define_array - allocates array
 * @max: max numbers of array
 * @size: the size of the array
 * Return: array malloced
 */
int *define_array(int max, size_t size)
{
	int i = 0;

	int *count = malloc(sizeof(int) * max + 1);

	if (count == NULL)
		return (NULL);
	for (i = 0; i < (int)size; i++)
		count[i] = 0;
	return (count);
}
