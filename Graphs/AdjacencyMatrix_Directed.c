#include <stdio.h>
#include <stdlib.h>

#define MAX 10   

typedef struct {
    int numVertices;
    int adjMatrix[MAX][MAX];
} Graph;

void initGraph(Graph *g, int vertices) {
    g->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;  
        }
    }
}

void addEdge(Graph *g, int src, int dest) {
    if (src >= 0 && src < g->numVertices && 
        dest >= 0 && dest < g->numVertices) {
        g->adjMatrix[src][dest] = 1; 
    } else {
        printf("Invalid edge: %d -> %d\n", src, dest);
    }
}

void printGraph(Graph *g) {
    printf("\nAdjacency Matrix of Directed Graph:\n");

    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph g;
    int vertices = 5;

    initGraph(&g, vertices);

    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 3, 4);
    addEdge(&g, 2, 4);
    addEdge(&g, 4, 1);

    printGraph(&g);

    return 0;
}
