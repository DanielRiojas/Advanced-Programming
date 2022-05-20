/*
    Realice un programa en Lenguaje C  que pregunte número de hilos ha de crear y además,  se desea saber cuántos procesadores o núcleos tiene el computador, como salida debe mostra la siguiente información: 

                                   Ingresar el numero de hilos:  X  

Este equipo usa Y procesador(es)

En este programa se desea usar X hilo(s)

           *****Acabo de entrar a la seccion paralela*****

En este momento se esta ejecutando # hilo.

 

               *******Termina sección paralela*******
*/
#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int main() {
    int n_hilos;
    scanf("%d", &n_hilos);
    
    printf("Este equipo usa %d procesadores\n", omp_get_num_procs());
    printf("En este programa se desea usar %i hilo(s)\n", omp_get_max_threads());

    printf("*Acabo de entrar a la seccion paralela*\n");
    omp_set_num_threads(n_hilos);

    #pragma omp parallel private (n_hilos) 
    printf("Este es el hilo : %i\n", omp_get_thread_num());
    
    printf("*Termina sección paralela*\n");

    return 0;
}