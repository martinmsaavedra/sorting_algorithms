#include "sort.h"
/**
 * merge_sort - merge sort main function
 * @array: array to sort
 * @size: left index of the array
 */
void merge_sort(int *array, size_t size)
{

	if ((!array) || size < 2)
		return;

	mergeSort(array, 0, (size - 1));
}
/**
 * mergeSort - merge sort auxiliary function
 * @array: array to sort
 * @left: left index of the array
 * @right: right index of the array
 */
void mergeSort(int *array, size_t left, size_t right)
{
	size_t mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;
		mergeSort(array, left, mid);
		mergeSort(array, mid + 1, right);
		merge(array, left, mid, right);
	}
}
/**
 * merge - merge sort
 * @arr: array to sort
 * @p: left index of the array
 * @q: middle of the array
 * @r: right index of the array
 */
void merge(int *arr, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int i, j, k, count = 0, index = 0;
	int *L, *M;

	printf("Merging...\n");
	L = malloc(sizeof(int) * n1);
	M = malloc(sizeof(int) * n2);
	printf("[left]: ");
	for (i = 0; i < n1; i++)
	{
		L[i] = arr[p + i];
		if (i + 1 == n1)
			printf("%d\n", L[i]);
		else
			printf("%d, ", L[i]);
	}
	printf("[right]: ");
	for (j = 0; j < n2; j++)
	{
		M[j] = arr[q + 1 + j];
		if (j + 1 == n2)
			printf("%d\n", M[j]);
		else
			printf("%d, ", M[j]);
	}
	i = 0, j = 0, k = p;
	while (i < n1 && j < n2)
	{
		if (L[i] <= M[j])
		{
			arr[k] = L[i];
			count++;
			i++;
		}
		else
		{
			arr[k] = M[j];
			count++;
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		count++;
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = M[j];
		count++;
		j++;
		k++;
	}
	free(L);
	free(M);
	printf("[Done]: ");
	for (index = p; index < p + count; index++)
	{
		if (index + 1 == p + count)
			printf("%d\n", arr[index]);
		else
			printf("%d, ", arr[index]);
	}
}
