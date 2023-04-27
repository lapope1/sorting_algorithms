#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm
 * @array: pointer to the array to sort
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum gap */
	while (gap < size / 3)
	gap = gap * 3 + 1;

	/* Do the shell sort */
	while (gap > 0)
	{
	for (i = gap; i < size; i++)
	{
		for (j = i; j >= gap && array[j] < array[j - gap]; j -= gap)
		{
			/* Swap the elements */
			swap(&array[j], &array[j - gap], sizeof(int));
		}
	}

	/* Print the current array */
	print_array(array, size);

	/* Decrease the gap */
	gap = gap / 3;
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
