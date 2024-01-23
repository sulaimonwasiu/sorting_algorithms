#include "sort.h"

/**
 * swap_nodes - swap the nodes in the list
 *
 * @list: pointer to the head of the list
 * @node1: first node pointer
 * @node2: second node pointer
 *
 * Return:  void
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (*list == NULL || node1 == NULL || node2 == NULL)
		return;

	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * insertion_sort_list - insertion sort algorithm
 *
 * @list: pointer to the list
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	if (*list == NULL || (*list)->next == NULL)
		return;

	listint_t *current = (*list)->next;

	while (current != NULL)
	{
		listint_t *insertion_pt = current->prev;
		int value = current->n;

		while (insertion_pt != NULL && insertion_pt->n > value)
		{
			swap_nodes(list, insertion_pt, current);
			print_list(*list);
			insertion_pt = current->prev;
		}
		current = current->next;
	}
}
