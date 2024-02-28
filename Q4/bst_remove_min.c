#include "binary_trees.h"

/**
* bst_remove_min - remove the minimum value from a BST
* @root: pointer to the root of the BST
*
* Return: pointer to the root of the BST after removal
*/
bst_t *bst_remove_min(bst_t *root)
{
	bst_t *temp = NULL;

	if (root == NULL)
	{
		return (NULL);
	}

	if (root->left == NULL)
	{
		temp = root->right;
		free(root);
		return (temp);
	}

	root->left = bst_remove_min(root->left);

	return (root);
}
