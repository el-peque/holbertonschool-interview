#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: head of linked list
 *
 * Return: address of the node where the loop starts,
 *         or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *forward = head, *forward_two_steps = head;

	if (!head)
		return (NULL);

	while (forward && forward_two_steps)
	{
		if (forward->n == forward_two_steps->n)
			return (forward);
	}

	return (NULL);
}
