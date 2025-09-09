#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
    int items[MAX];
    int count;
} List;

typedef struct {
    List list;
    int front;
    int rear;
} Queue;

Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue (Queue* q);
void display (Queue* q);
int front(Queue* q);

int main(){
    Queue* Q = initialize();

    enqueue(Q, 1);
    enqueue(Q, 3);
    enqueue(Q, 2);
    enqueue(Q, 5);
    display(Q);

    printf("Dequeued: %d\n", dequeue(Q));
    display(Q);

    return 0;
}

Queue* initialize(){
    Queue* Q = (Queue*) malloc(sizeof(Queue));
    if(Q == NULL){
        printf("Memory allocation failed.\n");
        return NULL;
    }

    Q->list.count = 0;
    Q->front = -1;
    Q->rear = -1;

    return Q;
}

bool isFull(Queue* q){
    return (q->list.count == MAX);
}

bool isEmpty(Queue* q){
    return (q->list.count == 0);
}

void enqueue(Queue* q, int value){
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
    q->list.items[q->rear] = value;
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
        printf("Queue is empty.\n");
        return;
    }

    printf("Items: [ ");
    
    for(int i = 0; i <= q->rear && i < MAX; i++) {
        printf("%d, ", q->list.items[i]);
    }
    printf("... ]\n");
    printf("Count: %d\n", q->list.count);
    printf("Front: %d\n", q->front);
    printf("Rear: %d\n\n", q->rear);
}

int front(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return -1;
    }

    return (q->list.items[q->front]);
}