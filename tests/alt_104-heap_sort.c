#include "sort.h"

void restore_heap_down(int *array, size_t size, size_t heap_size, size_t root);

/**
 * restore_heap_down - Restores a binary tree represented by an array.
 * @array: Array of integers representing a binary tree.
 * @size: Size of the array/tree.
 * @heap_size: size of the heap.
 * @root: Root node of the binary tree.
 *
 * Description: Restorees a binary tree represented by an array to
 * a complete binary heap from the given root node down to the last
 * node of the tree by comparing the root node with its left and right
 * child nodes and swapping them if they are out of order.
 */
void restore_heap_down(int *array, size_t size, size_t heap_size, size_t root)
{
	size_t left, right, largest;

	left = 2 * root + 1;
	right = 2 * root + 2;
	largest = root;

	/* Find the largest element among root, left child and right child. */
	if (left < heap_size && array[left] > array[largest])
		largest = left;
	if (right < heap_size && array[right] > array[largest])
		largest = right;

	/* If the largest element is not the root, swap it with the root. */
	if (largest != root)
	{
		swap(array + root, array + largest, sizeof(int));
		print_array(array, size);
		restore_heap_down(array, size, heap_size, largest);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the
 *             heap sort algorithm.
 * @array: Pointer to the array of integers.
 * @size: The number of elements in the array.
 *
 * Description: Sorts the array using the heap sort algorithm. Prints the
 * array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	/* Build a max heap from the array. */
	for (i = size / 2 - 1; i >= 0; i--)
		restore_heap_down(array, size, size, i);

	/**
	 * Extract elements from the heap one by one and put them
	 * at the end of the array
	 */
	for (i = size - 1; i > 0; i--)
	{
		swap(array, array + i, sizeof(int));
		print_array(array, size);
		restore_heap_down(array, size, i, 0);
	}
}

/**
 * compilation: gcc -Wall -Wextra -Werror -pedantic  -std=gnu89
 * 104-main.c 104-heap_sort.c  helpers.c utils.c -o heap_alt
 *
 * Altrnatively: add `swap()` function definition from `helpers`
 */
