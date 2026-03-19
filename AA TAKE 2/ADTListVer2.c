#include <stdio.h>
#include <stdlib.h>

#define MAX 10
typedef struct {
    char Elements[MAX];
    int count;
} *List;

void initList(List* L){
    *L = malloc(sizeof(**L));   

    if (*L != NULL) {
        (*L)->count = 0;
        printf("%d, List is empty.\n", (*L)->count);
    }
}

int main(){
    List L;
    initList(&L);

    free(L);  
    return 0;
}