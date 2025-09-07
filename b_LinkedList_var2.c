#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* head;
    int count;
} List;

List* initialize ();
void insertFirst (List* list, int data);
void insertLast(List* list, int data);
void insertPos (List* list, int data, int index);
void deleteStart (List* list);
void deleteLast (List* list);
void deletePos (List* list, int index);
int retrieve (List* list, int index);
int locate (List* list, int data);
Node* createNode (int data);
void display (List* list);
void empty (List* list);

int main () {
    List* L = initialize ();
    int Data, pos;
    int choice;

    while (1){
        printf("Which process do you want today?\n"
               "(1) Insert First\t(6) Delete at Position\n"
               "(2) Insert Last\t\t(7) Retrieve Number\n"
               "(3) Insert at Position\t(8) Locate Position\n"
               "(4) Delete Start\t(9) Display Current List\n"
               "(5) Delete Last\t\t(10) Exit Program\n\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter number: ");
                scanf("%d", &Data);
                insertFirst(L, Data);
				display(L);
                break;
            case 2:
                printf("Enter number: ");
                scanf("%d", &Data);
                insertLast(L, Data);
				display(L);
                break;
            case 3:
                printf("Enter number to insert: ");
                scanf("%d", &Data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertPos(L, Data, pos);
				display(L);
                break;
            case 4:
                deleteStart (L);
				display(L);
                break;
            case 5:
                deleteLast(L);
				display(L);
                break;
			case 6:
				printf("Enter position to delete: ");
				scanf("%d", &pos);
				deletePos (L, pos);
				display(L);
				break;
			case 7:
				printf("Enter position to retrieve number: ");
				scanf("%d", &pos);

				int found = retrieve(L, pos);
				if (found != -1) {
					printf("Data found in position %d is: %d\n\n", pos, found);
				} else {
					printf("No data retrieved\n\n");
				}
				break;
			case 8:
				printf("Enter data to locate: ");
				scanf("%d", &Data);

				int location = locate(L, Data);
				if(location != -1){
					printf("Data %d is found in position: %d\n\n", Data, location);
				} else {
					printf("No data found in that position\n\n");
				}
				break;
			case 9:
				display(L);
				break;
            case 10:
                empty (L);
				printf("List has been emptied\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}

Node* createNode (int data){
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL){
        printf("Memory allocation failed.\n");
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertFirst (List* list, int data){
    Node* newNode = createNode(data); // Allocating memory for the newNode

    if(newNode == NULL) return; //Checking if successful memory allocation for newNode
    
    newNode->next = list->head; //Set the next pointer of the newNode to the current head of the list
    list->head = newNode; //Update the list's head pointer to point to the newNode
    list->count++; //Increment the list's count
}

void insertLast(List* list, int data){
    Node* newNode = createNode(data); //Allocating memory for the newNode

    if(newNode == NULL) return; //Checking if successful memory allocation for newNode
    
    //If list is empty, set head to newNode
    if(list->head == NULL) {
        list->head = newNode;
        list->count++;
        return;
    }

    //Traverse to the last node
    Node* current = list->head;
    while (current->next != NULL){
        current = current->next;
    }

    //Attach new node at the end
    current->next = newNode;
    list->count++;
}

void insertPos (List* list, int data, int index){
    //Check if index is valid (less than the count)
    if (index > list->count){
        printf("Invalid index.\n");
        return;
    }

    //If index is 0, insertFirst function is called
    if(index == 0) {
        insertFirst(list, data);
        return;
    }

    //If index is equal to count, insertLast is called
    if(index == list->count){
        insertLast(list, data);
        return;
    }

    //Otherwise, create newNode and allocate memory
    Node* newNode = createNode(data);
    Node* current = list->head; //Set current pointer to the head of the list
    
    //Iterating thru the  list until index-1 to find the node just before the insertion point
    for(int i = 0; i < index - 1; i++){
        current = current->next;
    }

    newNode->next = current->next; //set the newNode next pointer to the current->next
    current->next = newNode; //Set the current->next to the newNode
    list->count++; //Increment the list's count
}

void deleteStart (List* list){
    if(list->head == NULL){
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    Node* current = list->head; //Declaring current pointer and set it to head

    list->head = current->next; //Update the list's head to current->next
    free(current); //Freeing the memory for current
    list->count--; //Increment the list's count
}

void deleteLast (List* list){
    //List is empty
    if(list->head == NULL){
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    //The list has only one node
    if(list->head->next == NULL){
        free(list->head);
        list->head = NULL;
        list->count--;
        return;
    }

    // List has multiple nodes
    Node* current = list->head;
    for(int i = 0; i < list->count - 2; i++){
        current = current->next; //Loop to find the second to the last node
    }

    free(current->next);
    current->next = NULL;
    list->count--;
}

void deletePos (List* list, int index){
	//Index is 0, then call removeStart() function
	if(index == 0){
		deleteStart(list);
		return;
	}

	Node* current = list->head; //Declaring current variable and set it to the list's head
	for(int i = 0; i < index - 1; i++){
		current = current->next; //Iterate thru the list index - 1 times
	}

	Node* temp = current->next; //Declaring temp and set it to current->next
	current->next = temp->next; //Current->next is set to temp->next
	free(temp); //Freeing up the space of temp
	list->count--; //Decrement the list's count
}

int retrieve (List* list, int index){
	//Checking if index is greater than the count
	if (index > list->count) {
		printf("Invalid index.\n");
		return -1;
	}

	Node* current = list->head; //Declaring current and setting it to the list's head
	for(int i = 0; i < index; i++){
		current = current->next; //Iterating index times, moving current forward
	}

	return current->data; //Return the data in the current
}

int locate (List* list, int data){
	//Checking if the list is empty
	if (list->head == NULL){
		printf("List is empty.\n");
		return -1;
	}

	Node* current = list->head; //Declaring current and set it to the list's head
	int index = 0;
	while (current != NULL){
		if(current->data == data){
			return index;
		}
		current = current->next;
		index++;
	}
	return -1;
}

List* initialize (){
    List* L = (List*)malloc(sizeof(List)); //Allocating memory for the new List struct

    //Checking if successful memory allocation
    if(L == NULL){
        printf("Memory allocation failed.\n");
        return NULL;
    }

    L->head = NULL; //Set the head pointer of the list to NULL
    L->count = 0; //Set the count of the List to 0

    return L; //Return the pointer to the newly created List
}

void display (List* list){
    Node* current = list->head;

    printf("Data in the List: ");
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    printf("Total Count: %d\n\n", list->count);
}

void empty (List* list){
    Node* current = list->head;
    Node* temp;

    while(current != NULL){
        temp = current->next;
        free(current);
        current = temp;
    }

    list->head = NULL;
    list->count = 0;
}
