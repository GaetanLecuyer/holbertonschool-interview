#include "lists.h"

/**
 * check_cycle - determines if a singly linked list contains a cycle
 * @list: single pointer to the head of the list to check if cyclical
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
	listint_t *tortoise = NULL, *hare = NULL;

	/* if list is NULL or empty, return 0 for no cycle */
	if (list == NULL || list->next == NULL)
		return (0);
	/* set slow moving pointer to start of list */
	tortoise = list;
	/* set fast moving pointer to the next node */
	hare = list->next;
	/* ensure hare can move forward two spots without segfaulting */
	while (hare && hare->next)
	{
		/* if both pointers ever point to same node, a cycle is found */
		if (tortoise == hare)
			return (1);
		/* otherwise, slow pointer moves forward one node */
		tortoise = tortoise->next;
		/* fast pointer jumps forward two nodes */
		hare = hare->next->next;
	}
	/* if pointers match and are not NULL, indicate cycle */
	if (hare && tortoise == hare)
		return (1);
	/* return 0 if made to end of the list and did not find a match */
	return (0);
}
