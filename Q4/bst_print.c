#include "binary_trees.h"

/**
* bst_print - print the values in a BST
* @tree: pointer to the root of the BST
* Return: void
*/
void bst_print(const bst_t *tree)
{
	if (tree != NULL)
	{
		printf("%d\n", tree->n);
		bst_print(tree->left);
		bst_print(tree->right);
	}
}
