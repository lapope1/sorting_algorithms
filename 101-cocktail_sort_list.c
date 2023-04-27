#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly-linked list of integers in
 * ascending order using the cocktail shaker algorithm.
 * @list: Pointer to the head of a listint_t doubly-linked list.
 *
 * Description: This function implements the cocktail shaker sort
 * algorithm. It takes a pointer to the head of the list and
 * modifies the list in place.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* Find the last element of the list */
	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		/* Move from left o right through the list. */
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			/* If current node > next node, swap */
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				/* Print the list after each swap */
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		/* Move from right to left through the list */
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			/* If current node < previous node, swap */
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}

/**
 * swap_node_ahead - Swaps a node in a doubly-lined list with the node ahead.
 * @list: Pointer to the head of a doubly-linked list.
 * @tail: Pointer to the tail of the doubly-linked list.
 * @shaker: Pointer to the current swapping node of the
 * cocktail shaker algorithm.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	/* Store the next node in a temporary variable */
	listint_t *tmp = (*shaker)->next;

	/* Update the prev pointer of the node ahead of the current node */
	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;

	/* Update the prev pointer of the next node */
	tmp->prev = (*shaker)->prev;

	/* Update the next pointer of the current node */
	(*shaker)->next = tmp->next;

	/* Update the prev pointer of the node following the next node */
	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;

	/**
	 * Update the prev pointer of the current node to point
	 * to the next node.
	 */
	(*shaker)->prev = tmp;

	/**
	 * Update the next pointer of the next node
	 * to point to the current node.
	 */
	tmp->next = *shaker;

	/* Update the shaker pointer to point to the next node */
	*shaker = tmp;
}

/**
 * swap_node_behind - Swaps a node in a doubly-linked list with
 * the node behind it.
 * @list: Pointer to the head of a doubly-linked list of integers.
 * @tail: Pointer to the tail of the doubly-linked list.
 * @shaker: Pointer to the current swapping node of the cocktail shaker
 * algorithm.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	/* Store the previous node in a temporary variable */
	listint_t *tmp = (*shaker)->prev;

	/* Update the next pointer of the node behind the current node */
	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;

	/* Update the next pointer of the previous node */
	tmp->next = (*shaker)->next;

	/* Update the prev pointer of the current node */
	(*shaker)->prev = tmp->prev;

	/* Update the next pointer of the node before the previous node */
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;

	/**
	 * Update the next pointer of the current node
	 * to point to the previous node.
	 */
	(*shaker)->next = tmp;

	/**
	 * Update the prev pointer of the previous node
	 * to point to the current node.
	 */
	tmp->prev = *shaker;

	/* Update the shaker pointer to point to the previous node */
	*shaker = tmp;
}
