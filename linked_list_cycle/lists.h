#ifndef LISTS_H
#define LISTS_H


/* INCLUDED LIBRARIES */
#include <stdlib.h>
#include <stdio.h>

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
/* given function to print the singly linked list */
size_t print_listint(const listint_t *h);
/* given function to add new node to the end of singly linked list */
listint_t *add_nodeint(listint_t **head, const int n);
/* given function to free singly linked list */
void free_listint(listint_t *head);

/* function that determines if the singly linked list contains a cycle */
int check_cycle(listint_t *list);

#endif /* LISTS_H */
