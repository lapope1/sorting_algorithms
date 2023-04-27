#include "sort.h"

/**
 * restore_heap_down - Restore the heap property of a binary tree
 * starting from the root node and moving down.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @root: The root node of the binary tree.
 * @end: The end index of the binary tree.
 *
 * Description: This function restores the heap property of a binary
 * tree by moving down the tree from the root node, swapping nodes as
 * necessary to maintain the heap property.
 */
void restore_heap_down(int *array, size_t size, size_t root, size_t end)
{
	size_t child, swap_index;

	while ((child = 2 * root + 1) <= end)
	{
		swap_index = root;

		if (array[swap_index] < array[child])
			swap_index = child;

		if (child + 1 <= end && array[swap_index] < array[child + 1])
			swap_index = child + 1;

		if (swap_index == root)
			return;

		swap(array + root, array + swap_index, sizeof(int));
		print_array(array, size);

		root = swap_index;
	}
}

/**
 * heap_sort - Sort an array of integers in ascending order
 * using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: This function sorts an array of integers using the
 * heap sort algorithm, which first creates a max heap of the array
 * and then repeatedly extracts the maximum element and places it
 * at the end of the array until the array is sorted in ascending
 * order. The function uses the restore_heap_down function to
 * restore the heap property of the binary tree after each swap.
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2; i > 0; i--)
		restore_heap_down(array, size, i - 1, size - 1);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, array + i, sizeof(int));
		print_array(array, size);
		restore_heap_down(array, size, 0, i - 1);
	}
}

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
