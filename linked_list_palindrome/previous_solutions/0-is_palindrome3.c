#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the first node of a singly linked list
 *
 * Returns: 0 if not palindrome, 1 if palindrome
 */

int is_palindrome(listint_t **head)
{
	if (head == NULL)
		return (0);
	if (*head == NULL)
		return (1);
	return (palindrome_check(*head, list_length(*head)));
}

/**
 * list_length - returns the length of a singly linked list
 * @head: pointer to the head of the list
 *
 * Returns: length of the list
 */

int list_length(listint_t *head)
{
	listint_t *mover = head;
	int size = 0;

	while(mover)
	{
		size++;
		mover = mover->next;
	}
	return (size);
}

/**
 * palindrome_check - checks if list is palindrome recursively
 * @head: single pointer to linked list
 * @count: how far deep to from head to check the end
 *
 * Returns: 0 if not palindrome, 1 if palindrome;
 */
int palindrome_check(listint_t *head, int size)
{
	listint_t *mover = head;
	int count = 0;

	if (size <= 1)
		return (1);
	for (count = 1; count < size; count++)
		mover = mover->next;
	if (head->n != mover->n)
		return (0);
	head = head->next;
	size -= 2;
	return (palindrome_check(head, size));
}
