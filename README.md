# holbertonschool-sorting_algorithms
A holberton school sorting algorithms team project



Data Structure
For this project we have the following Functions, print_array, and print_list:

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


Doubly linked list:
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


Prototypes
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);


Description
In this project, we will explore at least four sorting algorithms and learn how to evaluate their time complexity using Big O notation. We will also examine how to choose the most efficient algorithm for different inputs. Special attention will be given to stable sorting algorithms, understanding what makes them stable and why stability matters in practice. By the end of the project, you will have a solid grasp of both the theoretical and practical aspects of sorting, enabling you to select the right algorithm for any scenario.

Example Implementation
Here's how we used one of the prototypes 


Compilation
We used the basic gcc compiler with the following flags:

$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89

Authors

Thekira A. Ahmed & Yara K. Alrasheed
