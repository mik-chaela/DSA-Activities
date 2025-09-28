/*
Variation 4 on ADT List
- List is a DYNAMIC ARRAY and accessed by POINTER
*/

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

typedef struct {
    int elem;
} studtype;

typedef struct {
    studtype *elemPtr;
    int count;
    int max;
} List;

void initialize (List *L);
void insertPosition (List *L, int data, int position);
void insertSorted (List *L, int data);
void deletePosition (List *L, int position);
int locate (List *L, int data);
int retrieve (List *L, int position);
void resize (List *L);
void display (List* L);
void makeNULL (List *L);

int main (){
    List *L = (List*) malloc(sizeof(List));
    initialize(L);

    insertPosition(L, 10, 0);
    insertPosition(L, 14, 1);
    insertPosition(L, 16, 2);
    printf("List after inserting data into desired position:\n");
    display(L);

    insertSorted(L, 12);
    insertSorted(L, 13);
    insertSorted(L, 15);
    printf("List after inserting data in a sorted manner:\n");
    display(L);

    deletePosition(L, 1);
    printf("List after deleting data:\n");
    display(L);

    printf("Data found?\n");
    int find = locate (L, 13);
    if (find != -1){
        printf("Yes. Data found in position %d\n", find);
    } else {
        printf("No. Data not found on the list\n");
    }

    int position = retrieve(L, 3);
    if (position == -1){
        printf("Position is empty.\n");
    }
    printf("Element in that position is: %d\n", position);

    makeNULL(L);

    return 0;
}

void initialize (List *L){
    L->count = 0;
    L->max = LENGTH;

    L->elemPtr = (studtype*) malloc (LENGTH * sizeof(studtype));
    if(L->elemPtr == NULL){
        printf("Memory allocation failed.\n");
        exit(1);
    }
}

void insertPosition (List *L, int data, int position){
    if(position < 0 || position > L->count){
        printf("Position is in invalid format.\n");
        exit(1);
    }

    if(L->count == L->max){
        resize (L);
    }

    for (int i = L->count; i > position; i--){
        L->elemPtr[i] = L->elemPtr[i - 1];
    }

    L->elemPtr[position].elem = data;
    L->count++; 
}

void insertSorted (List *L, int data){
    if (L->count == L->max){
        resize(L);
    }

    int pos = 0;

    while (pos < L->count && L->elemPtr[pos].elem < data){
        pos++;
    }

    for (int i = L->count; i > pos; i--){
        L->elemPtr[i] = L->elemPtr[i - 1];
    }

    L->elemPtr[pos].elem = data;
    L->count++;
}

void deletePosition (List *L, int position){
    if (position < 0 || position > L->count){
        printf("Invalid position.\n");
    }

    for (int i = position; i < L->count; i++){
        L->elemPtr[i] = L->elemPtr[i + 1];
    }
    L->count--;
}

int locate (List *L, int data){
    for (int i = 0; i < L->count; i++){
        if (L->elemPtr[i].elem == data){
            return i;
        }
    }
    return -1;
}

int retrieve (List *L, int position){
    if (position < 0 || position > L->count){
        printf("Position invalid.\n");
    }
    
    for(int i = position; i < L->count; i++){
        return L->elemPtr[i].elem;
    }

    return -1;
}

void resize (List *L){
    L->elemPtr = realloc(L->elemPtr, (L->max * 2) * sizeof(studtype));
    if(L->elemPtr == NULL){
        printf("Memory reallocation failed.\n");
        exit(1);
    }
    L->max *= 2;
}

void makeNULL (List *L){
    free(L->elemPtr);
    free(L);
}

void display (List* L){
    printf("[ ");
    for(int i = 0; i < L->count; i++){
        printf("%d", L->elemPtr[i].elem); 
        if(i < L->count - 1){
            printf(", ");
        }
    }
    printf(" ]\n");
    printf("Total Count: %d\n", L->count);
    printf("Max: %d\n\n", L->max);
}