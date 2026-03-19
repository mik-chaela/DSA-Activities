#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
    int items[MAX];
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
}

Queue* initialize(){
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    if(Q == NULL){
        printf("Memory allocation failed.\n");
        return NULL;
    }
    Q->front = 1;
    Q->rear = 0;

    return Q;
}

bool isEmpty(Queue* q){
    return (q->front == (q->rear + 1) % MAX);
}

bool isFull(Queue* q){
    return (q->front == (q->rear + 2) % MAX);
}