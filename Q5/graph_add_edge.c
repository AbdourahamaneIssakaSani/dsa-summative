#include "graphs.h"

vertex_t *get_vertex(graph_t *graph, const char *str);

edge_t *create_edge(vertex_t *src_vertex, vertex_t *dest_vertex, int weight);

/**
* graph_add_edge - adds an edge between two vertices to the graph
* @graph: pointer to graph type
* @src: string value of source vertex
* @dest: string value of destination vertex
* @weight: weight of the edge
*
* Return: 1 on success, 0 on failure
*/
int graph_add_edge(graph_t *graph,
				char const *src, char const *dest, int weight)
{
	vertex_t *src_vertex, *dest_vertex;

	if (graph == NULL || src == NULL || dest == NULL)
		return (0);

	src_vertex = get_vertex(graph, src);
	dest_vertex = get_vertex(graph, dest);

	if (src_vertex == NULL || dest_vertex == NULL)
		return (0);

	if (!create_edge(src_vertex, dest_vertex, weight) ||
		!create_edge(dest_vertex, src_vertex, weight))
		return (0);

	return (1);
}

/**
* create_edge - creates an edge between two vertices
* @src_vertex: pointer to source vertex
* @dest_vertex: pointer to destination vertex
* @weight: weight of the edge
*
* Return: pointer to the created edge, NULL on failure
*/
edge_t *create_edge(vertex_t *src_vertex, vertex_t *dest_vertex, int weight)
{
	edge_t *edge = malloc(sizeof(edge_t));

	if (edge == NULL)
		return (NULL);

	edge->dest = dest_vertex;
	edge->weight = weight;
	edge->next = src_vertex->edges;
	src_vertex->edges = edge;

	return (edge);
}

/**
* get_vertex - gets a vertex from the graph
* @graph: pointer to graph type
* @str: string value of the vertex
* Return: pointer to the vertex, NULL on failure
*/
vertex_t *get_vertex(graph_t *graph, const char *str)
{
	vertex_t *vertex;

	for (vertex = graph->vertices; vertex; vertex = vertex->next)
		if (!strcmp(vertex->content, str))
			return (vertex);

	return (NULL);
}
