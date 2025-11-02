#include <stdio.h>
#include "sort.h"
/**
 * get_max - Gets the maximum value in an array
 * @array: The array
 * @size: The size of the array
 * Return: The maximum integer in the array
 */
int get_max(int *array, size_t size)
{
int max = array[0];
size_t i;
for (i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}
return (max);
}
/**
 * counting_sort_digit - Performs counting sort on a specific digit
 * @array: The array to sort
 * @size: The size of the array
 * @exp: The digit exponent (1 for ones, 10 for tens, etc.)
 */
void counting_sort_digit(int *array, size_t size, int exp)
{
int *output, count[10] = {0};
size_t i;
output = malloc(size * sizeof(int));
if (!output)
return;
for (i = 0; i < size; i++)
count[(array[i] / exp) % 10]++;
for (i = 1; i < 10; i++)
count[i] += count[i - 1];
for (i = size; i > 0; i--)
{
output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
count[(array[i - 1] / exp) % 10]--;
}
for (i = 0; i < size; i++)
array[i] = output[i];
free(output);
}
/**
 * radix_sort - Sorts an array of integers in ascending order using LSD Radix sort
 * @array: The array to sort
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
int max, exp;
if (array == NULL || size < 2)
return;
max = get_max(array, size);
for (exp = 1; max / exp > 0; exp *= 10)
{
counting_sort_digit(array, size, exp);
print_array(array, size);
}
}
