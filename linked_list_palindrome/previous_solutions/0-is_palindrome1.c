#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the first node of a singly linked list
 *
 * Returns: 0 if not palindrome, 1 if palindrome
 */

int is_palindrome(listint_t **head)
{
	int *array = NULL, size = 0, i = 0;
	listint_t *mover = NULL;

	if (head == NULL)
		return (0);
	if (*head == NULL)
		return (1);
	size = list_length(*head);
	array = malloc(sizeof(int) * size);
	if (array == NULL)
		return (0);
	mover = *head;
	for (i = 0; i < size; i++)
	{
		array[i] = mover->n;
		mover = mover->next;
	}
	for (i = 0; i < (size / 2); i++)
	{
		if (array[i] != array[size - 1 - i])
		{
			free(array);
			return (0);
		}
	}
	free(array);
	return (1);
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
