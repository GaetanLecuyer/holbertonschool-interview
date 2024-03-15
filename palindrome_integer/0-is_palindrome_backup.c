#include "palindrome.h"

/**
 * is_palindrome - checks if given unsigned int is a palindrome
 * @n: unsigned long int to check if palindrome
 *
 * Return: returns 1 if palindrome, 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	int digit[1] = {0};

	return palindrome_check(&n, digit);
}

/**
 * palindrome_check - checks if unsigned long int is a palindrome recursively
 * @n: pointer to number to check if palindrome
 * @digit: pointer to keep track of digit count;
 * used to find power of 10 to isolate digit
 *
 * Return: 1 if palindrome, 0 if not
 */
int palindrome_check(unsigned long *n, int *digit)
{
	if ((*digit) < 20 && (*n) / (power_of_ten((*digit) + 1)) != 0)
	{
		(*digit) += 1;
		if (palindrome_check(n, digit))
		{
			(*n) %= (power_of_ten(*digit));
			(*n) /= 10;
			(*digit) -= 2;
		}
		else
			return (0);
	}
	if (((*n) / power_of_ten(*digit)) == (*n) % 10)
		return (1);
	return (0);
}

/**
 * power_of_ten - finds 10 raised to the power of digit
 * used to determine the place value of the digit
 *
 * @digit: number to raise 10 to the power of; count of digit
 *
 * Return: unsigned int representing the digit place value
 */

unsigned long power_of_ten(int digit)
{
	unsigned long value = 1;

	if (digit < 1)
		return (value);
	while (digit)
	{
		value *= 10;
		digit--;
	}
	return (value);
}
