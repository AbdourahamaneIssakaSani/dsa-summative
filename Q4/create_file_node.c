#include "binary_trees.h"

/**
* create_file_node - create a new file node
* @file_size: size of the file
*
* Return: pointer to the new file node
*/
file_node_t *create_file_node(int file_size)
{
	file_node_t *new_node = malloc(sizeof(file_node_t));

	if (new_node == NULL)
	{
		printf("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	new_node->file_size = file_size;
	new_node->left = new_node->right = NULL;

	return (new_node);
}
