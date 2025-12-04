#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

typedef struct {
    int numVertices;
    int adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

void initGraph(Graph *g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adj[i][j] = 0; 
        }
    }
}

void addEdge(Graph *g, int src, int dest) {
    if (src >= g->numVertices || dest >= g->numVertices) {
        printf("Invalid edge (%d, %d)\n", src, dest);
        return;
    }

    g->adj[src][dest] = 1;
    g->adj[dest][src] = 1; 
}

void printGraph(Graph *g) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

void BFS(Graph *g, int start) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES], front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS starting from %d: ", start);

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < g->numVertices; i++) {
            if (g->adj[node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void DFSUtil(Graph *g, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < g->numVertices; i++) {
        if (g->adj[v][i] == 1 && !visited[i]) {
            DFSUtil(g, i, visited);
        }
    }
}

void DFS(Graph *g, int start) {
    int visited[MAX_VERTICES] = {0};

    printf("\nDFS starting from %d: ", start);
    DFSUtil(g, start, visited);
    printf("\n");
}

int main() {
    Graph g;
    int vertices = 5;

    initGraph(&g, vertices);

    addEdge(&g, 0, 1);
    addEdge(&g, 0, 4);
    addEdge(&g, 1, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 4);

    printGraph(&g);

    BFS(&g, 0);
    DFS(&g, 0);

    return 0;
}
