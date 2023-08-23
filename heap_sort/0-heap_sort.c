#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending order using
 *             the Heap sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	size_t i = 0;

	for (i = size / 2 - 1; i >= 0; i--)
	{
		heapify(array, size, i, size);
	}

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}

/**
 * swap - swaps two integers
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - turns an array into a max heap
 * @array: array to heapify
 * @size: size of the heap
 * @index: index to start heapifying from
 * @full_size: full size of the array for printing
 */
void heapify(int *array, size_t size, size_t index, size_t full_size)
{
	size_t largest = index;
	size_t left = 2 * index + 1;
	size_t right = 2 * index + 2;

	if (left < size && array[left] > array[largest])
	{
		largest = left;
	}

	if (right < size && array[right] > array[largest])
	{
		largest = right;
	}

	if (largest != index)
	{
		swap(&array[index], &array[largest]);
		print_array(array, full_size);
		heapify(array, size, largest, full_size);
	}
}
