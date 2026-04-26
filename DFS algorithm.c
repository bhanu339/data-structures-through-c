#include <stdio.h>

int visited[100];
int graph[100][100];
int n;

// DFS function (recursive)
void DFS(int vertex) {
    int i;

    printf("%d ", vertex);
    visited[vertex] = 1;

    for(i = 0; i < n; i++) {
        if(graph[vertex][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    // Initialize visited array
    for(i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");
    DFS(start);

    return 0;
}
