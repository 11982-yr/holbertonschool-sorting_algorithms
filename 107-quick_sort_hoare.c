#include <stdio.h>
#include "sort.h"

/**
 * swap - swaps two integers in an array
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
 * hoare_partition - partitions the array using Hoare scheme
 * @array: the array to partition
 * @low: starting index
 * @high: ending index
 * @size: size of the array (for printing)
 *
 * Return: index of partition
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap(&array[i], &array[j]);
        print_array(array, size);
    }
}

/**
 * quick_sort_recursive - recursively sorts an array using Hoare partition
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: size of array (for printing)
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int p = hoare_partition(array, low, high, size);
        quick_sort_recursive(array, low, p, size);
        quick_sort_recursive(array, p + 1, high, size);
    }
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * using the Quick sort algorithm with Hoare partition scheme
 * @array: array to sort
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}
