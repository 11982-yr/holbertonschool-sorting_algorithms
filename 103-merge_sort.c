#include "sort.h"
#include <stdlib.h>

/**
* merge_sort - sorts an array in ascending order 
* using the Merge sort algorithm.
*
* @array: array of integers.
* @size: size of array.
*/

void merge_sort(int *array, size_t size)
{
  size_t n;
  int k;

  if (array == NULL || size < 2)
    return;

