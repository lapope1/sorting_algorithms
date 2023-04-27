#include "sort.h"

/**
 * bitonic_merge - Sorts a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 * @direction: The direction to sort in, either UP or DOWN.
 *
 * Description: Sorts a bitonic sequence in an array from index start
 * to start+seq-1 in the given direction.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char direction)
{
	size_t i, jump = seq / 2;

	/* Recurse until sequence size becomes 1 */
	if (seq > 1)
	{
		/* Merge two sub-sequences */
		for (i = start; i < start + jump; i++)
		{
			if ((direction == 'u' && array[i] > array[i + jump]) ||
					(direction == 'd' && array[i] < array[i + jump]))
				swap(array + i, array + i + jump, sizeof(int));
		}
		bitonic_merge(array, size, start, jump, direction);
		bitonic_merge(array, size, start + jump, jump, direction);
	}
}

/**
 * bitonic_sequence - Converts an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @direction: The direction to sort the bitonic sequence block in,
 * either UP or DOWN.
 *
 * Description: Recursively converts the sub-sequences of array into
 * bitonic sequences and merges them in the given direction.
 */
void bitonic_sequence(int *array, size_t size, size_t start, size_t seq,
		char direction)
{
	size_t cut = seq / 2;
	char *direction_str = (direction == 'u') ? "UP" : "DOWN";

	/* Recurse until sequence size becomes 1 */
	if (seq > 1)
	{
		/* Print current sequence being merged */
		printf("Merging [%lu/%lu] (%s):\n", seq, size, direction_str);
		print_array(array + start, seq);

		/* Convert sub-sequences to bitonic sequences */
		bitonic_sequence(array, size, start, cut, 'u');
		bitonic_sequence(array, size, start + cut, cut, 'd');

		/* Merge the bitonic sequences in the given direction */
		bitonic_merge(array, size, start, seq, direction);

		/* Print the result of the merge */
		printf("Result [%lu/%lu] (%s):\n", seq, size, direction_str);
		print_array(array + start, seq);
	}
}


/**
 * bitonic_sort - Sorts an array of integers in ascending order using
 *                the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for size = 2^k
 * where k >= 0 (i.e., size must be a power of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	bitonic_sequence(array, size, 0, size, 'u');
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
