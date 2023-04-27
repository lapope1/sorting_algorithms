#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		while ((current->prev) && (current->prev->n > current->n))
		{
			/* Swap the nodes */
			current = swap_node(current, list);

			/* Print the list after each swap */
			print_list(*list);
		}
		/* Move to the next node */
		current = current->next;
	}
}

/**
 * swap_node - swaps a node with its previous node
 *
 * @node: the node to swap
 * @list: double pointer to the head of the list
 *
 * Return: a pointer to the node that was swapped
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;

	/* swap the nodes */
	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;

	return (current);
}
