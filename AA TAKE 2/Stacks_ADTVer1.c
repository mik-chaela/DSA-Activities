//VERSION 1

#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

typedef struct {
    char Elem [SIZE];
    int top;
} Stack;

void initStack(Stack* A);
bool isEmpty (Stack A);
bool isFull (Stack A);
void push (Stack* A, char newElem);
char pop (Stack* A);
void printStack (Stack A);

int main (){
    Stack S;
    initStack(&S);
    
    push (&S, 'A');
    push (&S, 'Y');
    push (&S, 'O');
    push (&S, 'P');
    printStack(S);

    return 0;
}

void initStack(Stack* A){
    A->top = -1;
}

bool isEmpty (Stack A){
    return A.top == -1;
}

bool isFull (Stack A){
    return A.top == SIZE - 1;
}

void push (Stack* A, char newElem){
    if(isFull(*A)){
        printf("Stack is full.\n");
    } else {
        A->Elem[++(A->top)] = newElem;
    }
}

char pop (Stack* A){
    if(isEmpty(*A)){
        printf("Nothing to pop. Stack is empty.\n");
        return -1;
    }   
    return A->Elem[(A->top)--];
}

void printStack (Stack A){
    if(isEmpty(A)){
        printf("Nothing to display. Stack is empty.\n");
        return;
    } else {
        Stack tempStack;
        initStack (&tempStack);

        printf("Top Element: %c\n", A.Elem[A.top]);
        printf("Index: %d\n", A.top);

        while(!isEmpty(A)){
            char poppedValue = pop(&A);
            printf("%d %c\n", A.top + 1 ,poppedValue);
            push(&tempStack, poppedValue);
        }

        while(!isEmpty(tempStack)){
            push(&A, pop(&tempStack));
        }
    }
}