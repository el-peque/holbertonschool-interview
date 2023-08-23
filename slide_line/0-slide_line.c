#include "slide_line.h"

/**
 * slide_line - Reproduces the 2048 game mechanics on a single horizontal line
 *
 * @line: Pointer to the line
 * @size: Number of elements in @line
 * @direction: Direction in where to move line
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	int change = 0;
	int MAX_SIZE = (int)size;
	int changes[MAX_SIZE];

	fill_zeroes(changes, MAX_SIZE);
	while (direction == SLIDE_RIGHT)
	{
		change = slide_right(line, changes, MAX_SIZE);
		if (change == 0)
			return (1);
	}
	while (direction == SLIDE_LEFT)
	{
		change = slide_left(line, changes, MAX_SIZE);
		if (change == 0)
			return (1);
	}
	return (0);
}

/**
 * slide_right - Reproduces the 2048 right move on a single horizontal line
 *
 * @line: Pointer to the line
 * @changes: Pointer to changes
 * @size: Number of elements in @line
 *
 * Return: number of changes to line
 */
int slide_right(int *line, int *changes, size_t size)
{
	int i = 0, change = 0;

	for (i = size - 1; i > 0; i--)
	{
		if (i > 0 && line[i - 1] != 0)
		{
			if (line[i] == 0)
			{
				line[i] += line[i - 1];
				line[i - 1] = 0;
				change++;
				if (changes[i - 1] == 1)
				{
					changes[i] = 1;
					changes[i - 1] = 0;
				}
			}
			else if (changes[i - 1] != 1 && line[i - 1] == line[i])
			{
				changes[i] = 1;
				changes[i - 1] = 0;
				line[i] += line[i - 1];
				line[i - 1] = 0;
				change++;
			}
		}
	}
	return (change);
}

/**
 * slide_left - Reproduces the 2048 left move on a single horizontal line
 *
 * @line: Pointer to the line
 * @changes: Pointer to changes
 * @size: Number of elements in @line
 *
 * Return: number of changes to line
 */
int slide_left(int *line, int *changes, size_t size)
{
	int change = 0;
	size_t i = 0;

	for (i = 0; i < size; i++)
	{
		if (i < size - 1 && line[i + 1] != 0)
		{
			if (line[i] == 0)
			{
				line[i] += line[i + 1];
				line[i + 1] = 0;
				change++;
				if (changes[i] == 1)
				{
					changes[i] = 1;
					changes[i + 1] = 0;
				}
			}
			else if (changes[i] != 1 && line[i + 1] == line[i])
			{
				changes[i] = 1;
				changes[i + 1] = 0;
				line[i] += line[i];
				line[i + 1] = 0;
				change++;
			}
		}
	}
	return (change);
}

/**
 * fill_zeroes - Fills an array with 0
 *
 * @array: pointer to the array to fill
 * @size: size of the array
 */
void fill_zeroes(int *array, size_t size)
{
	size_t i = 0;

	for (i = 0; i < size; i++)
	{
		array[i] = 0;
	}
}
