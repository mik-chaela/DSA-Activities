#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 128

typedef struct node{
    char elem[MAX];
    int top;
}Stack;

void Push(Stack* S, char x);
void Pop(Stack* S);
char Top(Stack S);
void initStack(Stack* S);

bool isFull(Stack S);
bool isEmpty(Stack S);

// your task is this function!
bool isPalindrome(char palindrome[]);

int main(){
    char palindrome[MAX];
    printf("Enter string: ");
    scanf("%s", palindrome);

    printf("Palindrome? %s", (isPalindrome(palindrome)) ? "Yes!" : "No!");
}
/*

bool isPalindrome(char palindrome[]){
    // implement here!!
    Stack Stack1, Stack2;
    int numLetters = strlen(palindrome);

    initStack(&Stack1);
    initStack(&Stack2);

    for(int i = 0 ; i < numLetters; i++){
        Push(&Stack1, palindrome[i]);
    }

    for(int i = 0 ; i < numLetters/2; i++){
        Push(&Stack2, palindrome[i]);
    }

    if(numLetters % 2 != 0){
        Pop(&Stack1);
    }
    
    while(!isEmpty(Stack2)){
        char c1 = Top(Stack2);
        Pop(&Stack2);
        char c2 = Top(Stack1);
        Pop(&Stack1);

        if(c1 != c2){
            return false;
        }
    }

    return true;
}
*/

bool isPalindrome(char palindrome[]){
    Stack Stack1, Stack2;
    int numLetters = strlen(palindrome);

    initStack(&Stack1);
    initStack(&Stack2);


    for(int i = 0 ; i < numLetters; i++){
        Push(&Stack1, palindrome[i]);
    }

    for(int i = numLetters - 1; i > numLetters / 2; i--){
        Push(&Stack2, palindrome[i]);
    }

    int remove = (numLetters + 1) / 2;
    for(int i = 0 ; i < remove; i++){
        Pop(&Stack1);
    }
    
    while(!isEmpty(Stack2)){
        char c1 = Top(Stack2);
        Pop(&Stack2);
        char c2 = Top(Stack1);
        Pop(&Stack1);


        if(c1 != c2){
            return false;
        }
    }

    return true;
}

void Push(Stack* S, char x){
    if(!isFull(*S)){
        S->elem[++(S->top)] = x;
    }

}

void Pop(Stack* S){
    if(!isEmpty(*S)){
        S->top--;
    }
}

char Top(Stack S){
    return S.elem[S.top];
}

void initStack(Stack* S){
    S->top = -1;
}

bool isFull(Stack S){
    return S.top == MAX - 1;
}

bool isEmpty(Stack S){
    return S.top == -1;
}

