#include "sort.h"

/**
 * insertion_sort_list - order a double linked
 * list using the algorithm insertion_sort
 * @list: Double linked list
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *aux = NULL, *head = NULL;
	int count = 0;

	if (!list || !(*list) || !(*list)->next)
		return;

	while (1)
	{
		count = 0;
		aux = *list;
		head = *list;
		while (aux->next)
		{
			if (aux->n > aux->next->n)
			{
				swap_nodes(list, aux, aux->next);
				count++;
				print_list(head);
				aux = aux->prev;

				while (aux->prev->n > aux->n)
				{
					swap_nodes(list, aux->prev, aux);
					head = *list;
					print_list(head);
					count++;
					if (aux->prev == NULL)
						break;
				}
			}
			aux = aux->next;
		}
		if (count == 0)
		{
			break;
		}
	}
}

/**
 * swap_nodes - swap the nodes of the list
 * @list: Double linked list
 * @node_A: Node A
 * @node_B: Node B
 * Return: Nothing
 */

void swap_nodes(listint_t **list, listint_t *node_A, listint_t *node_B)
{
	if (node_A->prev == NULL)
	{
		listint_t *t1 = node_B->next;

		node_A->next = t1;
		node_A->prev = node_B;
		node_B->next = node_A;
		node_B->prev = NULL;
		t1->prev = node_A;
		*list = node_B;
		return;
	}

	if (node_B->next == NULL)
	{
		listint_t *t1 = node_A->prev;

		node_B->prev = t1;
		t1->next = node_B;
		node_B->next = node_A;
		node_A->prev = node_B;
		node_A->next = NULL;
		return;
	}
	else
	{
		listint_t *t1 = node_A->prev;
		listint_t *t2 = node_B->next;

		node_A->next = t2;
		node_A->prev = node_B;
		node_B->next = node_A;
		node_B->prev = t1;
		t1->next = node_B;
		t2->prev = node_A;
		return;
	}
}
