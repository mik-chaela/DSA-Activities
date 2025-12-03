#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int elem;
    struct node* LC;
    struct node* RC;
} Node, *BST;

void insert (BST* T, int value) {
    BST* trav;
    
    for(trav = T; *trav != NULL && (*trav)->elem != value;){
        trav = ((*trav)->elem > value) ? &(*trav)->LC : &(*trav)->RC;
    }
    
    if(*trav == NULL){
        *trav = (BST)calloc(1, sizeof(Node));
        (*trav)->elem = value;
    }
}

void inorder (BST B){
    if(B != NULL){
        inorder(B->LC);
        printf("%d ", B->elem);
        inorder(B->RC);
    }
}

int main(){
    BST Tree = NULL;
    
    insert (&Tree, 50);
    insert (&Tree, 20);
    insert (&Tree, 13);
    insert (&Tree, 75);
    insert (&Tree, 12);
    
    inorder(Tree);
    return 0;
}
