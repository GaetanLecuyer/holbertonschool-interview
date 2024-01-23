#include "lists.h"

/**
 * insert_node - inserts a new number as a node into sorted list
 * @head: pointer to the head of the sorted singly linked list
 * @number: number to sort and add into list as new node
 * Return: pointer to the new node, or NULL if error encountered
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new = NULL, *mover = NULL;

	/* check if not given pointer to list */
	if (head == NULL)
		return (NULL);
	/* set new as a stand alone node with number as data, next to NULL */
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;
	/* if orginally given empty list, set head to new node */
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	/* else, set mover to head of list to move until ready to insert */
	mover = *head;
	/* check if need to insert at beginning of sorted list */
	if (mover->n > number)
	{
		*head = new;
		new->next = mover;
		return (new);
	}
	/* move until at location to insert new node */
	while (mover->next != NULL && mover->next->n <= number)
		mover = mover->next;
	new->next = mover->next;
	mover->next = new;
	return (new);
}
