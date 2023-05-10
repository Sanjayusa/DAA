#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

bool isSafe(int vertex, int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int colors[MAX_VERTICES], int color)
{
    for (int i = 0; i < vertices; i++)
    {
        if (graph[vertex][i] && colors[i] == color)
        {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int colors[MAX_VERTICES], int numColors, int vertex)
{
    if (vertex == vertices)
    {
        return true; // All vertices have been assigned a color
    }

    for (int color = 1; color <= numColors; color++)
    {
        if (isSafe(vertex, graph, vertices, colors, color))
        {
            colors[vertex] = color;

            if (graphColoringUtil(graph, vertices, colors, numColors, vertex + 1))
            {
                return true;
            }

            colors[vertex] = 0; // backtrack and try with a different color
        }
    }

    return false;
}

bool graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int numColors)
{
    int colors[MAX_VERTICES] = {0}; // Initialize colors for all vertices as 0

    if (graphColoringUtil(graph, vertices, colors, numColors, 0))
    {
        printf("Graph can be colored using at most %d colors:\n", numColors);
        for (int i = 0; i < vertices; i++)
        {
            printf("Vertex %d -> Color %d\n", i + 1, colors[i]);
        }
        return true;
    }
    else
    {
        printf("Graph cannot be colored using %d colors.\n", numColors);
        return false;
    }
}

int main()
{
    int graph[MAX_VERTICES][MAX_VERTICES];
    int vertices, edges, numColors;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (vertex1 vertex2):\n");
    for (int i = 0; i < edges; i++)
    {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1 - 1][v2 - 1] = 1;
        graph[v2 - 1][v1 - 1] = 1;
    }

    printf("Enter the number of colors: ");
    scanf("%d", &numColors);

    graphColoring(graph, vertices, numColors);

    return 0;
}

