/*
Variation 1 on ADT List
- List is a STATIC ARRAY and accessed by VALUE
*/

#include <stdio.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List;

List initializeList ();
List insertPosition (List L, int pos, int data); //Insert data at a desired index, shift elements if necessary
List insertSorted (List L, int data); //Insert data in a sorted manner
List deletePosition (List L, int pos); //Deletes a data at a given position, shifts element to the left to fill out the space
int locate (List L, int data); //Loop through the array and return the position if found, unless return -1
void displayList(List L);

int main (){
    List L = initializeList();

    L = insertPosition(L, 0, 10);
    L = insertPosition(L, 1, 20);
    L = insertPosition(L, 2, 30);
    L = insertPosition(L, 3, 40);
    L = insertPosition(L, 3, 35);
    printf("List After Inserting Data into Desired Positions\n");
    displayList (L);

    L = insertSorted(L, 12);
    printf("List After Inserting Data '12' in a Sorted Manner\n");
    displayList (L);
  
    L = deletePosition (L, 3);
    printf("List After Deleting 3rd Position (30)\n");
    displayList (L);

    int found = locate(L, 12);
    if (found != -1){
        printf("Data is found in position %d\n", found);
    } else {
        printf("Data not found.\n");
    }

    return 0;
}

List initializeList (){
	List L;
	
    L.count = 0;
    for(int i = 0; i < MAX; i++){
        L.elem[i] = 0;
    }
	
	return L; //return list
}

List insertPosition(List L, int pos, int data){
    if (pos < 0 || pos > L.count || L.count >= MAX) { //checking if position is either negative number, greater than the count, or
        printf("Invalid Format.\n");                 // or greater than the list capacity.
        return L; //return current list
    }

    for(int i = L.count; i > pos; i--){ // iteration begins on the last element on the list. If it reaches the desired position, elements are
        L.elem[i] = L.elem[i - 1];      // shifted to the right to make space for the new data
    }

    L.elem[pos] = data; // new data is inserted
    L.count++; // count is incremented

    return L; //return modified list
}

List insertSorted (List L, int data){ //array is assumed to be in a sorted manner
	if (L.count >= MAX) {           //checks if list is full
        printf("List is full.\n");
        return L; //return current list
    }

    int pos = 0; //position is initialized to zero

    //finding the position where the new data will be inserted
    while (pos < L.count && L.elem[pos] < data){ 
        pos++;
    }

    //shifts elements to the right to make space for the new data
    for (int i = L.count; i > pos; i--){
        L.elem[i] = L.elem[i - 1];
    }

    L.elem[pos] = data; // new data is inserted
    L.count++; // count is incremented

    return L; //return modified list
}

List deletePosition (List L, int pos){
	if (pos < 0 || pos >= L.count){     //verifies if the position is valid
        printf("Position not found.\n");
        return L; //return current list
    }

	for (int i = pos; i < L.count; i++){ //iteration begins on the position to be deleted.
        L.elem[i] = L.elem[i + 1]; //elements are shifted to the left to fill in the position
	}
    L.count--; //count is decremented

    return L; //return modified list
}

int locate (List L, int data){
    for(int i = 0; i < L.count; i++){ //iteration begins on the first index
        if(data == L.elem[i]){ //if data is found, return index
            return i;
        }
    }
    return -1; //otherwise return -1
}

void displayList(List L){ //loop through the list and display the elements with its respective positions
    for (int i = 0; i < L.count; i++){
        printf("Index %d: %d\n", i, L.elem[i]);
    }
	printf("Total Data Found: %d\n\n", L.count); //displays the total count in the list
}