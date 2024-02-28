/**
* This program creates a binary search tree
* and removes the node with the minimum file size.
*
* It uses the following functions:
* - bst_insert
* - bst_print
* - bst_remove_min
* - bst_search_min
*
* Compilation: gcc -o bst Q4/bst.c Q4/bst_insert.c Q4/bst_print.c Q4/bst_remove_min.c Q4/bst_search_min.c
*
* Execution: ./bst
*/

#include "binary_trees.h"

/**
* main - Entry point
* Return: 0 on success, error code on failure
*/
int main(void)
{
	bst_t *file_tree = NULL;

	int files[] = {20, 15, 8, 16, 4, 5, 9, 10, 13, 11,

				12, 0, 14, 17, 19, 6, 18, 3, 2, 1};

	size_t num_files = sizeof(files) / sizeof(files[0]);

	for (size_t i = 0; i < num_files; i++)
	{
		file_tree = bst_insert(file_tree, files[i]);
	}

	printf("\n\n=========================\n\n");
	printf("Original tree:\n");
	bst_print(file_tree);

	int *min_size_file = bst_search_min(file_tree);

	if (min_size_file != NULL)
	{
		printf("Minimum size file: %d kilobytes\n", *min_size_file);

		if (*min_size_file < 1)
		{
			bst_remove_min(file_tree);
			printf("Minimum size node deleted.\n");

			printf("\n\n=========================\n\n");
			printf("Tree after deletion:\n");
			bst_print(file_tree);
		}
	}
	else
	{
		printf("Tree is empty.\n");
	}

	return (0);
}
