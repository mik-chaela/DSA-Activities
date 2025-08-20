#include <stdio.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List;

List initializeList ();
List insertPosition (List L, int pos, int data); //Insert data at a desired index
List insertSorted (List L, int data); //Insert data in a sorted manner
List deletePosition (List L, int pos); //Deletes a data at a given position
void displayList(List L);

int main (){
    List L = initializeList();

    L = insertPosition(L, 0, 10);
    L = insertPosition(L, 1, 20);
    L = insertPosition(L, 2, 30);
    L = insertPosition(L, 2, 35);
    L = insertPosition(L, 3, 40);
    printf("List After Inserting Data into Desired Positions\n");
    displayList (L);
    
    L = insertSorted(L, 12);
    printf("List After Inserting Data Sorted\n");
    displayList (L);
    
    L = deletePosition (L, 3);
    printf("List After Deleting Position\n");

    return 0;
}

List initializeList (){
	List L;
	
	L.count = 0;
	
	for(int i = 0; i < MAX; i++){
		L.elem[i] = -1;
	}
	
	return L;
}

List insertPosition(List L, int pos, int data){
    if (pos < 0 || pos > L.count || L.count >= MAX) {
        return L;
    }

    for (int i = 0; i <= L.count; i++){
        if(i == pos){
        	if (L.elem[i] != -1){
        		L.elem[pos] = data;
        		L.count--;
			}
            L.elem[pos] = data;
            L.count++;
        }
    }

    return L;
}

List insertSorted (List L, int data){
	if (L.count >= MAX) {
        return L; 
    }

    int pos = 0;

    while (pos < L.count && L.elem[pos] < data){
        pos++;
    }

    for (int i = L.count; i > pos; i--){
        L.elem[i] = L.elem[i - 1];
    }

    L.elem[pos] = data;
    L.count++;

    return L;
}

List deletePosition (List L, int pos){
	
	for (int i = 0; i < L.count; i++){
		if (i == pos){
			
		}
	}
}

void displayList(List L){
    for (int i = 0; i < L.count; i++){
        printf("Index %d: %d\n", i, L.elem[i]);
    }
	printf("Total Data Found: %d\n\n", L.count);
}