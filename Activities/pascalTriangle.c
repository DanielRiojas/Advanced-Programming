/*
El ejercicio o práctica que se plantea es el siguiente:

Escribir un programa que permita visualizar el triángulo de pascal. En el triángulo de pascal cada número es la suma de los dos números situados encima de él. Solucionar el ejercicio utilizando un arreglo,matriz, o vector de una única dimensión.
*/
#include<stdio.h>

int main() {
    int lineas;
    printf("Este programa muestra una pirámide de pascal\n Ingresa cuantos pisos quieres que tenga: ");
    scanf("%d", &lineas);
    int piramide[lineas][lineas];
    piramide[0][0] = 1;
    int tabs = lineas;

    int piso = 0;
    while(piso < lineas) {
        //Imprimir piso actual
        for(int i = 0; i < tabs; i++){
            printf("  ");
        }
        tabs--;

        for(int i = 0; i <= piso; i++){
            printf("%d  ", piramide[piso][i]);
        }
        printf("\n\n");

        //Crear piso de abajo
        piso++;
        piramide[piso][0] = 1;
        piramide[piso][piso] = 1;
        for(int i = 1; i < piso; i++){
            //printf("%d", piramide[piso][i]);
            piramide[piso][i] = piramide[piso-1][i]+piramide[piso-1][i-1];
            //printf("+%d=%d\n", piramide[i-1],piramide[i]);
        }
    }
    
    printf("Piramide finalizada\n");

    return 0;
}