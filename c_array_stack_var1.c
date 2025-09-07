/* Stack is a static array. TOP starts from first position and moves to the right. It is initialized to -1 indicating empty. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items [MAX];
    int top;
} Stack;

Stack* initialize();
bool isFull (Stack* S);
bool isEmpty (Stack* S);
void push (Stack* S, int value);
int pop (Stack* S);
void display (Stack* S, int popped);

int main(){
    Stack* S = initialize();
    int popped = -1;

    push (S, 1);
    push (S, 3);
    push (S, 2);
    push (S, 5);
    printf("Before Push Operation:\n");
    display(S, popped);
    push (S, 4);
    printf("After Push Operation:\n");
    display(S, popped);

    popped = pop(S);
    printf("After Pop Operation of %d:\n", popped);
    display(S, popped);

    free(S);

    return 0;
}

Stack* initialize(){
    Stack* S = (Stack*) malloc(sizeof(Stack));
    if(S == NULL){
        printf("Memory allocation failed.\n");
        return NULL;
    }
    S->top = -1;
    return S;
}

bool isFull (Stack* S){
    return S->top == MAX - 1;
}

bool isEmpty (Stack* S){
    return S->top == -1;
}

void push (Stack *S, int value){
    if (isFull(S)){
        printf("Stack is full.\n");
        return;
    }
    S->items[++(S->top)] = value;
}

int pop (Stack* S){
    if(isEmpty(S)){
        printf("Stack is empty.\n");   
        return 0;
    }
    return S->items[(S->top)--];
}

void display (Stack* S, int popped){
    if(isEmpty(S)){
        printf("Stack is empty.\n");  
        return;
    }
/*    
    Stack* temp = initialize(temp);

    printf("Items: [ ");
    while(!isEmpty(S)){
        int val = pop(S);
        printf("%d ", val);
    }

    while(!isEmpty(temp)){
        push(S, pop(temp));
    }

    if(popped != -1){
        printf("%d ", popped);
    }

    printf("\nTop: %d\n\n", S->top);

*/
    printf("Items: [ ");
    for(int i = 0; i <= S->top; i++){
        printf("%d", S->items[i]);        
        if(i < S->top) printf(", ");
    }

    if(popped != -1){
        if(S->top >= 0) printf(", ");
        printf("%d", popped);
    }

    if(S->top < MAX - 1){
        printf(", ...");
    }
    printf(" ]\n");
    printf("Top: %d\n\n", S->top);

}