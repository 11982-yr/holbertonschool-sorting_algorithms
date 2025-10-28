#include "sort.h"

/**
* shell_sort = sorts an array in ascending order 
* using the Shell sort algorithm and the Knuth sequence.
*
* @array: array of integers.
* @size: the size of the array.
*/

void shell_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

 	size_t gap = 1;

	if (!array || size < 2)
	return;

	while (gap < size / 3)
	gap = gap * 3 + 1;

	while (gap > 0)
	{
    for (i = gap; i < size; i++)
    {
        temp = array[i];
        j = i;

        while (j >= gap && array[j - gap] > temp)
        {
            array[j] = array[j - gap];
            j -= gap;
        }

        array[j] = temp;
    }
	print_array(array, size);
	gap = (gap - 1) / 3;
}
}
