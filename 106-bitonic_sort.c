#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_ints - Swap two integers
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
 * bitonic_merge - Merges a bitonic sequence
 * @array: Array to sort
 * @size: Full array size
 * @start: Starting index of sequence
 * @seq: Length of sequence
 * @dir: Direction (1 for UP, 0 for DOWN)
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, int dir)
{
    if (seq > 1)
    {
        size_t k = seq / 2, i;

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
 * bitonic_seq - Builds bitonic sequence recursively
 * @array: Array to sort
 * @size: Full array size
 * @start: Starting index
 * @seq: Sequence size
 * @dir: Direction (1 for UP, 0 for DOWN)
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
 * bitonic_sort - Sorts an array in ascending order using Bitonic sort
 * @array: Array to sort
 * @size: Array size (must be power of 2)
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_seq(array, size, 0, size, 1);
}
