#include "sort.h"

/**
 * swap - Swaps the contents of two memory locations of a given size.
 * @a: Pointer to the first memory location.
 * @b: Pointer tot the second memory location.
 * @size: Size of the memory locations to swap, in bytes.
 *
 * Description: The contents of the memory locations are copied
 * to temporary memory before swap, to ensure that the swap is done
 * correctly even if the memory locations overlap.
 */
void swap(void *a, void *b, size_t size)
{
	void *tmp = malloc(size);  /* Allocate temporary memory */

	memcpy(tmp, a, size);  /* Copy contents of `a` to `tmp` */
	memcpy(a, b, size);  /* Copy contents of `b` to `a` */
	memcpy(b, tmp, size);  /* Copy contents of `tmp` to `b` */

	free(tmp);  /* Free temporary memory */
}


/**
 * swap_node - Swaps a node with its previous node.
 * @node: Pointer to node to be swapped.
 * @list: Pointer to the head node of the list.
 *
 * Return: Pointer to the node that was just swapped.
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *prev_node, *next_node;

	prev_node = node->prev;
	next_node = node->next;

	/* Update the next and prev pointers of the nodes */
	if (prev_node)
		prev_node->next = next_node;

	if (next_node)
		next_node->prev = prev_node;

	node->prev = prev_node->prev;
	prev_node->prev = node;
	prev_node->next = node->next;
	node->next = prev_node;

	/* If the previous node is now the head node */
	if (node->prev == NULL)
		*list = node;

	return (node);
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


/**
 * find_maximum - Finds the maximum integer in an array.
 * @array: Array of integers.
 * @size: Number of elements in @array
 *
 * Return: The maximum integer in the @array
 */
int find_maximum(int *array, size_t size)
{
	int i, max_int;

	/* Loop through the array and find maximum value */
	for (max_int = array[0], i = 1; i < (int)size; i++)
	{
		if (array[i] > max_int)
		{
			max_int = array[i];
		}
	}

	return (max_int);
}
