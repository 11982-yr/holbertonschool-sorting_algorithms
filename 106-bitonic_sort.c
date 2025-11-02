#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_ints - Swap two integers
 * @a: first integer
 * @b: second integer
 */
void swap_ints(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * bitonic_merge - Merge bitonic sequence
 * @array: array to sort
 * @size: full array size
 * @start: starting index of the sequence
 * @seq: size of the sequence to merge
 * @dir: direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, int dir)
{
    size_t i, k;

    if (seq > 1)
    {
        k = seq / 2;
        for (i = start; i < start + k; i++)
        {
            if ((dir && array[i] > array[i + k]) ||
                (!dir && array[i] < array[i + k]))
                swap_ints(&array[i], &array[i + k]);
        }
        bitonic_merge(array, size, start, k, dir);
        bitonic_merge(array, size, start + k, k, dir);
    }
}

/**
 * bitonic_seq - Build bitonic sequence recursively
 * @array: array to sort
 * @size: total array size
 * @start: start index
 * @seq: sequence size
 * @dir: direction (1 for ascending, 0 for descending)
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, int dir)
{
    size_t k;
    char *direction = (dir == 1) ? "UP" : "DOWN";

    if (seq > 1)
    {
        k = seq / 2;
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
 * bitonic_sort - Sorts an array using Bitonic sort algorithm
 * @array: array to sort
 * @size: array size (must be power of 2)
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_seq(array, size, 0, size, 1);
}
