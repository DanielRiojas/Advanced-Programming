//In this example, the product of two floating-point numbers entered by the user is calculated and printed on the screen.
#include<stdio.h>

int main() {
    float num1, num2, product;
    printf("Enter to digits: ");
    scanf("%f %f", &num1, &num2);

    product = num1 * num2;
    printf("%f * %f = %f\n", num1, num2, product);

    return 0;
}