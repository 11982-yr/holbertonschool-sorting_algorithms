#include "sort.h"
/**
 * swap_ints - Swaps two integers in an array
 * @a: First integer
 * @b: Second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp;
tmp = *a;
*a = *b;
*b = tmp;
}
/**
 * lomuto_partition - Lomuto partition scheme
 * @array: The array of integers
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array (for printing)
 *
 * Return: The index of the pivot after partition
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;
int j;
for (j = low; j < high; j++)
{
if (array[j] < pivot)
{
i++;
if (i != j)
{
swap_ints(&array[i], &array[j]);
print_array(array, size);
}
}
}
if (array[i + 1] != array[high])
{
swap_ints(&array[i + 1], &array[high]);
print_array(array, size);
}
return (i + 1);
}
/**
 * quick_sort_recursive - Helper function for recursive quick sort
 * @array: Array of integers
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
int pivot_index;
if (low < high)
{
pivot_index = lomuto_partition(array, low, high, size);
quick_sort_recursive(array, low, pivot_index - 1, size);
quick_sort_recursive(array, pivot_index + 1, high, size);
}
}
/**
 * quick_sort - Sorts an array of integers using Quick sort algorithm
 * @array: The array of integers
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
quick_sort_recursive(array, 0, (int)size - 1, size);
}
