#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int customerNo;
    struct Node* next;
} Node;

typedef struct {
   Node* front;
   Node* rear; 
} Queue;

Queue* initialize ();
//bool isFull (Queue* q); //Linked list can never be full
bool isEmpty (Queue* q);
Node* createNode (int customerNo);
void enqueue (Queue* q, int customerNo);
int dequeue (Queue* q);
void display (Queue* q);
void freeQueue(Queue* q);

int main (){
    Queue* regularQueue = initialize();
    Queue* priorityQueue = initialize();
    
    int choice, served;
    int customerNo = 1;

    while(1){
        printf("--- Pharmacy Queueing System ---\n");
        printf("1. Enter Regular Queue\n2. Enter Priority Queue\n"
               "3. Call Next Customer\n4. Display Queues\n"
               "5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                enqueue (regularQueue, customerNo);
                printf("You have entered the Regular Queue. Your number is %d.\n\n", customerNo);
                customerNo++; 
                break;
            case 2:
                enqueue(priorityQueue, customerNo);
                printf("You have entered the Priority Queue. Your number is %d.\n\n", customerNo);
                customerNo++;
                break;
            case 3:
                if(!isEmpty(priorityQueue)){
                    served = dequeue(priorityQueue);
                    printf("Calling next customer from Priority Queue. Customer number: %d\n\n", served);
                } else if (!isEmpty(regularQueue)){
                    served = dequeue (regularQueue);
                    printf("Calling next customer from Regular Queue. Customer number: %d\n\n", served);
                } else {
                    printf("No customers in queue.\n");
                }
                break;
            case 4:
                printf("\n-- Current Queue Status --\n");
                printf("Regular Queue: ");
                display(regularQueue);
                printf("\nPriority Queue: ");
                display(priorityQueue);
                printf("\n\n");
                break;
            case 5:
                freeQueue(priorityQueue);
                freeQueue(regularQueue);

                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}

Queue* initialize (){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if(q == NULL){
        printf("Memory allocation failed.\n");
        return NULL;
    }
    q->front = NULL;
    q->rear = NULL;

    return q;
}

bool isEmpty (Queue* q){
    return (q->front == NULL);
}

Node* createNode (int customerNo){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->customerNo = customerNo;
    newNode->next = NULL;

    return newNode;
}

void enqueue (Queue* q, int customerNo){
    Node* newNode = createNode(customerNo);

    if(isEmpty(q)){
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue (Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return -1;
    }
    Node* temp = q->front;
    int front = temp->customerNo;

    q->front = q->front->next;
    if(q->front == NULL){
        q->rear = NULL;
    }
    free(temp);
    return front;
}

void display (Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return;
    }
    Node* temp = q->front;
    while(temp != NULL){
        printf("%d -> ", temp->customerNo);
        temp = temp->next;
    }
    printf("END\n");
}

void freeQueue(Queue* q){
    Node* current = q->front;

    while(current != NULL){
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    q->front = q->rear = NULL;
}