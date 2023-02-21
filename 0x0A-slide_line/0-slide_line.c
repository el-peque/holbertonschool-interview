#include "slide_line.h"
#include <stddef.h>

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
	size_t i = 0;
	int change = 0;
	int changes[size];

	fill_zeroes(changes, size);
	while (direction == SLIDE_RIGHT)
	{
		change = 0;
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
		if (change == 0)
			return (1);
	}
	while (direction == SLIDE_LEFT)
	{
		change = 0;
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
		if (change == 0)
			return (1);
	}
	return (0);
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
