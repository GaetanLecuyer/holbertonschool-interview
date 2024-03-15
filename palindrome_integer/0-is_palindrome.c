#include "palindrome.h"

/**
 * is_palindrome - checks if given unsigned int is a palindrome
 * @n: unsigned long int to check if palindrome
 *
 * Return: returns 1 if palindrome, 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long original = n, reverse = 0;
	int last = 0;

	while (n != 0)
	{
		/* find the value of the last digit */
		last = n % 10;
		/* store the value in a reverse number */
		/* multiply by ten to increase the digit count of reverse */
		reverse *= 10;
		/* add the last digit to reverse */
		reverse += last;
		/* cut off the last digit so the new last digit is next digit */
		n /= 10;
	}
	/* check if original number and calculated reverse are the same */
	if (original == reverse)
		return (1);
	return (0);
}
