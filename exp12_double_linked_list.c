// Experiment 26: Implementation of Breadth First Search (BFS)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = 0, rear = 0;
int vertices;

void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1; // undirected
}

void enqueue(int v) { queue[rear++] = v; }
int dequeue() { return queue[front++]; }
int isQueueEmpty() { return front == rear; }

void BFS(int start) {
    memset(visited, 0, sizeof(visited));
    front = rear = 0;
    printf("BFS traversal starting from vertex %d: ", start);
    visited[start] = 1;
    enqueue(start);
    while (!isQueueEmpty()) {
        int v = dequeue();
        printf("%d ", v);
        for (int i = 0; i < vertices; i++) {
            if (adj[v][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

int main() {
    int edges, u, v, start;
    printf("=== Breadth First Search (BFS) ===\n");
    printf("Enter number of vertices: "); scanf("%d", &vertices);
    printf("Enter number of edges: "); scanf("%d", &edges);

    memset(adj, 0, sizeof(adj));
    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter starting vertex: "); scanf("%d", &start);
    BFS(start);

    printf("\nAdjacency Matrix:\n   ");
    for (int i = 0; i < vertices; i++) printf("%2d", i);
    printf("\n");
    for (int i = 0; i < vertices; i++) {
        printf("%2d ", i);
        for (int j = 0; j < vertices; j++) printf("%2d", adj[i][j]);
        printf("\n");
    }

    return 0;
}
