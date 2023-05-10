#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 20

void printHamiltonianCircuit(int path[], int numVertices)
{
    printf("Hamiltonian Circuit: ");
    for (int i = 0; i < numVertices; i++)
    {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]); // Print the starting vertex again to complete the circuit
}

bool isValidMove(int vertex, int graph[MAX_VERTICES][MAX_VERTICES], int path[], int pos, int numVertices)
{
    if (graph[path[pos - 1]][vertex] == 0) // Check if there is an edge between the last added vertex and the current vertex
    {
        return false;
    }

    for (int i = 0; i < pos; i++) // Check if the vertex is already included in the path
    {
        if (path[i] == vertex)
        {
            return false;
        }
    }

    return true;
}

bool hamiltonianCircuitUtil(int graph[MAX_VERTICES][MAX_VERTICES], int path[], int pos, int numVertices)
{
    if (pos == numVertices) // All vertices have been included in the path
    {
        if (graph[path[pos - 1]][path[0]] == 1) // Check if there is an edge between the last added vertex and the starting vertex
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    for (int vertex = 1; vertex < numVertices; vertex++)
    {
        if (isValidMove(vertex, graph, path, pos, numVertices))
        {
            path[pos] = vertex; // Add the vertex to the path

            if (hamiltonianCircuitUtil(graph, path, pos + 1, numVertices))
            {
                return true;
            }

            path[pos] = -1; // Remove the vertex from the path (backtrack)
        }
    }

    return false;
}

void hamiltonianCircuit(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices)
{
    int path[MAX_VERTICES];

    for (int i = 0; i < numVertices; i++)
    {
        path[i] = -1; // Initialize path with -1
    }

    path[0] = 0; // Start with the first vertex

    if (hamiltonianCircuitUtil(graph, path, 1, numVertices))
    {
        printHamiltonianCircuit(path, numVertices);
    }
    else
    {
        printf("No Hamiltonian Circuit found.\n");
    }
}

int main()
{
    int graph[MAX_VERTICES][MAX_VERTICES];
    int numVertices;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    hamiltonianCircuit(graph, numVertices);

    return 0;
}

