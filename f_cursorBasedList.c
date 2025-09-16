#include<stdio.h>

#define MAX 5

typedef struct {
  int elem;
  int next;
} Cell, HeapSpace[MAX];

typedef struct {
  HeapSpace H;
  int avail;
} VHeap;

typedef int List;

void initialize(VHeap* V);
int allocSpace(VHeap* V);
void deallocSpace(VHeap* V, int index);
void insertFirst(int* L, VHeap* V, int elem);
void insertLast(int* L, VHeap* V, int elem);
void insertSorted(int* L, VHeap* V, int elem);
void delete (int* L, VHeap* V, int elem);
void deleteAllOccurrence (int* L, VHeap* V, int elem);
void display(int L, VHeap V);

int main(){
	VHeap V;
	List L = -1; //start empty
	initialize(&V);
	
    printf("Before\n");
	insertFirst(&L, &V, 5);
    display(L, V);

    printf("\nInserting First...\n");
    insertFirst(&L, &V, 2);
    display(L, V);

    printf("\nInserting Last...\n");
    insertLast(&L, &V, 10);
    display(L, V);

    printf("\nInserting Sorted Number 8 and 5...\n");
    insertSorted(&L, &V, 8);
    insertSorted(&L, &V, 5 );
    display(L, V);

    printf("\nDeleting Number 10...\n");
    delete(&L, &V, 10);
    display(L, V);

    printf("\nDeleting All Occurences of Number 5...\n");
    deleteAllOccurrence(&L, &V, 5);
    display(L, V);
   
    return 0;
}

void initialize(VHeap* V){
	V->avail = 0;
	for(int i = 0; i < MAX - 1; i++){
        V->H[i].next = i + 1;
    }
    V->H[MAX - 1].next = -1; //end of the list
}

int allocSpace(VHeap* V){
	int ret = V->avail;
	if(ret != -1){
		V->avail = V->H[ret].next;
	}
	return ret;
}

void deallocSpace(VHeap* V, int index){
	V->H[index].next = V->avail;
	V->avail = index;
}

void insertFirst(int* L, VHeap* V, int elem){
	int newCell = allocSpace(V);
	if(newCell != -1){
		V->H[newCell].elem = elem;
		V->H[newCell].next = *L;
        *L = newCell;
	} else {
        printf("No space available.\n");
    }
}

void insertLast(int* L, VHeap* V, int elem){
	int newCell = allocSpace(V);
	if(newCell != -1){
		V->H[newCell].elem = elem;
		V->H[newCell].next = -1;
		
        if(*L == -1){
            *L = newCell;
        } else {
            int trav = *L;
            while(V->H[trav].next != -1){
                trav = V->H[trav].next;
            }
           V->H[trav].next = newCell;
        }
	} else {
        printf("No space available.\n");
    }
}

void insertSorted(int* L, VHeap* V, int elem){
    int newCell = allocSpace(V);
    if(newCell != -1){
        V->H[newCell].elem = elem;
        V->H[newCell].next = -1;

        //Insert first logic
        if(*L == -1 || elem <= V->H[*L].elem){
            V->H[newCell].next = *L;
            *L = newCell;
        } else {
            int prev = *L;
            int current = V->H[prev].next;
            while(current != -1 && V->H[current].elem < elem){
                prev = current;
                current = V->H[current].next;
            }
            V->H[newCell].next = current;
            V->H[prev].next = newCell;
        }
    } else {
        printf("No space available.\n");
    }
}

void delete (int* L, VHeap* V, int elem){
    int* trav, temp;
    trav = L;

    while(*trav != -1 && V->H[*trav].elem != elem){
        trav = &V->H[*trav].next;
    }

    if(*trav != -1){
        temp = *trav;
        *trav = V->H[*trav].next;
        deallocSpace(V, temp);
    } else {
        printf("Number not found.\n");
    }
}

void deleteAllOccurrence (int* L, VHeap* V, int elem){
    int* trav = L;

    while(*trav != -1){
        if(V->H[*trav].elem == elem){
            int temp = *trav;
            *trav = V->H[*trav].next;
            deallocSpace(V, temp);
        } else{
            trav = &V->H[*trav].next;
        }
    }
}

void display(int L, VHeap V){
    printf("List: ");
    for(int i = L; i != -1; i = V.H[i].next){
        printf("%d -> ", V.H[i].elem);
    }
    printf("NULL\n");
}