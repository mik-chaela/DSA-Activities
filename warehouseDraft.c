#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "arrayStack.h"

#define MAX_STACKS 3

int main() {
    // write your code here
    Stack s[MAX_STACKS];
    
    for(int i = 0; i < MAX_STACKS; i++){
        initializeStack(&s[i]);
    }

    int choice;
    Stack* targetStack = NULL;
    
    while(1){
        printf("--- Warehouse Inventory Management System ---\n"
               "1. Push a container\n2. Pop a container\n"
               "3. Check if a container exists\n4. Display all stacks\n"
               "5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                int ID;
                printf("Enter container ID to push: ");
                scanf("%d", &ID);
                
                for(int i = 0; i < MAX_STACKS && targetStack == NULL; i++){
                    if(!isFull(&s[i])){
                        targetStack = &s[i];
                    }
                }
                if(targetStack != NULL){
                    push(targetStack, ID);
                }
                printf("Container %d pushed successfully.\n\n", ID);
                break;
            case 2:
                int popped;
                for(int i = 0; i < MAX_STACKS && targetStack == NULL; i++){
                    if(!isEmpty(&s[i])){
                        targetStack = &s[i];
                    }
                }
                if(targetStack != NULL){
                    popped = pop(targetStack);
                }
                printf("Container %d popped successfully.\n\n", popped);
                break;
            case 3:
                int check;
                printf("Enter container ID to check: ");
                scanf("%d", &check);
                
                bool found = false;
                for(int i = 0; i < MAX_STACKS && !found; i++){
                    Stack tempStack;
                    initializeStack(&tempStack);
                    int topElement;
                    
                    while(!isEmpty(&s[i])){
                        topElement = pop(&s[i]);
                        push(&tempStack, topElement);
                        if(topElement == check){
                            found = true;
                            break;
                        }
                    }
                        
                    while(!isEmpty(&tempStack)){
                        push(&s[i], pop(&tempStack));
                    }
                }
                
                if(!found){
                    printf("Container %d exists in a stack.\n", check);
                } else {
                    printf("Container %d does not exist in any stack.\n", check);
                }
            case 4:
               display(s); 
               break;
            case 5:
                printf("Exiting program.");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}


/*
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "types.h"
#define MAX_STACKS 3


// write your functions here
void initializeStack(Stack *s){
    s->top = -1;
}

int pop(Stack *s){
    if(isEmpty(s)){
        printf("Error: All stacks are empty. Cannot pop container.\n");
        return -1;
    }
    return s->items[(s->top)--];
}

bool isFull (Stack* s){
    return (s->top == MAX - 1);
}

bool isEmpty (Stack* s){
    return (s->top == -1);
}

void push (Stack *s, int value){
    s->items[++(s->top)] = value;
}

void display(Stack *s){
    for(int i = 0; i < MAX_STACKS; i++){
        printf("\n--- Stack %d ---\n", i+1);
        if(isEmpty(&s[i])){
            printf("Stack is empty.\n\n");
            return;
        } else {
            Stack tempStack;
            initializeStack(&tempStack);

            while(!isEmpty(&s[i])){
                int val = pop(&s[i]);
                printf("%d\n", val);
                push(&tempStack, val);
            }
            
            while(!isEmpty(&tempStack)){
                push(&s[i], pop(&tempStack));
            }
        }
    }
}
*/
