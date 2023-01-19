#include "lists.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: linked list head
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *aux, *dummy;
	listint_t *one_step = *head, *two_step = *head;

	if (!head || !one_step->next)
		return (1);
	dummy = malloc(sizeof(listint_t **));
	while (one_step)
	{
		if (two_step->next)
		{
			aux = malloc(sizeof(listint_t **));
			aux->next = dummy, aux->n = one_step->n;
			dummy = aux; }
		if (!two_step->next || !two_step->next->next)
		{
			aux = dummy;
			one_step = one_step->next;
			while (dummy->next && one_step->next)
			{
				if (dummy->n != one_step->n)
				{
					free_listint(aux);
					return (0); }
				dummy = dummy->next;
				one_step = one_step->next;
			}
			if (dummy->n != one_step->n)
			{
				free_listint(aux);
				return (0); }
			free_listint(aux);
			return (1);
		}
		one_step = one_step->next;
		two_step = two_step->next->next;
	}
	free_listint(dummy);
	return (0);
}
