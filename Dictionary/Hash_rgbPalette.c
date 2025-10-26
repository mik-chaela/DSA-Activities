#include <stdio.h>

int Hash_RGB(int r, int g, int b){
    return ((r * 3) + (g * 31) + (b * 17)) % 64; //any prime number can do
}

int main (){
    int r, g, b;

    printf("Enter value of r: ");
    scanf("%d", &r);

    printf("Enter value of g: ");
    scanf("%d", &g);

    printf("Enter value of b: ");
    scanf("%d", &b);

    int ans = Hash_RGB (r,g,b);

    printf("%d\n", ans);
    

    return 0;
}