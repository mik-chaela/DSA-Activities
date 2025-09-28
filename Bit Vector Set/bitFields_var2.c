/* 
Variation 2 - Bit Fields
Bit fields allow the compiler to pack structure members into a small 
number of bits. The struct itself holds the bit set.
*/

#include <stdio.h>
#include <stdbool.h>

#define SET_SIZE 8

typedef struct {
    unsigned int field: SET_SIZE;
} Set;

void initialize (Set* set);
void insert (Set* set, int element);
void delete (Set* set, int element);
bool find (Set set, int element);
Set union_set (Set A, Set B);
Set intersection (Set A, Set B);
Set difference (Set A, Set B);
void display (Set set);

int main(){
    Set A, B, C;
    initialize(&A);
    initialize(&B);

    insert(&A, 0); 
    printf("A = "); display(A);
    insert(&A, 4); 
    printf("A = "); display(A);
    insert(&A, 5); 
    printf("A = "); display(A);

    insert(&B, 2); 
    printf("B = "); display(B); 
    insert(&B, 5); 
    printf("B = "); display(B); 

    printf("Find 1 in A: %s\n", find(A, 1) ? "Yes" : "No");
    printf("Find 5 in A: %s\n", find(A, 5) ? "Yes" : "No");

    C = union_set(A, B);
    printf("C.field (Union) = "); display(C); 

    C = intersection(A, B);
    printf("C.field (Intersection) = "); display(C); 

    C = difference(A, B);
    printf("C.field (Difference) = "); display(C); 

    delete(&A, 5); 
    printf("A after delete = "); display(A);
    delete(&A, 4); 
    printf("A after delete = "); display(A);

    return 0;
}

void initialize (Set* set){
    set->field = 0; //clearing all bits
}

void insert (Set* set, int element){
    if(element < 0 || element >= SET_SIZE) return;
    unsigned int mask = 1 << element;
    set->field |= mask;
}

void delete (Set* set, int element){
    if(element < 0 || element >= SET_SIZE) return;
    unsigned int mask = 1 << element;
    mask = ~mask;
    set->field &= mask;
}

bool find (Set set, int element){
    if(element < 0 || element >= SET_SIZE) return false;
    unsigned int mask = 1 << element;
    return (set.field & mask) != 0;
}

Set union_set (Set A, Set B){
    Set C;
    C.field = A.field | B.field;
    return C;
}

Set intersection (Set A, Set B){
    Set C;
    C.field = A.field & B.field;
    return C;
}

Set difference (Set A, Set B){
    Set C;
    C.field = A.field & (~B.field);
    return C;
}

void display (Set set){
    printf("%d ", set.field);
    printf("{");
    int first = 1;
    for(int i = 0; i < SET_SIZE; ++i){
        if(set.field & (1 << i)) {
            if(!first) printf(", ");
            printf("%d", i);
            first = 0;
        }
    }
    printf("} (");
    for(int i = SET_SIZE - 1; i >= 0; i--){
        printf("%d", (set.field >> i) & 1);
    }
    printf(")\n");
}
