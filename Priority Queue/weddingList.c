#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // Required for boolean return types

// --- STRUCT DEFINITIONS ---

typedef struct node {
    char name[50];
    char role[50];  // Stores "Bride", "Groom", "Family", etc.
    int priority;   // Calculated based on role
    struct node* next;
} Node;

typedef struct {
    Node* front;
} PriorityQueue;

// --- FUNCTION PROTOTYPES ---

PriorityQueue* initialize();
void enqueue(PriorityQueue* pq, char* name, char* role);
char* dequeue(PriorityQueue* pq);
bool isGuestInQueue(PriorityQueue* pq, char* targetName);
void findGuestsLike(PriorityQueue* pq, char* roleFragment);
void display(PriorityQueue* pq);

// --- MAIN FUNCTION (TESTING) ---

int main() {
    // 1. Initialize
    printf("Initializing Wedding Guest Queue...\n");
    PriorityQueue* weddingQ = initialize();

    // 2. Enqueue Guests (Simulating arrival)
    // Note: You need to implement logic to auto-assign priority based on role!
    // Priority Rules: Bride/Groom (100) > Family (50) > VIP (20) > Others (1)
    
    printf("\n--- Guests Arriving ---\n");
    enqueue(weddingQ, "John Smith", "Regular Guest");
    enqueue(weddingQ, "Maria Clara", "Mother of Family");
    enqueue(weddingQ, "Alice Guo", "VIP Sponsor");
    enqueue(weddingQ, "Jose Rizal", "Groom"); 
    
    // 3. Display Queue
    display(weddingQ);

    // 4. Test Search
    printf("\n--- Searching for 'Alice Guo' ---\n");
    if (isGuestInQueue(weddingQ, "Alice Guo")) {
        printf("Yes, she is on the list.\n");
    } else {
        printf("Not found.\n");
    }

    printf("\n--- Finding all 'Family' members ---\n");
    findGuestsLike(weddingQ, "Family");

    // 5. Dequeue (Seating)
    printf("\n--- Seating Guests (High Priority First) ---\n");
    
    char* seatedGuest;
    
    seatedGuest = dequeue(weddingQ);
    if (seatedGuest) {
        printf("Seated: %s\n", seatedGuest);
        free(seatedGuest); // Important: Free the string returned by dequeue
    }

    seatedGuest = dequeue(weddingQ);
    if (seatedGuest) {
        printf("Seated: %s\n", seatedGuest);
        free(seatedGuest);
    }

    printf("\n");
    // Display remaining
    display(weddingQ);

    return 0;
}

// --- IMPLEMENT YOUR FUNCTIONS BELOW ---

// 1. Initialize the queue
PriorityQueue* initialize() {
    // TODO: Allocate memory for PriorityQueue
    // TODO: Set front to NULL
    // TODO: Return the pointer

    PriorityQueue* wedding = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    wedding->front = NULL;
    return wedding;
}

// 2. Add guest (Sorted Insert)
void enqueue(PriorityQueue* pq, char* name, char* role) {
    // TODO: Allocate memory for newNode
    // TODO: strcpy name and role
    
    // TODO: Calculate Priority
    // If role is "Bride" or "Groom" (strcmp) -> 100
    // If role contains "Family" (strstr) -> 50
    // If role contains "VIP" (strstr) -> 20
    // Else -> 1

    // TODO: Insert into list based on priority (Head insert OR Traversal)

    Node* newGuest = (Node*)malloc(sizeof(Node));
    newGuest->next = NULL;
    strcpy(newGuest->name, name);
    strcpy(newGuest->role, role);

    if(strcmp(newGuest->role, "Bride") == 0 || strcmp(newGuest->role, "Groom") == 0){
        newGuest->priority = 100;
    } else if (strstr(newGuest->role, "Family") != NULL){
        newGuest->priority = 50;
    } else if (strstr(newGuest->role, "VIP") != NULL){
        newGuest->priority = 20;
    } else {
        newGuest->priority = 1;
    }

    if(pq->front == NULL || newGuest->priority > pq->front->priority){
        newGuest->next = pq->front;
        pq->front = newGuest;
    } else {
        Node* temp = pq->front;
        while(temp->next != NULL && temp->next->priority >= newGuest->priority){
            temp = temp->next;
        }
        newGuest->next = temp->next;
        temp->next = newGuest;
    }
}

// 3. Remove highest priority guest
char* dequeue(PriorityQueue* pq) {
    // TODO: Check if empty
    // TODO: Save name to a new char* buffer (malloc) using strcpy
    // TODO: Move front pointer
    // TODO: Free the old node
    // TODO: Return the saved name

    if(pq->front == NULL){
        printf("No Guest/s Found.\n\n");
        return NULL;
    }
    char* buffer = malloc(strlen(pq->front->name) + 1);
    strcpy(buffer, pq->front->name);

    Node* temp = pq->front;
    pq->front = pq->front->next;
    free(temp);

    return buffer; 
}

// 4. Check if exact name exists
bool isGuestInQueue(PriorityQueue* pq, char* targetName) {
    // TODO: Loop through list
    // TODO: Use strcmp to compare names
    // TODO: Return true if found, false otherwise

    if(pq->front == NULL){
        printf("No Guest/s Found.\n\n");
        return false;
    }

    Node* current = pq->front;
    while(current != NULL){
        if(strcmp(current->name, targetName) == 0){
            return true;
        }
        current = current->next;
    }
    return false;
}

// 5. Find guests with partial role match
void findGuestsLike(PriorityQueue* pq, char* roleFragment) {
    // TODO: Loop through list
    // TODO: Use strstr to see if roleFragment is inside temp->role
    // TODO: Print details if match found

    if(pq->front == NULL){
        printf("No Guest/s Found.\n\n");
        return;
    }

    Node* current = pq->front;
    while(current != NULL){
        if(strstr(current->role, roleFragment) != NULL){
            printf("%s \n", current->name);
        }
        current = current->next;
    }
}

// 6. Print the whole list
void display(PriorityQueue* pq) {
    // TODO: Loop through list
    // TODO: Print Name, Role, and Priority

    printf("Guest/s Found in the List:\n");
    Node* current = pq->front;
    while(current != NULL){
        printf("Guest Name: %s\n", current->name);
        printf("Role: %s\n", current->role);
        printf("Priority Level: %d\n\n", current->priority);
        current = current->next;
    }
}