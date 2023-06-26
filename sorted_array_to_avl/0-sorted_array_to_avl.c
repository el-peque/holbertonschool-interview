#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	size_t i = 0;
	avl_t *head = NULL;

	if (!array || size == 0)
		return (NULL);

	head = malloc(sizeof(avl_t));
	if (!head)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (!head->left)
			head->n = array[i];
		else if (!head->right)
		{
			head->right = malloc(sizeof(avl_t));
			head->right->n = array[i];
		}
		else
		{
			head->parent->n = array[i];
			head = head->parent;
		}
	}

	return (head);
}
