#include "sort.h"
#include <stdlib.h>

/**
* counting_sort - sorts an array in ascending order 
* using the Counting sort algorithm.
*
* @array: array of integers.
* @size: size of array.
*/

void counting_sort(int *array, size_t size)
{
  size_t n;
  int k;
  int *count_array, *output;

  if (array == NULL || size < 2)
    return;

  k = array[0];
  for (n = 1; n < size; n++)
{
  if (array[n] > k)
    k = array[n];
}

count_array = malloc((k + 1) * sizeof(int));
if (count_array == NULL)
  return;
for (n = 0; n <= (size_t)k; n++)
  count_array[n] = 0;

for (n = 0; n < size; n++)
count_array[array[n]]++;

for (n = 1; n<= (size_t)k; n++)
  count_array[n] += count_array[n - 1];

print_array(count_array, k + 1);

output = malloc(size * sizeof(int));
if (output == NULL)
{
  free (count_array);
  return;
}

for (n = size; n > 0; n--)
{
  output[count_array[array[n - 1]] - 1] = array[n - 1];
  count_array[array[n - 1]]--;
}

for (n = 0; n < size; n++)
        array[n] = output[n];

    free(count_array);
    free(output);
}
