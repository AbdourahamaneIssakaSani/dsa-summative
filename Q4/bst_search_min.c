#include "binary_trees.h"

/**
* bst_search_min - search for the minimum value in a BST
* @root: pointer to the root of the BST
*
* Return: pointer to the minimum value in the BST
*/
int *bst_search_min(bst_t *root)
{
	if (root == NULL)
	{
		return (NULL);
	}

	if (root->left == NULL)
	{
		return (&root->n);
	}

	return (bst_search_min(root->left));
}
