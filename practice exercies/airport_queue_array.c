#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSENGERS 10

typedef struct {
    int ticketNo;
    char name[30];
    char dest[30];
} PassengerDetails;

typedef struct {
    PassengerDetails passenger [MAX_PASSENGERS];
    int count;
} AirportList;

typedef struct {
    AirportList list;
    int front;
    int rear;
} Queue;

Queue* initializeBooking ();
bool isFull (Queue* q);
bool isEmpty (Queue* q);
void enqueuePassenger (Queue* q, char* name, char* dest, int no);
PassengerDetails* dequeuePassenger (Queue* q);
void display (Queue* q);

int main(){
    Queue* booking = initializeBooking();
    PassengerDetails* called;
    int choice, find;
    int ticketNo = 1;
    char name[30];
    char dest[30];
    
    while(1){
        printf("-----------------------------------------\n");
        printf("Mabuhay! Welcome to Philippine Airlines!\n");
        printf("-----------------------------------------\n");
        printf("What do you want to do today?\n");
        printf("(1) Enqueue Passenger\n(2) Call Passenger Number\n(3) Search for a Passenger\n(4) Display Queue\n(5) Exit Program\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice){
            case 1:
                printf("Enter name of the passenger: ");
                fgets(name, sizeof(name), stdin);
                printf("Enter destination: ");
                fgets(dest, sizeof(dest), stdin);

                enqueuePassenger(booking, name, dest, ticketNo);
                printf("\nSuccess! Booking details saved. Ticket Number is %d.\n\n", ticketNo);
                ticketNo++;
                break;
            case 2:
                called = dequeuePassenger(booking);
                
                if(called != NULL){
                    printf("\nCalling Passenger with Ticket Number %d.\n", called->ticketNo);
                    printf("Name: %sDestination: %s", called->name, called->dest);
                    printf("Please proceed to boarding. Thank you!\n\n");
                } else {
                    printf("No Passenger to Call.\n\n");
                }
                break;
            case 3:
                printf("Enter Ticket Number to search passenger: ");
                scanf("%d", &find);

                PassengerDetails* found = NULL;
                Queue* tempQueue = initializeBooking();
                PassengerDetails* frontPerson;

                while(!isEmpty(booking)){
                    frontPerson = dequeuePassenger(booking);
                    enqueuePassenger(tempQueue, frontPerson->name, frontPerson->dest, frontPerson->ticketNo);
                    if(frontPerson->ticketNo == find){
                        found = (PassengerDetails*)malloc(sizeof(PassengerDetails));
                        found->ticketNo = frontPerson->ticketNo;
                        strcpy(found->name, frontPerson->name);
                        strcpy(found->dest, frontPerson->dest);
                        break;
                    }
                }

                while(!isEmpty(tempQueue)){
                    PassengerDetails* dequeued = dequeuePassenger(tempQueue);
                    enqueuePassenger(booking, dequeued->name, dequeued->dest, dequeued->ticketNo);
                }

                if (found != NULL){
                    printf("\nPassenger with Ticket Number %d found!\n", found->ticketNo);
                    printf("Name: %sDestination: %s\n", found->name, found->dest);
                    free(found);
                } else {
                    printf("\nNo Passenger Found.\n\n");
                }
                break;
            case 4:
                display(booking);
                break;
            case 5:
                free(booking);
                printf("\nThank you for flying with us. Goodbye!\n");
                return 0;
            default:
                printf("Error! Invalid choice.\n");
                break;
        }
    }

    return 0;

}

Queue* initializeBooking (){
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

bool isFull (Queue* q){
    return (q->list.count == MAX_PASSENGERS);
}

bool isEmpty (Queue* q){
    return (q->list.count == 0);
}

void enqueuePassenger (Queue* q, char* name, char* dest, int no){
    if(isFull(q)){
        printf("Error: Fully Booked! Please try again later.\n");
        return;
    }
    
    if(isEmpty(q)){
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = ((q->rear + 1) % MAX_PASSENGERS);
    }

    q->list.passenger[q->rear].ticketNo = no;
    strcpy(q->list.passenger[q->rear].name, name);
    strcpy(q->list.passenger[q->rear].dest, dest);
    
    q->list.count++;
}

PassengerDetails* dequeuePassenger (Queue* q){
    if(isEmpty(q)){
        printf("\nQueue is empty. ");
        return NULL;
    }

    PassengerDetails* frontPerson = &q->list.passenger[q->front];
    q->list.count--;

    if(q->list.count == 0){
        q->front = q->rear = -1; 
    } else {
        q->front = ((q->front + 1) % MAX_PASSENGERS);
    }
    return frontPerson;
}

void display (Queue* q){
    if(isEmpty(q)){
        printf("\nNo Booking Details Found...\n\n");
        return;
    }

    Queue* tempQueue = initializeBooking();
    PassengerDetails* passenger;
    printf("\n-----------------------------------------\n");
    printf("\t\tBooking Details\n");
    printf("-----------------------------------------\n\n");

    while(!isEmpty(q)){
        passenger = dequeuePassenger(q);
        printf("Ticket No: %d\n", passenger->ticketNo);
        printf("Name: %sDestination: %s\n", passenger->name, passenger->dest);
        enqueuePassenger(tempQueue, passenger->name, passenger->dest, passenger->ticketNo);
    }
    
    while(!isEmpty(tempQueue)){
        passenger = dequeuePassenger(tempQueue);
        enqueuePassenger(q, passenger->name, passenger->dest, passenger->ticketNo);
    }
    printf("Total Number of Passenger/s: %d\n", q->list.count);
    printf("-----------------------------------------\n\n");
    free(tempQueue);
    
}
