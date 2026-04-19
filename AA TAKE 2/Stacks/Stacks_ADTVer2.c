//VERSION 2

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct stackType {
    char Elem[MAX];
    int top;
} *Stack;

void initializeStack(Stack* S){
    (*S) = malloc(sizeof(struct stackType));
    if((*S)!= NULL){
        (*S)->top = -1;
    }
}

bool isEmpty (Stack S){
    return (S->top == -1);
}

bool isFull (Stack S){
    return (S->top == MAX - 1);
}

void push (Stack* S, char newElem){
    
}

int main(){
    Stack S;
    initializeStack(&S);

    return 0;
}