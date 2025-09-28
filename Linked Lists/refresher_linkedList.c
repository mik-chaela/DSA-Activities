#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    char elem;
    struct node *link;
} *charList; //List datatype

bool findElem (charList L, char a);
charList createNode (char ch);

int main () {
    charList L = NULL;

    //manual creation of three nodes
    L = createNode ('U');
    L->link = createNode('S');
    L->link->link = createNode('C');

    printf("Test A: List is empty\n");
    charList emptyList = NULL;
    printf("Find 'U': %s\n\n", findElem(emptyList, 'U') ? "true" : "false");

    printf("Test B: Element IS IN the list\n");
    printf("Find 'S': %s\n\n", findElem(L, 'S') ? "true" : "false");

    printf("Test C: Element IS NOT in the list\n");
    printf("Find 'A': %s\n\n", findElem(L, 'A') ? "true" : "false");
}

charList createNode (char ch){
    charList newNode = (charList) malloc (sizeof (struct node));
    
    newNode->elem = ch;
    newNode->link = NULL;

    return newNode;
}

bool findElem (charList L, char a){
    bool found = false;

    while (L != NULL){
        if (L->elem == a){
            found = true;
        }
        L = L->link;
    }
    
    return found;
}