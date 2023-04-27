#include "sort.h"

/**
 * counting_sort - Sort an array of integers in ascending order
 * using the counting sort algorithm.
 * @array: Array of integers.
 * @size: Number of elements in an array.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = find_maximum(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
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
