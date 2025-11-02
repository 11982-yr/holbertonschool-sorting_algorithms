#include "sort.h"
#include <stdio.h>

/**
 * swap_ints - Swaps two integers in an array
 * @a: Pointer to first integer
 * @b: Pointer to second integer
 */
void swap_ints(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * hoare_partition - Partitions an array using Hoare scheme
 * @array: The array to partition
 * @low: Start index
 * @high: End index
 * @size: Size of the array (for printing)
 * Return: Index of partition
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

        swap_ints(&array[i], &array[j]);
        print_array(array, size);
    }
}

/**
 * quick_sort_rec - Recursive Quick Sort function
 * @array: Array to sort
 * @low: Start index
 * @high: End index
 * @size: Size of the array (for printing)
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int p = hoare_partition(array, low, high, size);
        quick_sort_rec(array, low, p, size);
        quick_sort_rec(array, p + 1, high, size);
    }
}

/**
 * quick_sort_hoare - Quick Sort algorithm using Hoare partition
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_rec(array, 0, size - 1, size);
}
