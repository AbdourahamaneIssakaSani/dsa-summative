#ifndef BINARY_TREES_H
#define BINARY_TREES_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>

/* Structures */
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;

	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;

} binary_tree_t, bst_t;

/**
 * struct file_node - file node
 * @file_size: size of the file
 * @left: left child
 * @right: right child
 */
typedef struct file_node
{
	int file_size;
	struct file_node *left;
	struct file_node *right;
} file_node_t;

/* Prototypes */
file_node_t *create_file_node(int file_size);
bst_t *bst_insert(bst_t *tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *bst_remove(bst_t *root, int value);

bst_t *bst_remove_min(bst_t *root);
int *bst_search_min(bst_t *root);

/* Auxiliar functions */
void bst_print(const bst_t *tree);

#endif /* BINARY_TREES_H */
