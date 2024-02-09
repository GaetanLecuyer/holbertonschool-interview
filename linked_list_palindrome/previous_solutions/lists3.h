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
/* Given function to print the list in order */
size_t print_listint(const listint_t *h);
/* Given function to add a node to the end of the list */
listint_t *add_nodeint_end(listint_t **head, const int n);
/* Given function to free a list */
void free_listint(listint_t *head);

/* Function to check if list is a palindrome */
int is_palindrome(listint_t **head);
/* Subfunction that finds length of the list */
int list_length(listint_t *head);
/* Subfunction that checks if palindrome */
int palindrome_check(listint_t *head, int size);

#endif /* LISTS_H */
