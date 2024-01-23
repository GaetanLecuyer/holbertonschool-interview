#ifndef LISTS_H
#define LISTS_H

/* INCLUDED LIBRARIES */
#include <stdio.h>
#include <stdlib.h>

/* STRUCTS AND DEFINITIONS */

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;


/* FUNCTION PROTOTYPES */

/* given function to print the singly linked list in order */
size_t print_listint(const listint_t *h);
/* given function to add node to the end of singly linked list */
listint_t *add_nodeint_end(listint_t **head, const int n);
/* given function to delete and free a singly linked list */
void free_listint(listint_t *head);

/* function to insert number into sorted singly linked list */
listint_t *insert_node(listint_t **head, int number);

#endif /* LISTS_H */
