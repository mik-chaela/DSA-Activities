#include <stdio.h>

int Hash_hundredths(int num){
    return (num/100) % 10;
}

int main (){
    int num;

    printf("Enter number: ");
    scanf("%d", &num);

    int ans = Hash_hundredths(num);

    printf("Number found in hundredths place: %d", ans);

    return 0;
}