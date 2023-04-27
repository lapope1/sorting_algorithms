#include "sort.h"

/**
 * merge - Sort a subarray of integers.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @beg: The beg index of the subarray.
 * @mid: The middle index of the subarray.
 * @end: The end index of the subarray.
 *
 * Description: This function takes a subarray of an array
 * of integers and sorts it using the merge sort algorithm.
 * It uses a buffer to store the sorted subarray and merges
 * the left and right subarrays into the buffer.
 */
void merge(int *subarr, int *buff, size_t beg, size_t mid, size_t end)
{
	size_t i, j, k = 0;

	/* Print the left subarray to be merged */
	printf("Merging...\n[left]: ");
	print_array(subarr + beg, mid - beg);

	/* Print the right subarray to be merged */
	printf("[right]: ");
	print_array(subarr + mid, end - mid);

	/* Merge the left and right subarrays into the buffer */
	for (i = beg, j = mid; i < mid && j < end; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];

	/* Add the remaining elements from the left subarray to the buffer */
	for (; i < mid; i++)
		buff[k++] = subarr[i];

	/* Add the remaining elements from the right subarray to the buffer */
	for (; j < end; j++)
		buff[k++] = subarr[j];

	/* Copy the sorted elements from the buffer end into the subarray */
	for (i = beg, k = 0; i < end; i++)
		subarr[i] = buff[k++];

	/* Print the sorted subarray */
	printf("[Done]: ");
	print_array(subarr + beg, end - beg);
}

/**
 * divide_and_sort - Implement the merge sort algorithm through recursion.
 * @subarr: An array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @beg: The first index of the beginning of subarray to be sorted.
 * @end: The end index of the subarray to be sorted.
 *
 * Description: This function implements the merge sort algorithm
 * recursively. It divides the subarray into two halves,
 * sorts them separately, and then merges them using the merge function.
 */
void divide_and_sort(int *subarr, int *buff, size_t beg, size_t end)
{
	size_t mid;

	/**
	 * If the subarray has more than one element,
	 * divide it and sort each half
	 */
	if (end - beg > 1)
	{
		mid = beg + (end - beg) / 2;
		divide_and_sort(subarr, buff, beg, mid);
		divide_and_sort(subarr, buff, mid, end);
		merge(subarr, buff, beg, mid, end);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 * order using the merge sort algorithm.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: This function sorts an array of integers
 * using the merge sort algorithm.
 * It calls the divide_and_sort function to sort the subarrays recursively.
 * It uses a buffer to store the sorted subarrays.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	/* Check if the array is NULL or has only one element */
	if (array == NULL || size < 2)
		return;

	/* Allocate memory for the buffer */
	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	/* Call the recursive merge sort function */
	divide_and_sort(array, buff, 0, size);

	/* Free the buffer */
	free(buff);
}
