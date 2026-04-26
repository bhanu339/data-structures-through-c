#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Linked list node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adjList[MAX];
int visited[MAX];

// Queue for BFS
int queue[MAX];
int front = -1, rear = -1;

// Add edge (undirected graph)
void addEdge(int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

// Enqueue
void enqueue(int value) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// Check empty
int isEmpty() {
    return front > rear;
}

// BFS traversal
void BFS(int start) {
    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        struct Node* temp = adjList[current];
        while (temp != NULL) {
            int adjVertex = temp->vertex;

            if (!visited[adjVertex]) {
                enqueue(adjVertex);
                visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int vertices, edges;
    int src, dest, start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    // Initialize adjacency list
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

    printf("\nBFS Traversal: ");
    BFS(start);

    return 0;
}
