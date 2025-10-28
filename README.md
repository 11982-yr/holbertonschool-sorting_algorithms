# Holbertonschool-sorting_algorithms
A Holberton school sorting algorithms team project

## Data Structure

For this project we have the following Functions, print_array, and print_list:
```c
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
```

```c
#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}
```

**Doubly linked list:**

```c
**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;
```

## Prototypes

```c
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
```

## Description

In this project, we will foucs on implementing and analyzing algorithms in C, and work with both arrays and doubly linked lists. This project include the follwoing task:
1. Bubble Sorts
2. Insertion Sort
3. Selection Sort
4. Quick Sort

And for each, we will write the time complexity in Big O notation for:
- Best cases
- Average cases
- Worst cases

## Example Implementation

Here's how we used the following prototype:

```c
void bubble_sort(int *array, size_t size);
```
to sort an array of integers in ascending order:

```c
#include "sort.h"

/**
* bubble_sort - sorts an array in ascending order using Bubble sort.
*
* @array: the array to sort
* @size: the size of the array
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, n = size;
	int temp;
	int swapped;

	if (array == NULL || size < 2)
	return;

	do {
	swapped = 0;

	for (i = 0; i < n - 1; i++)
	{
	if (array[i] > array[i + 1])
	{
	temp = array[i];
	array[i] = array[i + 1];
	array[i + 1] = temp;

	print_array(array, size);
	swapped = 1;
	}
}
	n--;
} while (swapped);
}
```


## Compilation

We compiled the project using the GCC compiler with the following base flags:

```c
$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 <additional_flags>
```
for each task.

Authors
```c
Thekira A. Ahmed & Yara K. Alrasheed
```
