/*
Variation 3 on ADT List
- List is a DYNAMIC ARRAY and accessed by VALUE
*/

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
} List;

List initialize(List L);
List insertPosition (List L, int position, int data);
List insertSorted (List L, int data);
List deletePostion (List L, int position);
int locate (List L, int data);
List resize (List L);
void display (List L);
void makeNULL (List L);

int main(){
    List L;

    L = initialize(L);
    L = insertPosition (L, 0, 5);
    L = insertPosition (L, 1, 10);
    L = insertPosition (L, 2, 15);
    L = insertPosition (L, 3, 20);
    L = insertPosition (L, 4, 25);
    L = insertPosition (L, 5, 30);

    printf("List after inserting data into desired positions\n");
    display(L);

    L = insertSorted (L, 23);
    printf("List after inserting data in a sorted manner\n");
    display(L);

    L = deletePostion (L, 2);
    printf("List after deleting data\n");
    display(L);

    int found = locate (L, 25);
    if (found != -1){
        printf("Data is found in position %d\n", found);
    } else {
        printf("Data not found\n");
    }

    makeNULL (L);
    return 0;
}

List initialize(List L){
    L.elemPtr = (int*) malloc (LENGTH * sizeof(int));
    if (L.elemPtr == NULL){
        printf("Memory allocation failed.\n");
        exit(1);
    }

    L.max = LENGTH;
    L.count = 0;

    return L;
}

List insertPosition (List L, int position, int data){
    if (position < 0 || position > L.count){
        printf("Invalid format.\n");
        return L;
    }

    if(L.count == L.max){
        L = resize(L);
    }

    for(int i = L.count; i > position; i--){
        L.elemPtr[i] = L.elemPtr[i - 1];
    }

    L.elemPtr[position] = data;
    L.count++;

    return L;
}

List insertSorted (List L, int data){
    if (L.count == L.max){
        L = resize(L);
    }

    int pos = 0;

    while (pos < L.count && L.elemPtr[pos] < data){
        pos++;
    }

    for(int i = L.count; i > pos; i--){
        L.elemPtr[i] = L.elemPtr[i - 1];
    }

    L.elemPtr[pos] = data;
    L.count++;

    return L;
}

List deletePostion (List L, int position){
    if (position < 0 || position > L.count){
        printf("Invalid position.\n");
        return L;
    }

    for(int i = position; i < L.count; i++){
        L.elemPtr[i] = L.elemPtr[i + 1];
    }
    L.count--;

    return L;
}

int locate (List L, int data){
    for(int i = 0; i < L.count; i++){
        if(L.elemPtr[i] == data){
            return i;
        }
    }
    return -1;
}

List resize (List L)    {
    L.elemPtr = realloc(L.elemPtr, (L.max * 2) * sizeof(int));
    if(L.elemPtr == NULL){
        printf("Memory reallocation failed.\n");
        makeNULL(L);
        exit(1);
    }
    L.max *= 2;
    return L;
}

void display (List L){
    printf("[ ");
    for(int i = 0; i < L.count; i++){
        printf("%d", L.elemPtr[i]);
        if(i < L.count - 1){
            printf(", ");
        }
    }
    printf(" ]\n");
    printf("Total Count: %d\n", L.count);
    printf("Max: %d\n\n", L.max);
}

void makeNULL (List L){
    free(L.elemPtr);
}