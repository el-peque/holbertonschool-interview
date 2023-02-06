#include "palindrome.h"
#include <stdio.h>

/**
 * is_palindrome - checks if a given unsigned integer is a palindrome
 * @n: number to be checked
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long int i = 10, j, reverse_n = 0;

	while ((n / i) > 0)
		i *= 10;

	reverse_n = (i / 10) * (n % 10);
	j = i / 100;
	i = 10;
	while ((n / i) > 0)
	{
		reverse_n += j * ((n / i) % 10);
		j /= 10;
		i *= 10;
	}
	return (n == reverse_n);
}
