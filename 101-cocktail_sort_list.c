#include "sort.h"

/**
 * cocktail_sort_list - short description
 *
 * Description: long description
 *
 * @list: argument_1 description
 *
 * Return: return description
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *head, *previous, *tail;
	int swap = 1, direction = 1;

	if (list == NULL)
		return;
	if ((*list) == NULL || (*list)->next == NULL)
		return;
	head = *list;
	tail = NULL;
	while (swap)
	{
		swap = 0;
		if (direction == 1)
		{
			previous = head;
			current = head->next;
		}
		else
		{
			previous = tail;
			current = tail->prev;
		}
		while (current)
		{
			if (direction == 1 && current->n < previous->n)
			{
				if (current->next == NULL)
					tail = previous;
				if (previous->prev == NULL)
					head = current;
				if (current->next != NULL)
					current->next->prev = previous;
				if (previous->prev != NULL)
					previous->prev->next = current;
				current->prev = previous->prev;
				previous->next = current->next;
				current->next = previous;
				previous->prev = current;
				swap = 1;
				current = previous;
				previous = current->prev;
				print_list(head);
			}
			if (direction == 0 && current->n > previous->n)
			{
				if (current->prev == NULL)
					head = previous;
				if (previous->next == NULL)
					tail = current;
				if (current->prev != NULL)
					current->prev->next = previous;
				if (previous->next != NULL)
					previous->next->prev = current;
				current->next = previous->next;
				previous->prev = current->prev;
				current->prev = previous;
				previous->next = current;
				swap = 1;
				current = previous;
				previous = current->next;
				print_list(head);
			}
			previous = current;
			if (direction == 1)
				current = current->next;
			else
				current = current->prev;
		}
		direction = !direction;
	}
	*list = head;
}
