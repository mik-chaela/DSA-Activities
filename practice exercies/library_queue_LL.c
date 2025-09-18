#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int studentID;
    char name[30];
    bool isVIP;
} Student;

typedef struct node{
    Student student;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* initialize();
bool isEmpty(Queue* q);
Node* createNode (int studID, char* studName, int vip);
void enqueueStudent (Queue* q, int studID, char* studName, int vip);
void displayLine (Queue* q);

int main(){
    Queue* line = initialize();

    int choice, studID, vipp;
    char studName[30];
    char vip;


    while(1){
        printf("Welcome to USC Library Queueing System!\n");
        printf("(1) Get Queue Number\n(2) Call Student\n(3) Display Queue\n(4) Exit Program\n");;
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter your USC ID Number: ");
                scanf("%d", &studID);
                getchar();
                printf("Enter student name to call out: ");
                fgets(studName, sizeof(studName), stdin);
                studName[strcspn(studName, "\n")] = '\0';
                printf("Are a VIP student? (Y/N): ");
                scanf(" %c", &vip);

                if (vip == 'y' || vip == 'Y'){
                    vipp = 1;
                } else if (vip == 'n' || vip == 'N'){
                    vipp = 0;
                } else {
                    printf("\nSystem Error! Invalid choice.\n\n");
                    break;
                }

                enqueueStudent(line, studID, studName, vipp);
                printf("\nRequest Submitted! Please wait for your name to be called.\n\n");
                break;
            case 3:
                displayLine(line);
                break;
            case 4:
                free(line);
                printf("\nThank you for using the US Library. Hoped you enjoyed reading! Goodbye!");
                return 0;
            default:
                printf("\nSystem Error! Invalid choice.\n\n");
                break;
        }
    }
    return 0;
}

Queue* initialize(){
    Queue* line = (Queue*)malloc(sizeof(Queue));
    line->front = NULL;
    line->rear = NULL;

    return line;
}

bool isEmpty(Queue* q){
    return (q->front == NULL);
}

Node* createNode (int studID, char* studName, int vip){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("\nSystem Error! Memory allocation failed.\n\n");
        return NULL;
    }
    newNode->student.studentID = studID;
    strcpy(newNode->student.name, studName);
    newNode->student.isVIP = vip;
    newNode->next = NULL;

    return newNode;
}

void enqueueStudent (Queue* q, int studID, char* studName, int vip){
    Node* newNode = createNode(studID, studName, vip);

    if(isEmpty(q)){
        q->front = q->rear = newNode;
    } else if (vip == 1){
        newNode->next = q->front;
        q->front = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void displayLine (Queue* q){
    if(isEmpty(q)){
        printf("\nNo one is currently queueing.\n\n");
        return;
    }
    printf("\nStudents In Queue\n");
    Node* current = q->front;
    while (current != NULL){
        printf("\nStudent ID: %d\n", current->student.studentID);
        printf("Student Name: %s\n", current->student.name);
        printf("VIP? ");
        if(current->student.isVIP == 1){
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        current = current->next;
    }
    printf("\n");
}
