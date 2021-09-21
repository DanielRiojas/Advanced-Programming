//In this example, the user is asked to enter two integers. Then, the sum of these two integers is calculated and displayed on the screen.

#include<stdio.h>

int main(){

    int num1, num2, sum;
    printf("Enter to digits: ");
    scanf("%d %d", &num1, &num2);

    sum = num1 + num2;
    printf("%d + %d = %d\n", num1, num2, sum);

    return 0;
}