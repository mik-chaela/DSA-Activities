/*REFRESHER ON LINKED LIST
Node insertAtBeginning(Node* head, int data); //pass by copy (pointer to node)
insertAtBeginning(head, 5); //pass by copy

void insertAtBeginning(struct node** head, int data); //pass by reference (pointer to pointer)
insertAtBeginning(&head, 5); //pass by reference
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
    int elem;
    struct node* next;
} *Node;

Node createNode(int data);
Node insertFirst (Node head, int data);
void displayList (Node head);

int main (){
    Node head = NULL;

    head = createNode(20);
    displayList (head);

    insertFirst(head, 31);

}

Node createNode(int data){
    Node newnode;

    newnode = (Node) malloc (sizeof(struct node));

    if(newnode == NULL){
        printf("Mmemory allocation failed.\n");
        return 0;
    }

    newnode->elem = data;
    newnode->next = NULL;

    return newnode;
}

void displayList (Node head){
    Node current = head;

    while (current != NULL){
        printf("%d -> ", current->elem);
        current = current->next;
    }
    printf("NULL\n");
}