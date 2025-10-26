#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SET_SIZE 8

typedef struct node{
    unsigned char set;
    struct node* next;
} Node;

void initialize(unsigned char set){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Error: Memory Allocation Failed.\n");
        return;
    }
    newNode->set = 0;
    newNode->next = NULL;
}

int main (){
    Node* head = NULL;
    
}