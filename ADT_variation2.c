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

void initialize (EPtr L); //initializing the elements and count to 0
void insertPosition (EPtr L, int pos, int data); //inserting data into desired position
void insertSorted (EPtr L, int data); //inserting data in a sorted manner, assuming the list is sorted
void deletePosition(EPtr L, int position); //shifting the elements to the left to fill in the position
int locate (EPtr L, int data); //looping thru the array and returns the position if data is found, otherwise return -1
int retrieve (EPtr L, int position); //looping thru the array and returns the element on that given position
void display(EPtr L);//displaying the current data found in the list

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

    deletePosition(L, 3);
    printf("List after deleting data:\n");
    display(L);

    int found = locate(L, 1);
    if(found != -1){
        printf("Data found in position %d\n", found);
    } else {
        printf("Data not found.\n");
    }

    int element = retrieve (L, 2);
    if (element != -1){
        printf("Data found in position 2 is %d\n", element);
    } else {
        printf("Position empty.\n");
    }

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
        return;
    }

    int pos = 0;
    while (pos < L->count && L->elem[pos] < data){
        pos++;
    }

    for(int i = L->count; i > pos; i--){
        L->elem[i] = L->elem[i - 1];
    }

    L->elem[pos] = data;
    L->count++;
}

void deletePosition(EPtr L, int position){
    if(position < 0 || position > L->count){ //verifying if the position is valid
        printf("Position not found.\n");
        return;
    }

    for(int i = position; i < L->count; i++){
        L->elem[i] = L->elem[i + 1];
    }
    L->count--;
}

int locate (EPtr L, int data){
    for(int i = 0; i < L->count; i++){
        if(L->elem[i] == data){
            return i;
        }
    }
    return -1;
}

int retrieve (EPtr L, int position){
    if(position < 0 || position >= L->count){
        return -1;
    }
    return L->elem[position];
}

void display (EPtr L){
    printf("[ ");
    for(int i = 0; i < L->count; i++){
        printf("%d", L->elem[i]); 
        if(i < L->count - 1){
            printf(", ");
        }
    }
    printf(" ]\n");
    printf("Total Count: %d\n\n", L->count); //displays the total count in the list
}