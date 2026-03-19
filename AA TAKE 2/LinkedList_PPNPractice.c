#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node* link;
}*LList;

void initializeList(LList* L){
    *L = NULL;
}

void insertFirst(LList* L, char elem){
    LList newNode = malloc(sizeof(struct node));
    if(newNode != NULL){
        newNode->data = elem;
        newNode->link = *L;
        *L = newNode;
    }
}

void displayList(LList L){
    for(LList trav = L; trav != NULL; trav = trav->link){
        printf("%c ", trav->data);
    }
    printf("\n");
}

//Function Specs: Deletes a given element at first occurence.
void deleteElem(LList* L, char elem){
    LList* curr;

    for(curr = L; *curr != NULL && (*curr)->data != elem; curr = &(*curr)->link);
    if(*curr != NULL){
        LList temp = *curr;
        *curr = temp->link;
        free(temp);
    }
}

int main(){
    LList A;
    initializeList(&A);

    insertFirst(&A, 'E');
    insertFirst(&A, 'P');
    insertFirst(&A, 'O');
    insertFirst(&A, 'H');
    insertFirst(&A, 'E');
    displayList(A);

    deleteElem(&A, 'E');
    displayList(A);

    return 0;
}