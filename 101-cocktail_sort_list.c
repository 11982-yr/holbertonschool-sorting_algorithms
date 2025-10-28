#include "sort.h"

/**
* swap_nodes - helper function for swapping.
*
* @list: list of nodes.
* @left: left swap
* @right: right swap
*/

void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
	left->prev->next = right;
	else
	*list = right;

	if (right->next)
	right->next->prev = left;

	right->prev = left->prev;
	left->prev  = right;
	left->next  = right->next;
	right->next = left;
}

/**
 * forward_pass - performs a forward pass in cocktail sort.
 *
 * @list: pointer to the head of the list.
 * @current: pointer to the current node.
 *
 * Return: 1 if swaps were made, 0 otherwise.
 */

int forward_pass(listint_t **list, listint_t **current)
{
	int swapped = 0;

	while ((*current)->next)
	{
	if ((*current)->n > (*current)->next->n)
	{
		swap_nodes(list, *current, (*current)->next);
		swapped = 1;
		print_list(*list);
	}
	else
		*current = (*current)->next;
	}
	return (swapped);
}

/**
 * backward_pass - performs a backward pass in cocktail sort.
 *
 * @list: pointer to the head of the list.
 * @current: pointer to the current node.
 *
 * Return: 1 if swaps were made, 0 otherwise.
 */

int backward_pass(listint_t **list, listint_t **current)
{
	int swapped = 0;

	while ((*current)->prev)
	{
	if ((*current)->prev->n > (*current)->n)
	{
		swap_nodes(list, (*current)->prev, *current);
		swapped = 1;
		print_list(*list);
	}
	else
		*current = (*current)->prev;
	}
	return (swapped);
}
/**
* cocktail_sort_list - sorts a doubly linked list in ascending order
* using the Cocktail shaker sort algorithm
*
* @list: doubly linked list of integers.
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped;


	if (!list || !*list || !(*list)->next)
		return;

	swapped = 1;
	current = *list;

	while (swapped)
	{
		swapped = 0;

		if (forward_pass(list, &current))
			swapped = 1;

		if (!swapped)
		break;

		if (backward_pass(list, &current))
			swapped = 1;
	}
}
