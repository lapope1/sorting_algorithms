#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/* SORTING ALGORITHMS FUNCTION PROTOTYPES */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *arrary, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

/* HELPERS AND UTILS FUNCTION PROTOTYPES */
void swap(void *a, void *b, size_t size);
listint_t *swap_node(listint_t *node, listint_t **list);
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
int find_maximum(int *array, size_t size);
int lumoto_partition(int *array, ssize_t first, ssize_t last, size_t size);
void qs(int *array, ssize_t first, ssize_t last, size_t size);
void merge(int *subarr, int *buff, size_t beg, size_t mid, size_t end);
void divide_and_sort(int *subarr, int *buff, size_t beg, size_t end);
void restore_heap_down(int *array, size_t size, size_t root, size_t end);
void radix_counting_sort(int *array, size_t size, int significant_digit,
		int *buffer);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char direction);
void bitonic_sequence(int *array, size_t size, size_t start, size_t seq,
		char direction);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

#endif /* __SORT_H__ */
