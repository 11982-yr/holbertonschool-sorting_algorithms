#include "sort.h"
#include <stdlib.h>

/**
 * find_max - helper to find maximum value.
 *
 * @array: array of integers.
 * @size: size of array.
 *
 * Return: 1 on success, 0 otherwise.
 */

static int find_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * init_count_array - initializer for counting array.
 *
 * @k: the largest number in array.
 *
 * Return: 1 on success, 0 otherwise.
 */

static int *init_count_array(int k)
{
	size_t i;

	int *count = malloc((k + 1) * sizeof(int));

	if (!count)
		return (NULL);

	for (i = 0; i <= (size_t)k; i++)
		count[i] = 0;

	return (count);
}

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

	if (!array || size < 2)
	return;

	k = find_max(array, size);
	count_array = init_count_array(k);
	if (!count_array)
		return;

	output = malloc(size * sizeof(int));
	if (!output)
	{
	free(count_array);
	return;
	}

	for (n = 0; n < size; n++)
		count_array[array[n]]++;

	for (n = 1; n <= (size_t)k; n++)
		count_array[n] += count_array[n - 1];

	print_array(count_array, k + 1);

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
