#include <stdio.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List;

List initializeList ();
List insertPosition (List L, int pos, int data);
List insertSorted (List L, int data);
//List deletePosition (List L, int pos);
void displayList(List L);

int main (){
    List L = initializeList();

    L = insertPosition(L, 0, 10);
    L = insertPosition(L, 1, 20);
    L = insertPosition(L, 2, 30);
    //L = insertPosition(L, 2, 35);
    L = insertPosition(L, 3, 40);

    displayList (L);
    
    L = insertSorted (L, 12);
    
    //L = deletePosition (L, 2);

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
	int key, j; 
	
	for(int i = 1; i < L.count; i++) {
		key = L.elem[i];
		j = i - 1;
		
		while (j >= 0 && L.elem[j] > key){
			L.elem[]
		}
	}	
}

/*
List deletePosition (List L, int pos){
	
	for (int i = 0; i < L.count; i++){
		if (i == pos){
			
		}
	}
}
*/

void displayList(List L){
    printf("Data found in the List:\n");
    for (int i = 0; i < L.count; i++){
        printf("Index %d: %d\n", i, L.elem[i]);
    }
	printf("Total Data Found: %d\n\n", L.count);
}