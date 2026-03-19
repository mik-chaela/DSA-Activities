/*********************************************************

LINKED LIST QUEUE IMPLEMENTATION

*********************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
	int severity;
	char symptoms[50]; //for testing purposes
} MedicalInfo;

typedef struct {
	int id;
	char name[24];
	int age;
	MedicalInfo med;
} Patient;

typedef struct node{
	Patient data;
	struct node* next;
} Node;

typedef struct {
	Node* front;
	Node* rear;
} Queue;

void initQueue (Queue* Q);
bool isEmpty (Queue Q);
void enqueue (Queue* Q, Patient P);
Patient dequeue (Queue* Q);
Patient peek (Queue Q);
void displayQueue (Queue Q);
int countPatients (Queue Q);
void searchPatients (Queue Q, int id);
void freeQueue (Queue* Q);

int main(){
	Queue A;
	initQueue (&A);
	
	int menu;
	Patient new;
	while(1){
		printf("\nHOSPITAL ER SYSTEM\n");
		printf("1 - Add Patient\n2 - Treat Patient\n3 - View Waiting List\n4 - Peek Next Patient\n5 - Exit\n");
		printf("Enter option: ");
		scanf("%d", &menu);
		
		switch(menu){
			case 1:
				printf("Enter patient ID: ");
				scanf("%d", &new.id);
				
				printf("Enter patient name: ");
				scanf(" %[^\n]", new.name);
				
				printf("Enter patient age: ");
				scanf("%d", &new.age);
				
				printf("Reason for Hospitalization: ");
				scanf(" %[^\n]", new.med.symptoms);
				
				printf("Enter severity (1 - lowest; 5 - highest): ");
				scanf("%d", &new.med.severity);
				
				enqueue (&A, new);
				printf("\nPatient %s is now in queue (%s; Severity: %d)\n", new.name, new.med.symptoms, new.med.severity);
				break;
			case 2:
				
				break;
			case 3:
				break;
			case 4:
				break;
			case 5: 
				freeQueue (&A);
				printf("\nQueue is freed. Program exiting...");
				return 0;
			default:
				printf("\nError. Invalid option encoded!\n");
				break;
		}
	}
	return 0;
}

void initQueue (Queue* Q){
	Q->front = NULL;
	Q->rear = NULL;
}

bool isEmpty (Queue Q){
	return Q.front == NULL;
}

void enqueue (Queue* Q, Patient P){
	Node* newPatient = malloc(sizeof(Node));
	
	if(newPatient != NULL){
		newPatient->data = P;
		newPatient->next = NULL;
		
		if(isEmpty(*Q)){
			Q->front = newPatient;
			Q->rear = newPatient;
		} else {
			Q->rear->next = newPatient;
			Q->rear = newPatient;
		}
	}
}

void freeQueue (Queue* Q){
	while (Q->front != NULL) {
        Node* temp = Q->front->next;
        free(Q->front);
        Q->front = temp;
    }
    Q->rear = NULL;
}
