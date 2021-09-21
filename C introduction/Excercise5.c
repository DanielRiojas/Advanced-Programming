//In this program, you will how to find the ASCII value of a character.
#include<stdio.h>

int main (){
    char chr;
    printf("Enter a character: ");
    scanf("%c", &chr);

    printf("The ASCII value of %c is %d\n", chr, chr);

    return 0;
}