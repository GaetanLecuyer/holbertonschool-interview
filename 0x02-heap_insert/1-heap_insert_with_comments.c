#include "binary_trees.h"

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * Max Binary Heap must be complete tree with max as root node
 * @root: a double pointer to the root node of the Heap
 * @value: the value to store in the inserted node
 *
 * Return: pointer to the newly inserted node, or NULL if failed
 */

heap_t *heap_insert(heap_t **root, int value)
{
	size_t level = 0, height = 0;
	heap_t *location = NULL, *new = NULL;

	/* return if given NULL instead of valid pointer */
	if (root == NULL)
		return (NULL);
	/* if given pointer to empty max binary heap, */
	/*   create new node and set root pointer to new node */
	if (*root == NULL)
	{
		/* Create new node with binary_tree_node function */
		new = binary_tree_node(*root, value);
		/* Reset root pointer to point to new root */
		*root = new;
		return (new);
	}
	/* Determine height of max heap to move through level-by-level */
	height = binary_tree_height(*root);
	/* Move through heap using level-order travesal */
	for (level = 0; level < height; level++)
	{
		/* Use find_location to find next opening in complete tree */
		location = find_location(*root, level);
		/* if the location is not NULL, break and */
		/*   location will be used as node to insert off of */
		if (location != NULL)
			break;
	}
	/* Create and insert node with location as parent */
	new = binary_tree_node(location, value);
	/* if location had no left child, set left to new node */
	if (!location->left)
		location->left = new;
	/* Otherwise, set new node as location's right child */
	else
		location->right = new;
	/* While new is not the root node and parent's value is less than, */
	/*   keep swapping nodes until maintaining max binary heap */
	while (new->parent && new->n > new->parent->n)
	{
		/* Swap the new node with its parent to maintain max heap */
		new = swap_child(root, new);
	}
	/* return newly inserted node */
	return (new);
}

/**
 * binary_tree_height - finds the height of completed binary tree
 * since the tree is completed, talled on left side
 * @root: pointer to the root node of the tree
 *
 * Return: returns the height of the overall tree
 */
size_t binary_tree_height(heap_t *root)
{
	if (root == NULL)
		return (0);
	/* Recursively call function, adding 1 for each layer found */
	/* Using left child, since heap is a complete tree */
	return (1 + binary_tree_height(root->left));
}

/**
 * find_location - finds first location that does not have a right child
 * the location may be a leaf or only have left child
 * since level-order traversal, will find location to add for complete tree
 * @root: pointer to the root node of the tree
 * @level: keeps track of the current level in the tree
 *
 * Return: location to insert new node off of, or NULL if has two children
 */
heap_t *find_location(heap_t *root, size_t level)
{
	heap_t *location = NULL;

	/* return NULL if no root pointer */
	if (root == NULL)
		return (NULL);
	/* if first level and no right child, return root node to insert from */
	/* check for right child because initially given a complete tree - */
	/*   doesn't matter if left child, it's first spot with missing child */
	if (level == 0 && root->right == NULL)
		return (root);
	/* if first level with both children, return NULL to continue */
	else if (level == 0)
		return (NULL);
	/* recursively call function for next level with left child as root */
	location = find_location(root->left, level - 1);
	/* if recursive call found valid location, return that location */
	if (location != NULL)
		return (location);
	/* recursively call function for next level with right child as root */
	location = find_location(root->right, level - 1);
	/* return valid location or NULL to continue */
	return (location);
}

/**
 * swap_child - swaps the new node with its parent
 * @root: double pointer to the root node of the max binary heap
 * @new: recently inserted node to swap
 *
 * Return: pointer to new node after switch
 */
heap_t *swap_child(heap_t **root, heap_t *new)
{
	int left = 0;
	heap_t *temp = new->parent, *temp_r = temp->right, *temp_l = temp->left;

	/* set left flag to 1 if new is the left child */
	if (new->parent->left == new)
		left = 1;
	/* Update parent's right child to skip over new, point to new's right */
	new->parent->right = new->right;
	/* if new had right child, update its parent to point to new parent */
	if (new->right)
		new->right->parent = new->parent;
	/* Update parent's left child to skip over new, point to new's left */
	new->parent->left = new->left;
	/* if new had left child, update its parent to point to new parent */
	if (new->left)
		new->left->parent = new->parent;
	if (left)
	{
		/* if new was the left child, set new's right to be temp_r */
		/*   temp_r was previously set to parent's right child */
		new->right = temp_r;
		/* if temp_r is a node, update its parent to point to new */
		if (temp_r)
			temp_r->parent = new;
	}
	else
	{
		/* if new was the right child, set new's left to be temp_l */
		/*   temp_l was previously set to parent's left child */
		new->left = temp_l;
		/* if temp_l is a node, update its parent to point to new */
		if (temp_l)
			temp_l->parent = new;
	}
	/* Update new's parent to be the original parent's parent */
	new->parent = temp->parent;
	/* if parent node is a node, reset its child node */
	if (temp->parent)
	{
		/* check if originally parent (temp) was left child */
		if (temp->parent->left == temp)
			/* reset left child to new node */
			temp->parent->left = new;
		else
			/* otherwise reset right child to new node */
			temp->parent->right = new;
	}
	/* otherwise, reset pointer to root node to new */
	else
		*root = new;
	/* if new was left child, set left child to temp (original parent) */
	if (left)
		new->left = temp;
	/* otherwise, set right child to temp (original parent) */
	else
		new->right = temp;
	/* set temp (original parent) to point back to new as parent */
	temp->parent = new;
	/* return the newly swapped node to keep checking if max binary heap */
	return (new);
}
