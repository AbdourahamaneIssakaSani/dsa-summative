#include "graphs.h"

/**
 * Compilation: gcc -o graph Q5/graph.c Q5/dijkstra_graph.c Q5/queues.c Q5/graph_create.c Q5/graph_add_vertex.c Q5/graph_add_edge.c Q5/graph_display.c
 *
 * Execution: ./graph
 */

int main(void)
{

    char src[2], dest[2];
    graph_t *router = graph_create();

    /*Creates vertices */
    graph_add_vertex(router, "A");
    graph_add_vertex(router, "B");
    graph_add_vertex(router, "C");
    graph_add_vertex(router, "D");
    graph_add_vertex(router, "E");
    graph_add_vertex(router, "F");
    graph_add_vertex(router, "G");

    /*Creates edges */
    graph_add_edge(router, "A", "B", 4);
    graph_add_edge(router, "B", "A", 4);

    graph_add_edge(router, "A", "C", 2);
    graph_add_edge(router, "C", "A", 2);

    graph_add_edge(router, "B", "D", 8);
    graph_add_edge(router, "D", "B", 8);

    graph_add_edge(router, "B", "F", 3);
    graph_add_edge(router, "F", "B", 3);

    graph_add_edge(router, "C", "D", 6);
    graph_add_edge(router, "D", "C", 6);

    graph_add_edge(router, "C", "E", 3);
    graph_add_edge(router, "E", "C", 3);

    graph_add_edge(router, "D", "F", 1);
    graph_add_edge(router, "F", "D", 1);

    graph_add_edge(router, "E", "G", 2);
    graph_add_edge(router, "G", "E", 2);

    graph_add_edge(router, "F", "G", 4);
    graph_add_edge(router, "G", "F", 4);

    graph_add_edge(router, "G", "D", 3);
    graph_add_edge(router, "D", "G", 3);

    /*Display the graph*/

    graph_display(router);
    printf("\n\n=============================\n\n");

    printf("Enter the source vertex: ");
    scanf("%s", src);
    printf("Enter the destination vertex: ");
    scanf("%s", dest);
    printf("\n\n#############################\n\n");

    vertex_t *src_vertex = get_vertex(router, src);
    vertex_t *dest_vertex = get_vertex(router, dest);

    if (src_vertex == NULL || dest_vertex == NULL)
    {
        printf("Source or destination vertex not found\n");
        return 1;
    }

    queue_t *path = dijkstra_graph(router, src_vertex, dest_vertex);

    if (path == NULL)
    {
        printf("No path found\n");
    }
    else
    {
        printf("\n\n=============================\n\n");
        printf("Shortest path: ");
        while (path->front != NULL)
        {
            printf("%s ", (char *)dequeue(path));

            if (path->front != NULL)
            {
                printf("-> ");
            }
        }
        printf("\n");
    }
    return (0);
}
