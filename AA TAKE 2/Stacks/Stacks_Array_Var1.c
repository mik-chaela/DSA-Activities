/***************************************************** 
Stack is a static array (Last in, First Out)
Only the TOP element can be accessed and deleted.
It is initialized to -1 indicating empty.
NOTE: Stack cannot be traversed

Basic Operations: Push(), Pop(), Peek()
Helper Functions: isEmpty(), isFull(), initStack()
*****************************************************/

// Version 1
#include <stdio.h>
#include <stdbool.h>

#define MAX 10
typedef struct {
    int Elem [MAX];
    int top;
} Stack;

void initStack(Stack* A){
    A->top = -1;
}

bool isEmpty(Stack B){
    return B.top == -1;
}

bool isFull(Stack B){
    return B.top == MAX - 1;
}

void push (Stack* A, int num){
    if(isFull(*A)){
        printf("Stack is full. Cannot push\n");
        return;
    }
    A->Elem[++(A->top)] = num;
}

int pop (Stack* A){
    if(isEmpty(*A)){
        printf("Stack is empty. Nothing to pop.\n");
        return -1;
    }
    return A->Elem[(A->top)--];
}

void printStack (Stack A){

    if(isEmpty(A)){
        printf("Nothing to display. Stack is empty.\n");
        return;
    } 
    Stack B;
    initStack(&B);

    while(!isEmpty(A)){
        int val = pop(&A);
        printf("%d ", val);
        push (&B, val);
    }

    printf("\nTop Element: %d", B.Elem[B.top]);
    printf("\nIndex: %d\n", B.top);
    
}

int main(){
    Stack S;
    initStack(&S);

    push(&S, 3);
    push(&S, 6);
    push(&S, 8);
    printStack(S);

    return 0;
}