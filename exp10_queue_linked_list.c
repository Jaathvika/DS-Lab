// Experiment 27: Implementation of Depth First Search (DFS)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int vertices;

void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1; // undirected
}

void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < vertices; i++) {
        if (adj[v][i] && !visited[i]) {
            DFS(i);
        }
    }
}

// Iterative DFS using stack
void DFS_iterative(int start) {
    int stack[MAX], top = -1;
    memset(visited, 0, sizeof(visited));
    stack[++top] = start;
    printf("DFS (iterative) starting from vertex %d: ", start);
    while (top != -1) {
        int v = stack[top--];
        if (!visited[v]) {
            visited[v] = 1;
            printf("%d ", v);
            for (int i = vertices - 1; i >= 0; i--) {
                if (adj[v][i] && !visited[i])
                    stack[++top] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    int edges, u, v, start;
    printf("=== Depth First Search (DFS) ===\n");
    printf("Enter number of vertices: "); scanf("%d", &vertices);
    printf("Enter number of edges: "); scanf("%d", &edges);

    memset(adj, 0, sizeof(adj));
    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter starting vertex: "); scanf("%d", &start);

    // Recursive DFS
    memset(visited, 0, sizeof(visited));
    printf("DFS (recursive) starting from vertex %d: ", start);
    DFS(start);
    printf("\n");

    // Iterative DFS
    DFS_iterative(start);

    return 0;
}
