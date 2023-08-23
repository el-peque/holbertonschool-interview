#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct HeapNode - Represents a node in a binary heap.
 * @data: The data (integer value) stored in the node.
 * @left: Pointer to the left child node.
 * @right: Pointer to the right child node.
 *
 */
typedef struct HeapNode
{
	int data;
	struct HeapNode *left;
	struct HeapNode *right;
} heap_t;

void swap(int *a, int *b);
void heapify(int *array, size_t size, size_t index, size_t full_size);
void heap_sort(int *array, size_t size);
void print_array(const int *array, size_t size);

#endif /* SORT_H */
