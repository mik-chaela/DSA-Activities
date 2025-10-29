/* 
Variation 1 - Bitmask (char holding int value)
This is the most common and space efficient way to implement a bit vector set. An unsigned char 
(or int) is used, and elements are added by setting the corresponding bit using the bitwise OR operator
*/
#include <stdio.h>
#include <stdbool.h>

#define SET_SIZE 8

void initialize (unsigned char* set);
void insert (unsigned char* set, int element);
void delete (unsigned char* set, int element);
bool find (unsigned char set, int element);
unsigned char union_set(unsigned char A, unsigned char B);
unsigned char intersection (unsigned char A, unsigned char B);
unsigned char difference (unsigned char A, unsigned char B);
void display (unsigned char set);

int main() {
    unsigned char A, B, C;
    initialize(&A);
    initialize(&B);

    insert(&A, 1); 
    printf("A = "); display(A);
    insert(&A, 6); 
    printf("A = "); display(A);

    insert(&B, 3);
    insert(&B, 6);
    insert(&B, 7);
    printf("B = "); display(B);

    delete(&A, 6);
    printf("A after delete 6 = "); display(A);
    delete(&A, 1); 
    printf("A after delete 1 = "); display(A);

    printf("Find 1 in A: %s\n", find(A, 1) ? "Yes" : "No");
    printf("Find 6 in A: %s\n", find(A, 6) ? "Yes" : "No");

    A = 66; 
    B = 200; 
    C = union_set(A, B); 
    printf("Union of A and B = "); display(C);

    C = intersection(A, B); 
    printf("Intersection of A and B = "); display(C);

    C = difference(A, B);
    printf("Difference of A and B = "); display(C);

    return 0;
}

 //initializing the set to be empty
void initialize (unsigned char* set){
    *set = 0;
}

//inserting an element (set the bit at 'element')
void insert (unsigned char* set, int element){
    if (element < 0 || element >= SET_SIZE) return;
    unsigned char mask = 1 << element;
    *set |= mask;
}

//deleting an element (clear the bit at 'element')
void delete (unsigned char* set, int element){
    if(element < 0 || element >= SET_SIZE) return;
    unsigned char mask = 1 << element;
    mask = ~mask;
    *set &= mask;
}

//Find if an element is in the set
bool find (unsigned char set, int element){
    if(element < 0 || element >= SET_SIZE) return false;
    unsigned char mask = 1 << element;
    return (set & mask) != 0;
}

//union of two sets
unsigned char union_set(unsigned char A, unsigned char B){
    return A | B;
}

//Intersection of two sets
unsigned char intersection (unsigned char A, unsigned char B){
    return A & B;
}

//Difference of two sets 
unsigned char difference (unsigned char A, unsigned char B){
    return A & (~B); //A AND (NOT B)
}

void display (unsigned char set){
    printf("%d ", set);
    printf("{");
    int first = 1;
    for(int i = 0; i < SET_SIZE; ++i){
        if(set & (1 << i)) {
            if(!first) printf(", ");
            printf("%d", i);
            first = 0;
        }
    }
    printf("} (");
    for(int i = SET_SIZE - 1; i >= 0; i--){
        printf("%d", (set >> i) & 1);
    }
    printf(")\n");
}
