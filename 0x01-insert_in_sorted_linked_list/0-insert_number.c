#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: head
 * @number: number
 * Return: address of the new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *aux = *head;
	listint_t *new_head;

	if (!aux)
		return (NULL);

	new_head = malloc(sizeof(listint_t *));
	new_head->n = number;
	if (aux->n > number)
	{
		new_head->next = aux;
		*head = new_head;
		return (new_head);
	}
	while (aux->next)
	{
		if (aux->next->n > number)
			break;
		aux = aux->next;
	}

	new_head = malloc(sizeof(listint_t *));
	new_head->n = number;
	new_head->next = aux->next;
	aux->next = new_head;

	return (new_head);
}
