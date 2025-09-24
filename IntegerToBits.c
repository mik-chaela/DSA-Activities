#include <stdio.h>

void displayBit (char val){
/*  
    int size = sizeof(char) * 8;
    for(int i = size - 1; i >= 0; i--){
        int bit = (val >> i) & 1;
        printf("%d", bit);
        
    }
*/
    int bit = sizeof(char) * 8;
    unsigned int mask = 1 << (bit - 1);
    
    while (mask != 0){
        printf("%d", (val & mask)? 1 : 0);
        mask >>= 1;
    }
}

int main (){
    int num;
    printf("Enter num: ");
    scanf("%d", &num);
    
    displayBit(num);
    return 0;
}
