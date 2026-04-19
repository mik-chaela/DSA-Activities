#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char elem;
    struct node* link;
}*charList;

charList createNode (char X){
    charList newNode = (charList)malloc(sizeof(struct node));
    if(newNode != NULL){
        newNode->elem = X;
        newNode->link = NULL;
    }
    return newNode;
}

void insertFirst (charList* A, char X){
    charList newNode = createNode(X);
    newNode->link = *A;
    *A = newNode;
}

void insertLast (charList* A, char X){
    charList* trav;
    for(trav = A; *trav != NULL; trav = &(*trav)->link);
    charList new = createNode (X);
    *trav = new;
}

void insertSorted (charList* A, char letter){
    charList* ptr;
    for(ptr = A; *ptr != NULL && (*ptr)->elem < letter; ptr = &(*ptr)->link);
    charList newNode = createNode(letter);
    newNode->link = *ptr;
    *ptr = newNode;
}

void insertUnique (charList* A, char X){
    charList trav;
    for(trav = *A; trav != NULL && trav->elem != X; trav = trav->link);
    if(trav == NULL){
        charList newNode = createNode(X);
        newNode->link = *A;
        *A = newNode;
        printf("Letter is unique and is inserted FIRST of the list.\n\n");
    } else{
        printf("Found a match! Letter not inserted.\n\n");
    }
}

void insertAtPosition (charList* A, char letter, int pos){
    charList* ptr;
    int pCount = 1;
    for (ptr = A; *ptr != NULL && pCount != pos; pCount++, ptr = &(*ptr)->link);
    if(pCount == pos){
        charList newNode = createNode(letter);
        newNode->link = *ptr;
        *ptr = newNode;
    } else {
        printf(":( Invalid position. Cannot insert\n\n");
    }
}

void displayList (charList list){
    charList trav = list;
    if(trav == NULL){
        printf("List is empty.\n\n");
    } else {
        for(; trav != NULL; trav = trav->link){
            printf("%c -> ", trav->elem);
        }
        printf("NULL\n\n");
    } 
}

void freeMemory (charList* L){
    charList trav, temp;
    for(trav = *L; trav != NULL; trav = temp){
        temp = trav->link;
        free(trav);
    }
    *L = NULL;
}

int main(){
    charList L;
    L = NULL;

    int choice;

    while(1){    
        printf("Hello User! Choose which insert functionality you would like to do for today:\n");
        printf("1. Insert First\n2. Insert Last\n3. Insert Sorted\n4. Insert Unique\n5. Insert At Position\n6. Display List\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        char letter;

        switch(choice){
            case 1:
                printf("Please enter any letter to insert: ");
                scanf("%c", &letter);
                insertFirst(&L, letter);
                printf("Letter just inserted FIRST in the list.\n\n");
                break;
            case 2:
                printf("Please enter any letter to insert: ");
                scanf("%c", &letter);
                insertLast (&L, letter);
                printf("Letter just inserted LAST in the list.\n\n");
                break;
            case 3:
                printf("Please enter any letter to insert: ");
                scanf("%c", &letter);
                printf("\nAssuming that the list is sorted...\n");
                insertSorted (&L, letter);
                printf("Letter just inserted in a sorted manner in the list.\n\n");
                break;
            case 4:
                printf("Please enter any letter to insert: ");
                scanf("%c", &letter);
                insertUnique (&L, letter);
                break;
            case 5:
                int position;
                printf("Please enter any letter to insert: ");
                scanf("%c", &letter);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&L, letter, position);
                printf("Letter inserted at position %d.\n\n", position);
                break;
            case 6:
                displayList(L);
                break;
            case 7:
                freeMemory(&L);
                return 0;
            default:
                printf(":( Invalid choice. Please try again.\n\n");
                break;
        };
    }
    return 0;
}
