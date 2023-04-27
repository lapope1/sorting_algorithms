#include "sort.h"

/**
 * radix_counting_sort - Sort the significant digits of an array of
 * integers in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @significant_digit: The significant digit to sort on.
 * @buffer: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int significant_digit,
		int *buffer)
{
	int count[10] = {0};
	size_t i;

	/* Count the number of occurences of each digit */
	for (i = 0; i < size; i++)
		count[(array[i] / significant_digit) % 10] += 1;

	/* Calculate the prefix sum of the counts */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Copy the sorted elements into the buffer */
	for (i = size - 1; i < (size_t)(-1); i--)
	{
		buffer[count[(array[i] / significant_digit) % 10] - 1] = array[i];
		count[(array[i] / significant_digit) % 10]--;
	}

	/* Copy the buffer back into the original array */
	for (i = 0; i < size; i++)
		array[i] = buffer[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 * order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm.
 */
void radix_sort(int *array, size_t size)
{
	int max_value, significant_digit, *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	/* Get the maximum value in the array */
	max_value = find_maximum(array, size);

	/* Sort the array by considering each significant digit */
	for (significant_digit = 1; max_value / significant_digit > 0;
			significant_digit *= 10)
	{
		/* Sort the array on the current digit using counting sort */
		radix_counting_sort(array, size, significant_digit, buffer);
		print_array(array, size);
	}

	free(buffer);
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
