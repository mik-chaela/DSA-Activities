#include <stdio.h>

int divideByPowerOfTwo (int num, int power){
    if(num < 0){
        return (num + ( 1 << power) - 1) >> power;
    } else {
        return num >> power;
    }
}

int main(){
    printf("100 divided by 8 is: %d\n", divideByPowerOfTwo(100, 3));
    printf("-100 divided by 8 is: %d\n", divideByPowerOfTwo(-100, 3));

    return 0;
}