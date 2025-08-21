/*
Variation 2 on ADT List
- List is a STATIC ARRAY and accessed by POINTER
*/

#include <stdio.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} Etype, *EPtr;

void initialize (EPtr L);
void insertPosition (EPtr L, int pos, int data);
void insertSorted (EPtr L, int data);
void display(EPtr L);

int main (){
    Etype list;
    EPtr L = &list;
    
    initialize(L);
    insertPosition(L, 0, 1);
    insertPosition(L, 1, 3);
    insertPosition(L, 2, 5);
    printf("List after inserting data into desired positions:\n");
    display(L);

    insertSorted(L, 4);
    printf("List after inserting data into desired positions:\n");
    display(L);

    return 0;
}

void initialize (EPtr L){
    L->count = 0;
    for(int i = 0; i < MAX; i++){
        L->elem[i] = 0;
    }
}

void insertPosition (EPtr L, int pos, int data){
    if (pos < 0 || pos > L->count || L->count >= MAX){
        printf("Invalid Format.\n");
        return;
    }

    for(int i = L->count; i > pos; i--){
        L->elem[i] = L->elem[i - 1];
    }
    L->elem[pos] = data;
    L->count++;
}

void insertSorted (EPtr L, int data){
    if(L->count >= MAX){
        printf("List is full.\n");
    }

    
}

void display (EPtr L){
    for(int i = 0; i < L->count; i++){
        printf("Index %d: %d\n", i, L->elem[i]);
    }
    printf("Count: %d\n", L->count);
}