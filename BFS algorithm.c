#include <stdio.h>

int queue[100], front = -1, rear = -1;
int visited[100];

// Enqueue function
void enqueue(int value) {
    if(rear == 99)
        printf("Queue is Full\n");
    else {
        if(front == -1)
            front = 0;
        queue[++rear] = value;
    }
}

// Dequeue function
int dequeue() {
    return queue[front++];
}

// BFS function
void BFS(int graph[100][100], int start, int n) {
    int i, current;

    enqueue(start);
    visited[start] = 1;

    while(front <= rear) {
        current = dequeue();
        printf("%d ", current);

        for(i = 0; i < n; i++) {
            if(graph[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[100][100];

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

    printf("\nBFS Traversal: ");
    BFS(graph, start, n);

    return 0;
}
