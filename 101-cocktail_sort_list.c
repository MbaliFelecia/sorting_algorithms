#include "sort.h"

/**
 * nodes_swap - Swaps two nodes in a doubly linked list.
 *
 * @list: Pointer to the first node of the list.
 * @first: Pointer to the first node to be swapped.
 * @second: Pointer to the second node to be swapped.
 */
void nodes_swap(listint_t **list, listint_t *first, listint_t *second)
{
	if (!first->prev) /* At the first node */
		*list = second;
	else
		first->prev->next = second;

	if (second->next) /* Not at the last node */
		second->next->prev = first;

	first->prev = second;
	first->next = second->next;
	second->next = first;
	second->prev = NULL; /* Update the previous of the second node */
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using the cocktail sort
 * algorithm.
 *
 * @list: Pointer to the first node of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *future;
	int swapped = 1;

	if (!list || !(*list) || !(*list)->next) /* Only one node or no nodes */
		return;

	future = *list;
	while (swapped)
	{
		swapped = 0;
		while (future->next) /* Traverse forward */
		{
			if (future->n > future->next->n)
			{
				nodes_swap(list, future, future->next);
				print_list(*list);
				swapped = 1;
				continue;
			}
			future = future->next;
		}

		if (!swapped) /* List is sorted */
			break;

		swapped = 0;
		while (future->prev) /* Traverse backwards */
		{
			if (future->n < future->prev->n)
			{
				nodes_swap(list, future->prev, future);
				print_list(*list);
				swapped = 1;
				continue;
			}
			future = future->prev;
		}
	}
}

