#include "sort.h"

/**
* swap_nodes - helper for swapping nodes.
*/

static void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
  if (left->prev)
    left->prev->next = right;
else
    *list = right;
  
  if (right->next)
    right->next->prev = left;

  right->prev = left->prev;
  left->prev = right;
  left->next = right->next;
  right->next = left;
}

/**
* insertion_sort_list - sorts a doubly linked list in ascending order using the Insertion sort
*
* @list: list of integers.
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;

  current = (*list)->next;
	while (current)
{
  insert = current;
  while (insert->prev && insert->prev->n > insert->n)
    {
    swap_nodes(list, insert->prev, insert);
  print_list(*list);
    }
current = insert->next;
}
}
