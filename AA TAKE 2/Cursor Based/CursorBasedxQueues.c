#include <stdio.h>
#include <string.h>

#define MAX 6
#define EMPTY -1

typedef struct {
    int orderID;
    char customerName[30];
    char snackItem[30];
    int quantity;
} Order;

typedef struct {
    Order data;
    int next;
} NodeType;

typedef struct {
    NodeType nodes[MAX];
    int avail;
} VirtualHeap;

typedef struct {
    int front;
    int rear;
} Queue;

/* Function Prototypes */
void initializeVirtualHeap(VirtualHeap *VH);
void initializeQueue(Queue *Q);
int allocSpace(VirtualHeap *VH);
void deallocSpace(VirtualHeap *VH, int index);

void enqueue(VirtualHeap *VH, Queue *Q, Order newOrder);   // answer this
void dequeue(VirtualHeap *VH, Queue *Q);                   // answer this
void displayQueue(VirtualHeap VH, Queue Q);                // answer this
int isEmpty(Queue Q);                                      // answer this
int isFull(VirtualHeap VH);                                // answer this

/* Helper function already given */
void insertSampleOrders(VirtualHeap *VH, Queue *Q);

int main() {
    VirtualHeap VH;
    Queue Q;

    initializeVirtualHeap(&VH);
    initializeQueue(&Q);

    insertSampleOrders(&VH, &Q);

    printf("Current Queue:\n");
    displayQueue(VH, Q);

    printf("\nDequeuing one order...\n");
    dequeue(&VH, &Q);

    printf("\nQueue after dequeue:\n");
    displayQueue(VH, Q);

    return 0;
}

/* Initializes the virtual heap */
void initializeVirtualHeap(VirtualHeap *VH) {
    int i;
    for (i = 0; i < MAX - 1; i++) {
        VH->nodes[i].next = i + 1;
    }
    VH->nodes[MAX - 1].next = EMPTY;
    VH->avail = 0;
}

/* Initializes the queue */
void initializeQueue(Queue *Q) {
    Q->front = EMPTY;
    Q->rear = EMPTY;
}

/* Allocates one node from the virtual heap */
int allocSpace(VirtualHeap *VH) {
    int space = VH->avail;
    if (space != EMPTY) {
        VH->avail = VH->nodes[space].next;
    }
    return space;
}

/* Returns a node back to the virtual heap */
void deallocSpace(VirtualHeap *VH, int index) {
    VH->nodes[index].next = VH->avail;
    VH->avail = index;
}

/* =========================
   FUNCTIONS FOR YOU TO DO
   ========================= */

int isEmpty(Queue Q) {
    /* Write your code here */
    return (Q.front == EMPTY);
}

int isFull(VirtualHeap VH) {
    /* Write your code here */
    return (VH.avail == -1);
}

void enqueue(VirtualHeap *VH, Queue *Q, Order newOrder) {
    /* Write your code here */
    int space = allocSpace(VH);
    if(space != EMPTY){
    	VH->nodes[space].data = newOrder;
    	VH->nodes[space].next = -1;
    	
    	if(isEmpty(*Q)){
    		Q->front = space;
    		Q->rear = space;
		} else {
			VH->nodes[Q->rear].next = space;
		}
		Q->rear = space;
	} else {
		printf("\n Queue is full. \n");
	}
}

void dequeue(VirtualHeap *VH, Queue *Q) {
    /* Write your code here */
    if(!isEmpty(*Q)){
    	deallocSpace(VH, Q->front);
		Q->front = Q->front + 1;		
	} else {
		printf("\n Nothing to dequeue. \n");
	}
}

void displayQueue(VirtualHeap VH, Queue Q) {
    /* Write your code here */    
    int trav;
    for(trav = Q.front; trav != -1; trav = VH.nodes[trav].next){
    	printf("Order Number: %d\n", VH.nodes[trav].data.orderID);
    	printf("Customer Name: %s\n", VH.nodes[trav].data.customerName);
    	printf("%d - %s\n\n", VH.nodes[trav].data.quantity, VH.nodes[trav].data.snackItem);
	}
}

/* Sample data insertion */
void insertSampleOrders(VirtualHeap *VH, Queue *Q) {
    Order o1 = {1001, "Alice", "Burger", 2};
    Order o2 = {1002, "Bob", "Fries", 1};
    Order o3 = {1003, "Charlie", "Pizza", 3};

    enqueue(VH, Q, o1);
    enqueue(VH, Q, o2);
    enqueue(VH, Q, o3);
}
