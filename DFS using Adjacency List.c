#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Node structure for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adjList[MAX];
int visited[MAX];

// Add edge (undirected graph)
void addEdge(int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

// DFS function (Recursive)
void DFS(int vertex) {
    struct Node* temp;

    visited[vertex] = 1;
    printf("%d ", vertex);

    temp = adjList[vertex];

    while (temp != NULL) {
        int adjVertex = temp->vertex;

        if (visited[adjVertex] == 0) {
            DFS(adjVertex);
        }
        temp = temp->next;
    }
}

int main() {
    int vertices, edges;
    int src, dest, start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    // Initialize adjacency list and visited array
    for (int i = 0; i < vertices; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);

        // Undirected graph
        addEdge(src, dest);
        addEdge(dest, src);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("\nDFS Traversal: ");
    DFS(start);

    return 0;
}
