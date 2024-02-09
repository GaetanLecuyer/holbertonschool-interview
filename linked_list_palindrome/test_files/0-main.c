#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	listint_t *head, *odd;

	head = NULL;
	printf("Testing head is NULL\n");
	if (is_palindrome(NULL) == 1)
		printf("Linked list is a palindrome\n");
	else
		printf("Linked list is not a palindrome\n");
	printf("Testing *head is NULL\n");
	if (is_palindrome(&head) == 1)
		printf("Linked list is a palindrome\n");
	else
		printf("Linked list is not a palindrome\n");
	add_nodeint_end(&head, 1);
	printf("testing one element\n");
	if (is_palindrome(&head) == 1)
		printf("Linked list is a palindrome\n");
	else
		printf("Linked list is not a palindrome\n");
	add_nodeint_end(&head, 17);
	printf("testing 2 elements\n");
	if (is_palindrome(&head) == 1)
		printf("Linked list is a palindrome\n");
	else
		printf("Linked list is not a palindrome\n");
	add_nodeint_end(&head, 972);
	add_nodeint_end(&head, 50);
	add_nodeint_end(&head, 98);
	add_nodeint_end(&head, 98);
	add_nodeint_end(&head, 50);
	add_nodeint_end(&head, 972);
	add_nodeint_end(&head, 17);
	add_nodeint_end(&head, 1);
	print_listint(head);

	if (is_palindrome(&head) == 1)
		printf("Linked list is a palindrome\n");
	else
		printf("Linked list is not a palindrome\n");

	free_listint(head);

	odd = NULL;
	add_nodeint_end(&odd, 1);
	add_nodeint_end(&odd, 17);
	add_nodeint_end(&odd, 972);
	add_nodeint_end(&odd, 50);
	add_nodeint_end(&odd, 98);
	add_nodeint_end(&odd, 50);
	add_nodeint_end(&odd, 972);
	add_nodeint_end(&odd, 17);
	add_nodeint_end(&odd, 1);
	print_listint(odd);

	if (is_palindrome(&odd) == 1)
		printf("Linked list is a palindrome\n");
	else
		printf("Linked list is not a palindrome\n");

	free_listint(odd);

	return (0);
}
