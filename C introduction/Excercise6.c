//In this program, you will find the quotient and remainder when an integer is divided by another integer.
#include<stdio.h>

int main(){
    int num1, num2, div, rem;
    printf("Write the dividend and divisor in that order: ");
    scanf("%d %d", &num1, &num2);
    
    //div
    div = num1 / num2;

    //rem
    rem = num1 % num2;

    printf("The division of %d / %d is %d and the remainder is %d\n", num1, num2, div, rem);
    return 0;
}