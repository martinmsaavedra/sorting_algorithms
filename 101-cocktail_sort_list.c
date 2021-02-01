#include "sort.h"

/**
 * cocktail_sort_list - order a double linked
 * list using the algorithm cocktail_sort
 * @list: Double linked list
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *aux = NULL, /**head = NULL,*/ *tail = NULL;
	int count = 0;

	if (!list || !(*list) || (!(*list)->next))
		return;
	aux = *list;
	while (1)
	{
		count = 0;
		while (aux->next)
		{
			if (aux->n > aux->next->n && aux->next)
			{
				swap_nodes(list, aux, aux->next);
				print_list(*list);
				count++;
				aux = aux->prev;
			}
			if (aux->next == NULL && tail == NULL)
			{
				tail = aux;
				tail = tail->prev;
			}
			aux = aux->next;
		}
		while (aux->prev)
		{
			if (aux->n < aux->prev->n && aux->prev)
			{
				swap_nodes(list, aux->prev, aux);
				print_list(*list);
				count++;
				aux = aux->next;
			}
			aux = aux->prev;
		}
		if (count == 0)
			break;
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
	listint_t *t1 = node_A->prev;
	listint_t *t2 = node_B->next;

	if (node_A->prev == NULL && node_B->next == NULL)
	{
		node_A->next = NULL;
		node_B->prev = NULL;
		node_A->prev = node_B;
		node_B->next = node_A;
		*list = node_B;
	}
	else if (node_A->prev == NULL)
	{
		node_A->next = t2;
		node_B->prev = NULL;
		node_A->prev = node_B;
		node_B->next = node_A;
		t2->prev = node_A;
		*list = node_B;
	}
	else if (node_B->next == NULL)
	{
		node_A->prev = node_B;
		node_B->next = node_A;
		node_B->prev = t1;
		t1->next = node_B;
		node_A->next = NULL;
	}
	else
	{
		node_A->prev = node_B;
		node_B->next = node_A;
		node_A->next = t2;
		node_B->prev = t1;
		t1->next = node_B;
		t2->prev = node_A;
	}
}
