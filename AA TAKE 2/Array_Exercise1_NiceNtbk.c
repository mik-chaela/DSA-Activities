#include <stdio.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    char elem[MAX];
    int count;
} charList;

void deleteElem(charList* L, char X) {
    int removed = 0;

    for (int i = 0; i < L->count; i++) {
        if (!removed && L->elem[i] == X) {
            for (int j = i; j < L->count - 1; j++) {
                L->elem[j] = L->elem[j + 1];
            }
            L->count--;  
            removed = 1;  
            i--; 
        }
    }
}

void deleteAllOccur(charList* L, char X) {
    for (int i = 0; i < L->count; ) { 
        if (L->elem[i] == X) {
            for (int j = i; j < L->count - 1; j++) {
                L->elem[j] = L->elem[j + 1];
            }
            L->count--; 
        } else {
            i++;  
        }
    }
}

bool findElem (charList L, char X){
    int i;
    for (i = 0; i < L.count && X != L.elem[i]; i++);
    return (i < L.count) ? true : false;
}

int main() {
    charList L = {{'U', 'S', 'C', 'C', 'E', 'B', 'U'}, 7};
    bool ans = findElem (L, 'Z');
    if(ans){
        printf("True\n\n");
    } else {
        printf("False\n\n");
    }
    
    deleteElem(&L, 'Z');
    for (int i = 0; i < L.count; i++) {
        printf("%c\n", L.elem[i]);
    }
    printf("\n");
    deleteAllOccur(&L, 'U');
    for (int i = 0; i < L.count; i++) {
        printf("%c\n", L.elem[i]);
    }

    return 0;
}
