/*
1º) Muestre un menú con 5 opciones:

    1. Dividir dos números.
    2. Restar dos números.
    3. Multiplicar dos números.
    4. Sumar dos números.
    5. Salir.

2º) Pida por teclado la opción deseada. Deberá ser introducida y validada, mientras que, sea mayor o igual que '1' y menor o igual que '5'.

3º) Ejecute la opción seleccionada del menú y muestre el resultado en pantalla.

4º) Repita los pasos 1º, 2º y 3º, mientras que, el usuario no seleccione la opción 5 (Salir) del menú.
*/
#include<stdio.h>

int main(){
    int opt;

    do{
        printf("Menú:\n");
        printf("1. Dividir dos números.\n");
        printf("2. Restar dos números.\n");
        printf("3. Multiplicar dos números.\n");
        printf("4. Sumar dos números.\n");
        printf("5. Salir.\n");
        scanf("%d", &opt);

        //Validar Opción
        if(opt < 1 || opt > 5){
            printf("Opción no válida, ingrese otra\n");
            continue;
        }
        int num1, num2;
        float ans;

        printf("Escribe el primer número:");
        scanf("%d", &num1);
        printf("Escribe el segundo número:");
        scanf("%d", &num2);

        switch (opt) {
        case 1:
            ans = num1 / num2;
            printf("La division de %d / %d = %f\n", num1, num2, ans);
            break;
        case 2:
            ans = num1 - num2;
            printf("La resta de %d - %d = %f\n", num1, num2, ans);
            break;
        case 3:
            ans = num1 * num2;
            printf("La suma de %d * %d = %f\n", num1, num2, ans);
            break;
        case 4:
            ans = num1 + num2;
            printf("La suma de %d + %d = %f\n", num1, num2, ans);
            break;
        default:
            printf("Hasta pronto\n");
            break;
        }

    }
    while (opt != 5);
    
    

    return 0;
}