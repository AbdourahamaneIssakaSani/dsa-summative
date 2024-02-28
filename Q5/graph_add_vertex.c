#include "graphs.h"

/**
* graph_add_vertex - Add a vertex in a graph
*
* @graph: Pointer to the graph data structure
* @str: String representing the new vertex
*
* Return: A pointer to the created vertex, NULL on failure
*/
vertex_t *graph_add_vertex(graph_t *graph, char const *str)
{
	vertex_t *new_vertex = malloc(sizeof(vertex_t));

	if (new_vertex == NULL)
		return (NULL);

	new_vertex->content = strdup(str);
	if (new_vertex->content == NULL)
	{
		free(new_vertex);
		return (NULL);
	}

	new_vertex->index = graph->nb_vertices++;
	new_vertex->edges = NULL;
	new_vertex->next = graph->vertices;
	graph->vertices = new_vertex;

	return (new_vertex);
}
