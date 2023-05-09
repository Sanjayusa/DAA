#include <stdio.h>

#define INF 9999 // infinite value

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0) {
                graph[i][j] = INF; // set the value to infinity if no edge exists
            }
        }
    }

    // perform Floyd's algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j]; // update the shortest distance
                }
            }
        }
    }

    // print the final distance matrix
    printf("The shortest distances between all pairs of vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == INF) {
                printf("INF ");
            } else {
                printf("%d   ", graph[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}

