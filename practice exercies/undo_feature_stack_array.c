#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING 20
#define MAX_STACK 10

typedef struct {
    char operationType[MAX_STACK][MAX_STRING];
    int top;
} Stack;

Stack* initializeStack();
bool isEmpty (Stack* s);
bool isFull (Stack* s);
void pushOperation(Stack* s, char* operation);
char* undoOperation (Stack* s);
void showHistory (Stack* s);

int main(){
    Stack* history = initializeStack();

    if(history == NULL){
        printf("Memory allocation failed.\n\n");
        return 0;
    }

    int choice;
    char* undo;

    while(1){
        printf("Hello User! Welcome to Text Editor!\n");
        printf("(1) Type Text\n(2) Delete Text\n(3) Paste Text\n(4) Copy Text\n"
                "(5) Undo Last Action\n(6) Show History\n(7) Exit Program\n");
        printf("What do you want to do today? ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                pushOperation(history, "Type Text");
                printf("\nYou just typed in a text.\n\n");
                break;
            case 2:
                pushOperation(history, "Delete Text");
                printf("\nYou just deleted a text.\n\n");
                break;
            case 3:
                pushOperation(history, "Paste Text");
                printf("\nYou just pasted a text.\n\n");
                break;
            case 4:
                pushOperation(history, "Copy Text");
                printf("\nYou just copied a text.\n\n");
                break;
            case 5:
                undo = undoOperation(history);
                if(undo != NULL){
                    printf("\nLast Operation '%s' Removed\n\n", undo);
                } else {
                    printf("Add operations first.\n\n");
                }
                break;
            case 6:
                showHistory(history);
                break;
            case 7:
                free(history);
                printf("\nThank you for using Text Editor. See you again soon!");
                return 0;
            default:
                printf("\nError: Invalid choice.\n\n");
        }
    }

    return 0;
}

Stack* initializeStack(){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if(s == NULL){
        printf("\nError: ");
        return NULL;
    }
    s->top = -1;
    return s;
}

bool isEmpty (Stack* s){
    return (s->top == -1);
}

bool isFull (Stack* s){
    return (s->top == MAX_STACK - 1);
}

void pushOperation(Stack* s, char* operation){
    if(isFull(s)){
        printf("\nError: History is full. Please try again later.\n\n");
        return;
    }

    s->top++;
    strcpy(s->operationType[s->top], operation);
}

char* undoOperation (Stack* s){
    if(isEmpty(s)){
        printf("\nError: History is empty. ");
        return NULL;
    }

    return s->operationType[(s->top)--];
}

void showHistory (Stack* s){
    if(isEmpty(s)){
        printf("\nNo History Saved\n");
    }

    Stack* tempStack = initializeStack();
    int i = 0;
    
    printf("\n--- History of Operations ---\n");
    while(!isEmpty(s)){
        pushOperation(tempStack, undoOperation(s));
    }
    
    while(!isEmpty(tempStack)){
        char* operation = undoOperation(tempStack);
        printf("%d. %s\n", i+1, operation);
        i++;
        pushOperation(s, operation);
    }
    printf("\n");
}