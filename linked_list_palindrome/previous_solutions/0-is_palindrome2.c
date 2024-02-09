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
	hold = backwards;
	while(mover)
	{
		if (mover->n != backwards->n)
		{
			free_list(hold);
			return (0);
		}
		mover = mover->next;
		backwards = backwards->next;
	}
	free_list(hold);
	return (1);
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


/**
 * free_list - frees a singly linked list
 * @head: pointer to beginning of list to free
 *
 */
void free_list(listint_t *head)
{
	listint_t *current;

	while(head)
	{
		current = head->next;
		free(head);
		head = current;
	}
	free(head);
}
