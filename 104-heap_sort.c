#include <stdio.h>
#include "sort.h"
/**
 * swap - Swap two integers in an array
 * @a: pointer to first integer
 * @b: pointer to second integer
 */
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}
/**
 * sift_down - Maintains the max heap property for a subtree
 * @array: The array
 * @start: Index of the root of the subtree
 * @end: Last index of the heap
 * @size: Size of the array (for printing)
 */
void sift_down(int *array, int start, int end, size_t size)
{
int root = start;
while ((2 * root + 1) <= end)
{
int child = 2 * root + 1;
int swap_idx = root;
if (array[swap_idx] < array[child])
swap_idx = child;
if ((child + 1) <= end && array[swap_idx] < array[child + 1])
swap_idx = child + 1;
if (swap_idx == root)
return;
swap(&array[root], &array[swap_idx]);
print_array(array, size);
root = swap_idx;
}
}
/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the sift-down Heap sort algorithm
 * @array: The array to sort
 * @size: Number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
if (!array || size < 2)
return;
for (int start = (size - 2) / 2; start >= 0; start--)
sift_down(array, start, size - 1, size);
for (int end = size - 1; end > 0; end--)
{
swap(&array[0], &array[end]);
print_array(array, size);
sift_down(array, 0, end - 1, size);
}
}
