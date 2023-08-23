#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers
 *
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: index where value is located
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
	{
		return (-1);
	}

	return (advanced_binary_recursive(array, 0, size - 1, value));
}

/**
 * advanced_binary_recursive - performs a recursive binary search
 *                             for a value in a sorted array
 *
 * @array: pointer to the first element of the array to search in
 * @left: left index of the current subarray
 * @right: right index of the current subarray
 * @value: value to search for
 *
 * Return: index where value is located, or -1 if not found
 */
int advanced_binary_recursive(int *array, int left, int right, int value)
{
	int mid, i;

	if (left > right)
		return (-1);

	mid = left + (right - left) / 2;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		if (i < right)
			printf("%d, ", array[i]);
		else
			printf("%d", array[i]);
	}
	printf("\n");

	if (array[mid] == value)
	{
		if (right == mid + 1)
		{
			if (array[mid - 1] == value)
				return (mid - 1);
			else
				return (mid);
		}

		if (array[mid + 1] == value)
			return (advanced_binary_recursive(array, mid, right, value));
		else if (array[mid - 1] == value)
			return (advanced_binary_recursive(array, left, mid, value));
		else
			return (mid);
	}
	else if (array[mid] < value)
	{
		return (advanced_binary_recursive(array, mid + 1, right, value));
	}
	else
	{
		return (advanced_binary_recursive(array, left, mid - 1, value));
	}
}
