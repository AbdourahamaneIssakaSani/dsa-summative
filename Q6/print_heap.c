#include "heap.h"

void print_heap_helper(binary_tree_node_t *node);

/**
* print_heap - Print the heap
* @heap: pointer to the heap
*/
void print_heap(heap_t *heap)
{
	if (heap == NULL || heap->root == NULL)
	{
		printf("Heap is empty.\n");
		return;
	}

	printf("Heap nodes (in-order): ");
	print_heap_helper(heap->root);
	printf("\n");
}

/**
* print_heap_helper - Print the heap
* @node: pointer to the heap node
*/
void print_heap_helper(binary_tree_node_t *node)
{
	if (node != NULL)
	{
		print_heap_helper(node->left);
		printf("%d ", *((int *)node->data));
		print_heap_helper(node->right);
	}
}
