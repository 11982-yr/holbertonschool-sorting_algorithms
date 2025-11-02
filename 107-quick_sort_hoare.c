#include <stdio.h>
#include "sort.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * hoare_partition - Hoare partition with last element as pivot
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];  // pivot is last element
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do { i++; } while (array[i] < pivot);
        do { j--; } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap(&array[i], &array[j]);
        print_array(array, size);
    }
}

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int p = hoare_partition(array, low, high, size);
        quick_sort_recursive(array, low, p, size);
        quick_sort_recursive(array, p + 1, high, size);
    }
}

void quick_sort_hoare(int *array, size_t size)
{
    if (!array || size < 2)
        return;
    quick_sort_recursive(array, 0, size - 1, size);
}
