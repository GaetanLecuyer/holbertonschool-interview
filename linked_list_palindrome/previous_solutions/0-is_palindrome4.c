#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the first node of a singly linked list
 *
 * Returns: 0 if not palindrome, 1 if palindrome
 */

int is_palindrome(listint_t **head)
{
	listint_t *mover = NULL, *backwards = NULL, *hold = NULL;
	int value = 1;

	if (head == NULL)
		return (0);
	if (*head == NULL)
		return (1);
	mover = *head;
	while(mover)
	{
		insert_node_beginning(&backwards, mover->n);
		mover = mover->next;
	}
	mover = *head;
	while(mover && value)
	{
		if (mover->n != backwards->n)
			value = 0;
		else
		{
			mover = mover->next;
			hold = backwards;
			backwards = backwards->next;
			free(hold);
		}
	}
	return (value);
}

/**
 * insert_node_beginning - inserts new node at beginning of list
 * @backwards: singly linked list to add to
 * @n: value to add to list
 *
 * Returns: pointer to newly created node
 */
listint_t *insert_node_beginning(listint_t **backwards, int n)
{
	listint_t *new = NULL;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = *backwards;

	*backwards = new;
	return (new);
}
