#include <stdio.h>
#include <stdbool.h>   

#define MAX 10  

typedef struct {
    char elem[MAX];   
    int count;        
} charList;

bool findElem(charList L, char X);

int main() {
    charList L;

    L.count = 3;
    L.elem[0] = 'U';
    L.elem[1] = 'S';
    L.elem[2] = 'C';

    // Test cases
    char test1 = 'S';
    char test2 = 'A';

    printf("Is '%c' in the list? %s\n", test1, findElem(L, test1) ? "true" : "false");
    printf("Is '%c' in the list? %s\n", test2, findElem(L, test2) ? "true" : "false");

    return 0;
}

bool findElem(charList L, char X) {
    bool found = false;  

    for (int i = 0; i < L.count; i++) {
        if (L.elem[i] == X) {
            found = true;   
        }
    }

    return found;  
}