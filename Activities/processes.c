/*
Realizar un programa en lenguaje C que genere 1 hijo con la función fork(), donde el padre guarde en un arreglo los numeros impares  del 1 al 100 y el hijo guarde en un arreglo los numeros pares del 1 al 100.

Utilizar la función sleep() en el hijo.

¿Cuales son los PID de los procesos Padre e Hijo?
¿Qué realiza la función sleep? 
*/
//Leonardo Daniel Riojas Sanchez A00825968
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    pid_t pid; //Declaramos el proceso hijo del padre

    //DEclaramos los arreglos de enteros
    int *fatherArray, *childArray;
    fatherArray = (int*) malloc(50 * sizeof(int));
    childArray = (int*) malloc(50 * sizeof(int));

    printf("El PID del padre es %d y el del hijo es %d\n", getpid(), pid);

    //Verificamos que se asignó la memoria para los arreglos
    if(fatherArray == NULL && childArray == NULL) {
        printf("Error! Memoria no asignada.");
        exit(0);
    }

    pid = fork(); 

    for(int i = 1; i < 100; i++){
        if(pid > 0) *(fatherArray + (i / 2)) = i;
        else *(childArray + (i / 2)) = i+1;
    }
    
    //Imprimimos los arreglos
    if(pid > 0) {
        printf("Arreglo del proceso padre:\n");
        for(int i = 0; i < 50; i++){
            printf("%d, ", *(fatherArray + i));
        }
        printf("\n");
    }
    else {
        printf("Arreglo del proceso hijo:\n");
        for(int i = 0; i < 50; i++){
            printf("%d, ", *(childArray + i));
        }
        printf("\n");
    }

    free(fatherArray);
    free(childArray);

    //Mandamos a dormir el proceso hijo
    /*if (pid == 0)
    {
        sleep(1);
    }*/
    return 0;
}