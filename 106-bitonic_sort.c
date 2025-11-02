#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * swap_ints - Swaps two integers in an array
 * @a: First integer
 * @b: Second integer
 */
void swap_ints(int *a, int *b)
{
int tmp = *a;
*a = *b;
*b = tmp;
}
/**
 * bitonic_merge - Merges a bitonic sequence in a given direction
 * @array: Array to sort
 * @size: Total size of array
 * @start: Starting index
 * @seq: Number of elements in the sequence
 * @dir: 1 for ascending, 0 for descending
 */
void bitonic_merge(int *array, size_t size, size_t start,
size_t seq, int dir)
{
if (seq > 1)
{
size_t k = seq / 2;
size_t i;
for (i = start; i < start + k; i++)
{
if ((dir && array[i] > array[i + k]) ||
(!dir && array[i] < array[i + k]))
{
swap_ints(&array[i], &array[i + k]);
print_array(array, size);
}
}
bitonic_merge(array, size, start, k, dir);
bitonic_merge(array, size, start + k, k, dir);
}
}
/**
 * bitonic_seq - Recursively builds a bitonic sequence
 * @array: Array to sort
 * @size: Total size of array
 * @start: Starting index
 * @seq: Number of elements in this sequence
 * @dir: 1 for ascending, 0 for descending
 */
void bitonic_seq(int *array, size_t size, size_t start,
size_t seq, int dir)
{
if (seq > 1)
{
size_t k = seq / 2;
char *direction = (dir == 1) ? "UP" : "DOWN";
printf("Merging [%lu/%lu] (%s):\n", seq, size, direction);
print_array(array + start, seq);
bitonic_seq(array, size, start, k, 1);
bitonic_seq(array, size, start + k, k, 0);
bitonic_merge(array, size, start, seq, dir);
printf("Result [%lu/%lu] (%s):\n", seq, size, direction);
print_array(array + start, seq);
}
}
/**
 * bitonic_sort - Sorts an array of integers in ascending order
 * using Bitonic sort
 * @array: Array to sort
 * @size: Number of elements in the array (must be power of 2)
 */
void bitonic_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
bitonic_seq(array, size, 0, size, 1);
}
