#include <stdio.h>
#include <stdlib.h>

#define MAX 9
#define VISITED -1;
#define UNVISITED 100;

typedef struct node {
    int elem;
    struct node* link;
} *ptr, Node;

typedef ptr Graph [MAX];

void dfs (Graph G, int vertex, int mark[]){
    ptr trav;
    
    mark[vertex] = VISITED;
    printf("%d ", vertex);
    
    trav = G[vertex];
    
    while (trav != NULL){
        if (mark[trav->elem] == UNVISITED) {
            dfs (G, trav->elem, mark);
        }
        trav = trav->link;
    }
}

/*
void dfs (Graph G, int vertex, int mark[]){
    ptr trav;
    
    mark[vertex] = VISITED;
    printf("%d ", vertex);
    
    for(trav = G[vertex]; trav != NULL; trav = trav->link){
        if(mark[trav->elem] == UNVISITED){
            dfs(G, trav->elem, mark);
        }
    }
}
*/
