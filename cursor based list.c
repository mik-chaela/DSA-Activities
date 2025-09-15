#include<stdio.h>

#define MAX 4

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

int main(){
	VHeap* V;
	List* L;
	initialize(V);
	
	insertFirst(L, V, 5);
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
	V->avail = V->H[index];
}

void insertFirst(int* L, VHeap* V, int elem){
	int newCell = allocSpace(V);
	if(newCell != -1){
		V->H[newCell].elem = elem;
		V->H[newCell].next = *L;
	}
	*L = newCell;
}

void insertFirst(int* L, VHeap* V, int elem){
	int newCell = allocSpace(V);
	if(newCell != -1){
		V->H[newCell].elem = elem;
		V->H[newCell].next = *L;
	}
	*L = newCell;
}

void insertLast(int* L, VHeap* V, int elem){
	int newCell = allocSpace(V);
	if(newCell != -1){
		V->H[newCell].elem = elem;
		V->H[newCell].next = -1;
		
		int* trav = L;
		while(*trav != -1){
			trav = &V->H[*trav].next;
		}
		*trav = newCell;
	}
}

void initialize(VHeap* V){
	V->avail = 0;
	while
}
