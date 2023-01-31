#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: pointer to head of list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *one_step = list, *two_step = list;

	while (two_step->next->next)
	{
		two_step = two_step->next->next;
		one_step = one_step->next;
		if (one_step == two_step)
			return (1);
	}

	return (0);
}
