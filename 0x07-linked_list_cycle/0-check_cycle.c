#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: pointer to head of list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *dummy = list;

	if (!list)
		return (0);
	if (!list->next)
		return (1);
	while (dummy->next)
	{
		dummy = dummy->next;
		if (dummy == list)
			return (1);
	}

	return (0);
}
