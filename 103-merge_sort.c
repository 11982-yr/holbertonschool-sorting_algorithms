#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * combine - Merge two sorted parts of an array
 * @arr: the array to sort
 * @buff: temporary buffer to hold sorted values
 * @start: starting index of left subarray
 * @mid: index separating left and right halves
 * @end: one past the last index of the right subarray
 */

static void combine(int *arr, int *buff, size_t start, size_t mid, size_t end)
{
	size_t left_i = start, right_i = mid, merge_i = start;

	printf("Merging...\n[left]: ");
	print_array(arr + start, mid - start);
	printf("[right]: ");
	print_array(arr + mid, end - mid);

	while (left_i < mid && right_i < end)
	{
		if (arr[left_i] <= arr[right_i])
			buff[merge_i++] = arr[left_i++];
		else
			buff[merge_i++] = arr[right_i++];
	}

	while (left_i < mid)
		buff[merge_i++] = arr[left_i++];
	while (right_i < end)
		buff[merge_i++] = arr[right_i++];

	for (merge_i = start; merge_i < end; merge_i++)
		arr[merge_i] = buff[merge_i];

	printf("[Done]: ");
	print_array(arr + start, end - start);
}

/**
 * recursive_divide - Split array recursively and call merge step
 * @arr: array to sort
 * @buff: temporary array for merging
 * @start: left boundary index
 * @end: right boundary index
 */

static void recursive_divide(int *arr, int *buff, size_t start, size_t end)
{
	size_t mid;

	if (end - start < 2)
		return;

	mid = (start + end) / 2;
	recursive_divide(arr, buff, start, mid);
	recursive_divide(arr, buff, mid, end);
	combine(arr, buff, start, mid, end);
}

/**
 * merge_sort - Sort an array of integers in ascending order
 * using the top-down Merge Sort algorithm
 * @array: pointer to array to sort
 * @size: number of elements in the array
 */

void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	recursive_divide(array, buffer, 0, size);
	free(buffer);
}
