#include "sort.h"

/**
 * lumoto_partition - Partition an array using the Lumoto partiton scheme
 * @array: array to partition
 * @first: index of the first element of @array
 * @last: index of the last element of @array
 * @size: size of @array
 *
 * Return: index of last sorted element.
 */
int lumoto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(&array[current], &array[finder],
						sizeof(int));
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap(&array[current], &array[last], sizeof(int));
		print_array(array, size);
	}
	return (current);
}

/**
 * qs - quicksort algorithm using the Lumoto partition scheme.
 * @array: array to sort
 * @first: index of the first element of @array
 * @last: index of the last element of @array
 * @size: size of array
 */
void qs(int *array, ssize_t first, ssize_t last, size_t size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = lumoto_partition(array, first, last, size);

		qs(array, first, position - 1, size);
		qs(array, position + 1, last, size);
	}
}

/**
 * quick_sort - Sort an arrray using the quick sort algorithm.
 * @array: array to sort
 * @size: size of the @array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	qs(array, 0, size - 1, size);
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
