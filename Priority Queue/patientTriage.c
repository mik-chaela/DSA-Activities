#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[50];
    int priority;
    struct node* next;
} Node;

typedef struct {
    Node* front;
} PriorityQueue;

int main (){
    
}