//In this program, the integer entered by the user is stored in a variable and printed on the screen.

#include<stdio.h>

int main() {

    int number = 0;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("The number entered is: %d\n", number);

    return 0;
}