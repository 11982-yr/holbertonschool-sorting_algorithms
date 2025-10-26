#include "sort.h"
#include <stdio.h>
/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 *
 * This function sorts an array by repeatedly finding the minimum
 * element from the unsorted portion and moving it to the front.
 * The array is printed after each swap to show the sorting process.
 * Works for arrays of any size.
 */
void selection_sort(int *array, size_t size)
{
/* i for the inner loop, j for outter*/
size_t i, j, min_idx;
for (i = 0; i < size - 1; i++)
{
min_idx = i;
for (j = i +1; j < size; j++)
{
if (array[j] < array[min_idx])
min_idx = j;
}
if (min_idx != i)
{
int temp = array[i];
array[i] = array[min_idx];
array[min_idx] = temp;
print_array(array, size);
}
}
}
