#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Size of the array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; ++i)
		printf("(%03d)", array[i]);
	printf("\n");
}

/**
 * binary_tree_delete - removes an entire binary tree
 * @tree: pointer to the root node of the tree to remove
 *
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	if (tree->left)
		binary_tree_delete(tree->left);
	if (tree->right)
		binary_tree_delete(tree->right);
	free(tree);
	/* tree = NULL */
}

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
	avl_t *tree;
	int array1[] = {
		1, 2, 20, 21, 22, 32, 34, 47, 62, 68,
		79, 84, 87, 91, 95, 98
	};
	size_t n1 = sizeof(array1) / sizeof(array1[0]);
	int array2[] = {
		1, 2, 20, 21, 22, 32, 34, 47, 62, 68,
		79, 84, 87
	};
	size_t n2 = sizeof(array2) / sizeof(array2[0]);

	printf("Even-sized array:\n");
	tree = sorted_array_to_avl(array1, n1);
	if (!tree)
	{
		printf("Returned NULL\n");
		return (1);
	}
	print_array(array1, n1);
	binary_tree_print(tree);
	binary_tree_delete(tree);
	tree = NULL;

	printf("Odd-sized array:\n");
	tree = sorted_array_to_avl(array2, n2);
	if (!tree)
	{
		printf("Returned NULL\n");
		return (1);
	}
	print_array(array2, n2);
	binary_tree_print(tree);
	binary_tree_delete(tree);
	tree = NULL;

	printf("Incorrect size:\n");
	tree = sorted_array_to_avl(array2, 0);
	if (!tree)
		printf("Correctly returned NULL\n");
	else
	{
		printf("Didn't return NULL\n");
		return (1);
	}

	printf("NULL array:\n");
	tree = sorted_array_to_avl((int *)NULL, n1);
	if (!tree)
		printf("Correctly returned NULL\n");
	else
	{
		printf("Didn't return NULL\n");
		return (1);
	}
	return (0);
}
