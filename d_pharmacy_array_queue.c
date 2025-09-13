#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10
#define MAX_Q 2

typedef struct {
    int items[MAX];
    int count;
} List;

typedef struct {
    List list;
    int front;
    int rear;
} Queue;

Queue* initialize();
bool isFull (Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int num);
int dequeue (Queue* q);
void display (Queue* q);

int main(){
    Queue* regularQueue = initialize();
    Queue* priorityQueue = initialize();

    int choice;
    int customerNum = 1;
    int served;
    
    while(1){
        printf("--- Pharmacy Queueing System ---\n");
        printf("1. Enter Regular Queue\n2. Enter Priority Queue\n"
               "3. Call Next Customer\n4. Display Queues\n"
               "5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                if(!isFull(regularQueue)){
                    enqueue (regularQueue, customerNum);
                    printf("You have entered the Regular queue. Your number is %d.\n\n", customerNum);
                    customerNum++;
                } else {
                    printf("Regular queue is full. Please try again later.\n\n");
                }
                
                break;
            case 2:
                if(!isFull(priorityQueue)){
                    enqueue (priorityQueue, customerNum);
                    printf("You have entered the Priority queue. Your number is %d.\n\n", customerNum);
                    customerNum++;
                } else {
                    printf("Priority queue is full. Please try again later.\n\n");
                }
                
                break;
            case 3:
                if(!isEmpty(priorityQueue)){
                    served = dequeue(priorityQueue);
                    printf("Calling next customer from Priority Queue. Customer number: %d\n\n", served);
                } else if (!isEmpty(regularQueue)){
                    served = dequeue(regularQueue);
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
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    
}

bool isFull(Queue* q){
    return (q->list.count == MAX);
}

bool isEmpty(Queue* q){
    return (q->list.count == 0);
}

Queue* initialize(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if(q == NULL){
        printf("Memory allocation failed.\n");
        return NULL;
    }
    q->list.count = 0;
    q->front = -1;
    q->rear = -1;

    return q;
}

void enqueue(Queue* q, int num){
    if(isFull(q)){
        printf("Queue is full.\n");
        return;
    }

    if(isEmpty(q)){
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = ((q->rear + 1) % MAX);
    }
    q->list.items[q->rear] = num;
    q->list.count++;
}

int dequeue (Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return -1;
    }

    int frontValue = q->list.items[q->front];
    q->list.count--;
     
    if(q->list.count == 0){
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }

    return frontValue;
}

void display (Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty.");
        return;
    }

    for (int i = q->front; i <= q->rear && i < MAX; i++){
        printf("%d ", q->list.items[i]);
    }
}