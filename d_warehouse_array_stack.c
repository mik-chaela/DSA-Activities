#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 5
#define MAX_STACKS 3

typedef struct{
    int items[MAX];
    int top;
} Stack;

bool isFull (Stack* s);
bool isEmpty (Stack* s);
void push (Stack* s, int value);
int pop (Stack* s);
int peek(Stack* s);
void initializeStack (Stack* s);
void display(Stack* s);

int main(){
    Stack s[MAX_STACKS];
    
    for(int i = 0; i < MAX_STACKS; i++){
        initializeStack(&s[i]);
    }

    int choice, ID;
    int popped = -1;

    while(1){
        printf("--- Warehouse Inventory Management System ---\n"
               "1. Push a container\n2. Pop a container\n"
               "3. Check if a container exists\n4. Display all stacks\n"
               "5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter container ID to push: ");
                scanf("%d", &ID);

                Stack* targetStack = NULL;
                for(int i = 0; i < MAX_STACKS; i++){
                    if(!isFull(&s[i])){
                        targetStack = &s[i];
                        break;
                    }
                }
                
                if(targetStack != NULL){
                    push (targetStack, ID);
                    printf("Container %d pushed successfully.\n\n", ID);
                } else {
                    printf("Error: All stacks are full. Cannot push.\n\n");
                }
                break;
            case 2: {
                Stack* targetStack = NULL;
                
                for (int i = MAX_STACKS - 1; i >= 0; i--){
                    if(!isEmpty(&s[i])){
                        targetStack = &s[i];
                        break;
                    }
                }

                if(targetStack != NULL) {
                    popped = pop(targetStack);
                    printf("Container %d popped successfully.\n\n", popped);
                } else {
                    printf("Error: All stacks are empty. Cannot pop container.\n\n");
                }
                break;
            }
            case 3:
                printf("Enter container ID to check: ");
                scanf("%d", &ID);

                bool found = false;
                for(int i = 0; i < MAX_STACKS && !found; i++){
                    Stack tempStack;
                    initializeStack(&tempStack);

                    while (!isEmpty(&s[i])) {
                        int topElement = pop(&s[i]);
                        push(&tempStack, topElement);
                        if(topElement == ID){
                            found = true;
                        }
                    }

                    while(!isEmpty(&tempStack)) {
                        push(&s[i], pop(&tempStack));
                    }
                }

                if (found) {
                    printf("Container %d exists in a stack.\n\n", ID);
                } else {
                    printf("Container %d does not exist in any stack.\n\n", ID);
                }

                break;
            case 4:
                display(s);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}

bool isFull (Stack* s){
    return (s->top == MAX - 1); 
}

bool isEmpty (Stack* s){
    return (s->top == -1);
}

void push (Stack* s, int value){
    if(isFull(s)){
        printf("Stack is full.\n");
        return;
    }
    s->items[++(s->top)] = value;
}

int pop (Stack* s){
    if(isEmpty(s)){
        printf("Error: Stack is empty. Cannot pop container.\n");
        return -1;
    }
    return s->items[(s->top)--];
}

void initializeStack (Stack* s){
    s->top = -1;
}

void display(Stack* s){
    for(int i = 0; i < MAX_STACKS; i++){
        printf("\n--- Stack %d ---\n", i + 1);

        if(isEmpty(&s[i])) {
            printf("Stack is empty.\n\n");
            continue;
        }

        Stack tempStack;
        initializeStack(&tempStack);

        while(!isEmpty(&s[i])) {
            int val = pop(&s[i]);
            printf("%d\n", val);
            push(&tempStack, val);
        }

        while(!isEmpty(&tempStack)){
            push(&s[i], pop(&tempStack));
        }
    }
    printf("\n");
}
