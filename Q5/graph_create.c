#include "graphs.h"

/**
* graph_create - Create a new graph
*
* Return: Pointer to the new graph
*/
graph_t *graph_create(void)
{
	graph_t *new_graph = malloc(sizeof(graph_t));

	if (new_graph == NULL)
		return (NULL);

	new_graph->nb_vertices = 0;
	new_graph->vertices = NULL;

	return (new_graph);
}
