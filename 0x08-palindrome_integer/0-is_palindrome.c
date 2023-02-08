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
	unsigned long int num = n, reverse_n = 0;

	while (n > 0)
	{
		reverse_n *= 10;
		reverse_n += (n % 10);
		n /= 10;
	}
	return (num == reverse_n);
}
