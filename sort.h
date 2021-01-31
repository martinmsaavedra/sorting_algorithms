#ifndef SORT_ALGOS
#define SORT_ALGOS

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *node_A, listint_t *node_B);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quicksort(int *array, ssize_t start, ssize_t next, size_t size);
void swap(int *a, int *b);
int partition(int *array, ssize_t start, ssize_t next, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);

#endif
