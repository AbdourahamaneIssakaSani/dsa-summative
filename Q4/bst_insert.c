#include "binary_trees.h"

/**
 * bst_insert - insert a value into a BST
 * @tree: pointer to the root of the BST
 * @value: value to insert
 *
 * Return: pointer to the root of the BST after insertion
 */
bst_t *bst_insert(bst_t *tree, int value)
{
	bst_t *new_node = NULL;

	if (tree == NULL)
	{
		new_node = (bst_t *)malloc(sizeof(bst_t));
		if (new_node == NULL)
			return (NULL);
		new_node->n = value;
		new_node->left = NULL;
		new_node->right = NULL;
		return (new_node);
	}
	if (value < tree->n)
	{
		tree->left = bst_insert(tree->left, value);
	}
	else if (value > tree->n)
	{
		tree->right = bst_insert(tree->right, value);
	}
	return (tree);
}
