#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 5

typedef struct{
    int items[MAX];
    int top;
} Stack;

bool isFull (Stack* s);
bool isEmpty (Stack* s);
void push (Stack* s, int value);
int pop (Stack* s);
int peek(Stack* s);
bool exists (Stack* s, int value);
void initializeStack (Stack* s);
void display(Stack* s);

int main(){
    Stack s[3];
    
    for(int i = 0; i < 3; i++){
        initializeStack(&s[i]);
    }

    int choice;
    int ID;
    int popped = -1;

    while(1){
        printf("--- Warehouse Inventory System ---\n"
               "1. Push a container\n2. Pop a container\n"
               "3. Check if a container exists\n4. Display all stacks\n"
               "5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter container ID to push: ");
                scanf("%d", &ID);

                for(int i = 0; i < 3; i++){
                    if(!isFull(&s[i])){
                        push(&s[i], ID);
                        break;
                    }
                }
                printf("Container %d pushed successfully.\n\n", ID);
                break;
            case 2:
                popped = pop(s);
                if (popped != -1){
                    printf("Container %d popped successfully.\n", popped);
                } else {
                    break;
                }
                break;
            case 3:
                printf("Enter container ID to check: ");
                scanf("%d", &ID);
                bool find = exists (s, ID);
                if (find) {
                    printf("Container %d exists in a stack.\n\n");
                } else {
                    printf("Container %d does not exist in any stack.\n\n");
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
    for(int i = 2; i >= 0; i--){
        if(!isEmpty(&s[i])){
            int value = s[i].items[(s[i].top)--];
            return value;
        }
    }
    printf("Error: All stacks are empty. Cannot pop container\n");
    return -1;
}

bool exists (Stack* s, int value){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j <= s[i].top; j++){
            if(s[i].items[j] == value){
                return true;
            }
        }
    }
    return false;
}
void initializeStack (Stack* s){
    s->top = -1;
}

void display(Stack* s){
    for(int i = 0; i < 3; i++){
        printf("---Stack %d---\n", i+1);

        if(isEmpty(&s[i])){
            printf("Stack is empty.\n\n");
        } else {
            for(int j = s[i].top; j >= 0; j--){
                printf("%d\n", s[i].items[j]);
            }
            printf("\n");
        }
        
    }
}