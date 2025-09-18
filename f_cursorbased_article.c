#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

// initVHeap
void initVHeap(VHeap* V){
    V->avail = 0;
    for(int i = 0; i < MAX_SIZE - 1; i++){
        V->H[i].next = i + 1;
    }
    V->H[MAX_SIZE - 1].next = -1;
}

// alloc
int alloc(VHeap* V){
    int ret = V->avail;
    if(ret != - 1){
        V->avail = V->H[ret].next; 
    }
    return ret;
}

// dealloc
void dealloc(VHeap* V, int index){
    V->H[index].next = V->avail;
    V->avail = index;
}

// insertArticle
int insertArticle(VHeap* V, int* L, Article article, int index){
    int newCell = alloc(V);
    int trav;
    
    if(newCell != -1){
        V->H[newCell].article.id = article.id;
        strcpy(V->H[newCell].article.title, article.title);
        strcpy(V->H[newCell].article.content, article.content);
        V->H[newCell].next = -1;
        
        if(index == 0){
           V->H[newCell].next = *L;
           *L = newCell;
        } else if (index != 0 && index != -1){
            trav = *L; // start at head
            for(int i = 0; i < index - 1 && trav != -1; i++){
                trav = V->H[trav].next;
            }
            if (trav != -1) { // valid position
                V->H[newCell].next = V->H[trav].next;
                V->H[trav].next = newCell;
            } else {
                printf("Invalid index.\n");
                dealloc(V, newCell); // free allocated cell
            }
        } else if(index == -1){
            trav = *L;
            
            while(V->H[trav].next != -1){
                trav = V->H[trav].next;
            }
            V->H[trav].next = newCell;
        } 
    } else {
        printf("Error: Heap is full. Cannot insert new article.\n");
    }
    
    
}

// viewArticles
void viewArticles(VHeap V, int L){
    printf("\n--- List of Articles ---\n");
    for(int i = L; i != -1; i = V.H[i].next){
        printf("ID: %d | Title: %s\n", V.H[i].article.id, V.H[i].article.title);
    }
    printf("------------------------\n\n");
}

// searchArticle
void searchArticle(VHeap V, int L, int id){
    int trav = L;
    while(trav != -1 && V.H[trav].article.id != id){
        trav = V.H[trav].next;
    }
    if (trav != -1){
        printf("\n--- Article Found ---\n");
        printf("ID: %d\nTitle: %s\n", V.H[trav].article.id, V.H[trav].article.title);
        printf("Content: %s.\n", V.H[trav].article.content);
        printf("---------------------\n\n");
    } else {
        printf("Article with ID %d not found.\n\n", id);
    }
}


// deleteArticle
int deleteArticle(VHeap* V, int* L, int id){
    if(*L == -1){
        printf("The knowledge base is empty.\n");
        return -1;
    }
    
    int* trav, temp;
    trav = L;
    
    while(*trav != -1 && V->H[*trav].article.id != id){
        trav = &V->H[*trav].next;
    }
    
    if(*trav != -1){
        temp = *trav;
        *trav = V->H[*trav].next;
        dealloc(V, temp);
        printf("Article with ID %d deleted successfully.\n\n", id);
    } else {
        printf("Article not found.\n\n");
    }
}