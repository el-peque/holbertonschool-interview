#include "slide_line.h"

int slide_right(int *line, int *changes, size_t size);
int slide_left(int *line, int *changes, size_t size);
void fill_zeroes(int *array, size_t size);

int slide_line(int *line, size_t size, int direction)
{
	int change = 0;
	int changes[size];

	fill_zeroes(changes, size);
	while (direction == SLIDE_RIGHT)
	{
		change = slide_right(line, changes, size);
		if (change == 0)
			return (1);
	}
	while (direction == SLIDE_LEFT)
	{
		change = slide_left(line, changes, size);
		if (change == 0)
			return (1);
	}
	return (0);
}
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
void fill_zeroes(int *array, size_t size)
{
	size_t i = 0;

	for (i = 0; i < size; i++)
	{
		array[i] = 0;
	}
}
