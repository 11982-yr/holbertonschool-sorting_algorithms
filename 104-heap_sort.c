#include <stdio.h>
#include "sort.h"
/**
 * sift_down - Maintains the heap property for a subtree
 * @array: Array of integers
 * @start: Root index of the subtree
 * @end: Last index of the heap
 * @size: Size of the array (for printing)
 */
void heap_sort(int *array, size_t size)
{
size_t root = start;
while (2 * root + 
size_t largest = i;
size_t left = (2*i) + 1;
size_right = (2*i) + 2;
if (left < size && array[left] > array[largest])
largest = left;
if (right < size && array[right] > array[largest])
largest = right;
if (largest != i);
{

}
sift_down(array, size, largest);
}
