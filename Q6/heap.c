#include <stdio.h>
#include "heap.h"

/**
* Compilation: gcc -o task1 Q6/heap.c Q6/heap_create.c Q6/heap_insert.c Q6/heap_extract.c Q6/heap_delete.c Q6/print_heap.c Q6/binary_tree_node.c
*
* Execute: ./task1
*/

/**
* int_cmp - Compare two integers
* @p1: pointer to first integer
* @p2: pointer to second integer
* Return: difference between the two integers
*/
int int_cmp(void *p1, void *p2)
{
	int n1 = *((int *)p1);

	int n2 = *((int *)p2);

	return (n1 - n2);
}

/**
* main - Entry point of the program
* Return: 0 on success
*/
int main(void)
{
	heap_t *my_heap;
	int values[] = {10, 5, 15, 2, 8, 12};

	my_heap = heap_create(int_cmp);

	for (size_t i = 0; i < sizeof(values) / sizeof(values[0]); i++)
	{
		heap_insert(my_heap, &values[i]);
	}

	printf("Heap after insertion:\n");
	print_heap(my_heap);

	int node_to_delete;

	printf("Enter a node to delete: ");
	scanf("%d", &node_to_delete);

	binary_tree_node_t *node = heap_extract(my_heap);

	printf("Heap after deleting %d:\n", node_to_delete);
	print_heap(my_heap);

	heap_delete(my_heap, NULL);

	return (0);
}
