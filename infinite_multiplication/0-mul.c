#include <stdio.h>
#include "holberton.h"

/**
 * main - Entry point for the program.
 *
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: Exits with code 98 in case of error.
 */
int main(int argc, char **argv)
{
	int num1_length = 0, num2_length = 0;

	if (!argv || argc != 3)
	{
		_print("Error\n");
		exit(98);
	}
	if (only_digits(argv[1]) == 1 || only_digits(argv[2]) == 1)
	{
		_print("Error\n");
		exit(98);
	}
	num1_length = _length(argv[1]);
	num2_length = _length(argv[2]);

	printf("");

	multiply(argv[1], argv[2], num1_length, num2_length);
}

/**
 * multiply - Multiply two large numbers represented as strings.
 *
 * @num1: The first number.
 * @num2: The second number.
 * @num1_length: The length of the first number.
 * @num2_length: The length of the second number.
 */
void multiply(char *num1, char *num2, int num1_length, int num2_length)
{
	int i, f, zero_idx = 0, mult, rest = 0, idx = 1023, sum, sum_rest = 0;
	char *result = NULL;

	result = malloc(sizeof(char) * 1024);
	fill_zero(result);

	for (i = num1_length - 1; i >= 0; i--)
	{
		int num1_digit = num1[i] - '0';

		idx = 1023 - zero_idx;
		rest = 0;

		for (f = num2_length - 1; f >= 0; f--)
		{
			int num2_digit = num2[f] - '0';

			mult = (num1_digit * num2_digit) + (result[idx] - '0') + rest;
			rest = mult / 10;
			result[idx] = (mult % 10) + '0';
			idx--;
		}
		while (rest > 0)
		{
			mult = (result[idx] - '0') + rest;
			rest = mult / 10;
			result[idx] = (mult % 10) + '0';
			idx--;
		}
		zero_idx++;
	}
	i = 0;
	while (result[i] == '0' && result[i + 1] != '\0')
		i++;

	for (i = i; result[i]; i++)
		putchar(result[i]);
	putchar('\n');

	free(result);
}

/**
 * fill_zero - Fill a string with zeros.
 *
 * @str: The string to be filled with zeros.
 */
void fill_zero(char *str)
{
	int i = 0;

	while (i < 1024)
	{
		str[i] = '0';
		i++;
	}
}

/**
 * _length - Calculate the length of a string.
 *
 * @str: The input string.
 *
 * Return: The length of the string.
 */
int _length(char *str)
{
	int i = 0;

	while (str[i])
		i++;

	return (i);
}

/**
 * _print - Print a string.
 *
 * @str: The string to be printed.
 *
 * Return: The number of characters printed.
 */
int _print(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * only_digits - Check if a string contains only digits.
 *
 * @str: The input string.
 *
 * Return: 1 if the string contains non-digit characters, 0 otherwise.
 */
int only_digits(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}
