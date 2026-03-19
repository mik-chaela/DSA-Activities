#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 5
#define MAX_STACKS 3

typedef struct node{
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* top;
    int count;
} Stack;

bool isFull (Stack* s);
bool isEmpty (Stack* s);
void push (Stack* s, int ID);
int pop (Stack* s);
int peek(Stack* s);
Stack* initializeStack ();
void display(Stack* s);
void freeStack (Stack* s);

int main (){
    Stack* s[MAX_STACKS];

    for(int i = 0; i < MAX_STACKS; i++){
        s[i] = initializeStack();
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
                    if(!isFull(s[i])){
                        targetStack = s[i];
                        break;
                    }
                }

                if(targetStack != NULL){
                    push (targetStack, ID);
                    printf("Container %d pushed successfully.\n\n", ID);
                } else {
                    printf("Error: All stacks are full. Cannot push container.\n\n");
                }
                
                break;
            case 2: {
                Stack* targetStack = NULL;

                for(int i = MAX_STACKS - 1; i >= 0; i--){
                    if(!isEmpty(s[i])){
                        targetStack = s[i];
                        break;
                    }
                }

                if(targetStack != NULL){
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
                    Stack* tempStack = initializeStack();

                    while(!isEmpty(s[i])){
                        int topElement = pop(s[i]);
                        push(tempStack, topElement);
                        if(topElement == ID){
                            found = true;
                        }
                    }

                    while(!isEmpty(tempStack)){
                        push(s[i], pop(tempStack));
                    }
                    free(tempStack);
                }

                if(found){
                    printf("Container %d exists in a stack.\n\n", ID);
                } else {
                    printf("Container %d does not exist in any stack.\n\n", ID);
                }
                break;
            case 4:
                for(int i = 0; i < MAX_STACKS; i++){
                    printf("\n--- Stack %d ---\n", i+1);
                    display(s[i]);
                }
                break;
            case 5:
                for (int i = 0; i < MAX_STACKS; i++){
                    freeStack(s[i]);
                }
                
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
    return (s->count == MAX);
}

bool isEmpty (Stack* s){
    return (s->count == 0);
}

Stack* initializeStack (){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if(s == NULL){
        printf("Memory allocation failed.\n");
        return NULL;
    }
    s->top = NULL;
    s->count = 0;
    return s;
}

void push (Stack* s, int ID){
    if(isFull(s)){
        printf("Error: Stack is full. Cannot push container.\n");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = ID;
    newNode->next = s->top;
    s->top = newNode;

    s->count++;
}

int pop (Stack* s){
    if(isEmpty(s)){
        printf("Error: Stack is empty. Cannot pop container.\n");
        return -1;
    }
    
    Node* temp = s->top;
    int top = temp->data;
    s->top = s->top->next;

    free(temp);
    s->count--;
    return top;
}

void display(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty.\n\n");
        return;
    }

    Node* current = s->top;
    while (current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
    
    printf("\n");
}

void freeStack (Stack* s){
    Node* current = s->top;

    while(current != NULL){
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    s->top = NULL;
    s->count = 0;
}