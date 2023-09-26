#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list
 * of integers in ascending order
 * algorithm
 *
 * @list: doubly linked list
 * Return: no return
 */
void insertion_sort_list(listint_t **list)
{
	 listint_t *curr, *inse, *tmp;

        curr = (*list)->next;

	if (!list || !(*list) || !((*list)->next))
		return;

	while (curr)
	{
		inse = curr;

		while (inse->prev && inse->n < inse->prev->n)
		{
			tmp = inse->prev;
			inse->prev = tmp->prev;
			tmp->next = inse->next;

			if (inse->next)
				inse->next->prev = tmp;
			
			inse->next = tmp;
			tmp->prev = inse;

			if (tmp->prev)
				tmp->prev->next = inse;
			else
				*list = inse;

			print_list(*list);
		}

		curr = curr->next;
	}
}
