#include <stdio.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;
int visited[MAX];
int adj[MAX][MAX];
int n;

// Enqueue operation
void enqueue(int value) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}

// Dequeue operation
int dequeue() {
    return queue[front++];
}

// Check if queue is empty
int isEmpty() {
    return front > rear;
}

// BFS function
void BFS(int start) {
    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("\nBFS Traversal: ");
    BFS(start);

    return 0;
}
