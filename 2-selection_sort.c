#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm.
 * @array: Pointer to the first element of the array to be sorted.
 * @size: Number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int tmp;

	/* Check for valid input */
	if (array == NULL || size < 2)
		return;

	/* Perform selection sort */
	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			/* Find the minimum element in the unsorted part */
			if (array[j] < array[min_index])
				min_index = j;
		}

		/* Swap the minimum element with the first element */
		if (min_index != i)
		{
			tmp = array[i];
			array[i] = array[min_index];
			array[min_index] = tmp;

			/* Print the array after every swap */
			print_array(array, size);
		}
	}
}
