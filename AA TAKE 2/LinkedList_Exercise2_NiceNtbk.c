#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    char elem;
    struct node* link;
} *charList;

void populateList (charList *L, char newElem){
    charList newNode = malloc (sizeof (struct node));
    
    if (newNode != NULL){
        newNode->elem = newElem;
        newNode->link = *L;
        *L = newNode;
    }
}

bool findElem (charList L, char X) {
    charList curr = L;
    bool found = false;

    while(curr != NULL && !found){
        if(curr->elem == X){
            found = true;
        }
        curr = curr->link;
    }
    return found;
}

void deleteElem (charList* L, char X){
    charList curr = *L;
    charList prev = NULL;
    int removed = 0;

    if(*L == NULL){ //If list is empty
        printf("List is empty.\n"); 
    }

    while (curr != NULL && !removed){
        if (curr->elem == X){ //if element is first in the list
            if (curr == *L) {
                *L = curr->link;
            } else {
                prev->link = curr->link;
            }
            free (curr);
            removed = 1;
        } else {
            prev = curr;
            curr = curr->link;
        }
    }

    if (!removed && *L != NULL){
        printf("Element '%c' is not in the list.\n\n", X);
    }
}

void deleteAllOccur (charList* L, char X){
    charList curr = *L;
    charList prev = NULL;
    int found = 0;

    if (*L == NULL) {
        printf("List is empty.\n");
    }

    while (curr != NULL){
        if(curr->elem == X){
            if(curr == *L){
                *L = curr->link;
                free(curr);
                curr = *L; 
            } else {
                prev->link = curr->link;
                free(curr);
                curr = prev->link;  
            }
            found = 1;
        } else {
            prev = curr;
            curr = curr->link;
        }
    }
    
    if (!found && *L != NULL){  
        printf("Element '%c' is not in the list.\n\n", X);
    }
}

void printList (charList L){
    charList temp = L;
    while (temp != NULL){
        printf("%c -> ", temp->elem);
        temp = temp->link;
    }
    printf("NULL\n\n");
}

int main() {
    charList L = NULL;
    char X = 'X';
    
    populateList (&L, 'S');
    populateList (&L, 'D');
    populateList(&L, 'A');
    populateList(&L, 'B');
    populateList (&L, 'D');
    printf("Initial List\n");
    printList(L);
    
    bool found = findElem (L, X);
    printf("%s", found ? "true\n\n" : "false\n\n");
    
    deleteElem (&L, X);
    printf("After Delete Elem\n");
    printList(L);
    
    deleteAllOccur (&L, X);
    printf("After All Occur\n");
    printList(L);
    
    return 0;
}