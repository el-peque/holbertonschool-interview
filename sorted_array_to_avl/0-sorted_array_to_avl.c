#include "binary_trees.h"

/**
 * create_avl_tree - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @start: start index of the subarray
 * @end: end index of the subarray
 * @parent: pointer to the parent node
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *create_avl_tree(int *array, int start, int end, avl_t *parent)
{
	int mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	
	root = malloc(sizeof(avl_t));
	if (!root)
		return (NULL);

	root->n = array[mid];
	root->parent = parent;
	root->left = create_avl_tree(array, start, mid - 1, root);
	root->right = create_avl_tree(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return (NULL);

	return (create_avl_tree(array, 0, size - 1, NULL));

}



/*
	// size_t i = 0;
	// avl_t *head = NULL;

	// if (!array || size == 0)
	// 	return (NULL);

	// head = malloc(sizeof(avl_t));
	// if (!head)
	// 	return (NULL);

	// for (i = 0; i < size; i++)
	// {
	// 	if (!head->left)
	// 		head->n = array[i];
	// 	else if (!head->right)
	// 	{
	// 		head->right = malloc(sizeof(avl_t));
	// 		head->right->n = array[i];
	// 	}
	// 	else
	// 	{
	// 		head->parent->n = array[i];
	// 		head = head->parent;
	// 	}
	// }

	// return (head);
	*/
