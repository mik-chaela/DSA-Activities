#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    Stack S[MAX_STACKS];
    for(int i = 0; i < MAX_STACKS; i++){
        initializeStack(&S[i]);
    }

    int choice;
    int ID;

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
                
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                printf("Exiting program\n");
                return 0;       
        }
    }

    return 0;
}

void initializeStack (Stack* s){
    s->top = -1;
}