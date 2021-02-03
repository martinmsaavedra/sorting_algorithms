#include "sort.h"

/**
 * swap -  swap position of two elements
 * @a: element to swap with b
 * @b: element to swap with a
 */
void swap(int *a, int *b)
{
	int temp = *a;

	if (*a != *b)
	{
		*a = *b;
		*b = temp;
	}
}

/**
 * heapify - heapify a tree
 * @array: array to heapify
 * @size: size of array
 * @i: idx to check if its larger
 * @size_print: size for printing
 */


void heapify(int *array, size_t size, size_t i, size_t size_print)
{
	/**
	 * Heapify proceso de crear la estructura de datos HEAP a partir
	 *de una arbol binario.
	 */
	size_t largest = i;
	/*hijo izquierdo*/
	size_t left = 2 * i + 1;
	/*hijo derecho*/
	size_t right = 2 * i + 2;


	if (left < size && array[left] > array[largest])
		largest = left;
	if (right < size && array[right] > array[largest])
		largest = right;

	/*cambiar y seguir haciendo heapyfy si la root no es el mayor*/
	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		heapify(array, size, largest, size_print);
		print_array(array, size_print);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: array to sort
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
		return;

	/**
	 * Empezar por el primer indice del nodo ->non-leaf n/2 - 1.
	 * Cada Nodo es i, vas disminuyendo para ir de arriba hacia abajo
	 */
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);
	/*Heap sort*/
	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		heapify(array, i, 0, size);
		print_array(array, size);
	}
}
