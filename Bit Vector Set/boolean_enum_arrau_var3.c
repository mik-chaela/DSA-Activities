/* 
Variation 3 - Boolean/Enum Array
This implementation uses an array where the index represents the element and the value (true/false) 
represents membership.
*/

#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 8

typedef bool Set[ARRAY_SIZE];

// Initialize the set (all elements false)
void initialize(Set set) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        set[i] = false;
    }
}

// Insert an element into the set
void insert(Set set, int element) {
    if (element < 0 || element >= ARRAY_SIZE) return; 
    set[element] = true;
}

// Delete an element from the set
void delete(Set set, int element) {
    if (element < 0 || element >= ARRAY_SIZE) return; 
    set[element] = false;
}

// Find if an element is in the set
bool find(Set set, int element) {
    if (element < 0 || element >= ARRAY_SIZE) return false; 
    return set[element];
}

// Union of two sets (result in C)
void union_set(Set A, Set B, Set C) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        C[i] = A[i] || B[i];
    }
}

// Intersection of two sets (result in C)
void intersection(Set A, Set B, Set C) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        C[i] = A[i] && B[i];
    }
}

// Difference of two sets (A - B, result in C)
void difference(Set A, Set B, Set C) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        C[i] = A[i] && !B[i];
    }
}

// Display the set
void display(Set set) {
    printf("{");
    int first = 1;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (set[i]) {
            if (!first) printf(", ");
            printf("%d", i);
            first = 0;
        }
    }
    printf("} [");
    for(int i = 0; i < ARRAY_SIZE; ++i){
        printf("%d", set[i] ? 1 : 0);
        if (i != ARRAY_SIZE - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    Set A, B, C;
    initialize(A);
    initialize(B);

    insert(A, 0); 
    insert(A, 2); 
    insert(A, 7); 
    printf("A = "); display(A); 

    insert(B, 2);
    insert(B, 4); 
    insert(B, 5); 
    printf("B = "); display(B); 

    union_set(A, B, C);
    printf("A union B = "); display(C); 

    intersection(A, B, C);
    printf("A intersection B = "); display(C); 

    difference(A, B, C);
    printf("A difference B = "); display(C); 

    delete(A, 0);
    delete(A, 7);
    printf("A after deletes = "); display(A); 

    return 0;
}