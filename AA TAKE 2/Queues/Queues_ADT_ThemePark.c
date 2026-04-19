#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5
typedef struct {
    int id;
    char name[24];
    int age;
} Guest;

typedef struct {
    Guest data[MAX];
    int front;
    int rear;
} Queue;

void initQueue (Queue* Q);
int isEmpty (Queue Q);
int isFull (Queue Q);
void peek (Queue Q);
void enqueue (Queue* Q, Guest g);
Guest dequeue (Queue* Q);
void displayQueue (Queue Q);

int main() {
    Queue line;
    initQueue (&line);
    
    int choice;
    Guest next;
    while(1){
        printf("THEME PARK QUEUE SYSTEM\n\n");
        printf("1 - Add Guest to Line\n2 - Ride Finished (Dequeue)\n3 - Display Waiting Guests\n4 - Exit\n\nChoice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter guest's ID: ");
                scanf("%d", &next.id);
                printf("Enter guest's name: ");
                scanf("%s", next.name);
                printf("Enter guest's age: ");
                scanf("%d", &next.age);
                
                if(isFull(line) == 1){
                    printf("Queue is full. No more guests can enter the line.\n");
                } else {
                    enqueue (&line, next);
                    printf("Guest %s enters line\n\n", next.name);
                }
                break;
            case 2:
                if(isEmpty(line) == 1){
                    printf("No guests waiting in line.\n\n");
                } else {
                    Guest out = dequeue(&line);
                    printf("%s rides the rollercoaster.\n\n", out.name);
                }
                break;
            case 3:
                if(isEmpty(line) == 1){
                    printf("No guests waiting in line.\n\n");
                } else {
                    displayQueue(line);
                }
                break;
            case 4:
                return 0;
            default:
                printf("Choice invalid. Enter another.\n\n");
        }
    }

    return 0;
}

void initQueue (Queue* Q){
    Q->front = 0;
    Q->rear = MAX - 1;
}

int isEmpty (Queue Q){
    int retval;
    if((Q.rear + 1) % MAX == Q.front){
        retval = 1; //Queue is empty
    } else {
        retval = 0; //Queue is not empty
    }
    return retval;
}

int isFull (Queue Q){
    int retval;
    if((Q.rear + 2) % MAX == Q.front){
        retval = 1; //Queue is full
    } else {
        retval = 0; //Queue is not full
    }
    return retval;
}

void enqueue (Queue* Q, Guest g){
    Q->rear = (Q->rear + 1) % MAX;
    Q->data[Q->rear] = g;
}

Guest dequeue (Queue* Q){
    Guest frontGuest;
    
    if(isEmpty(*Q) == 1){
        printf("No guests waiting in line.\n\n");
    } else {
        frontGuest = Q->data[Q->front];
        Q->front = (Q->front + 1) % MAX;
    }
    return frontGuest;
}

void displayQueue (Queue Q){
    Guest next;
    printf("Guests waiting in line:\n\n");
    while(isEmpty(Q) != 1){
        next = dequeue(&Q);
        printf("ID: %d | Name: %s | Age: %d\n", next.id, next.name, next.age);
    }
    printf("\n");
}
