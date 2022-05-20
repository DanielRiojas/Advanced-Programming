/*
La serie de Fibonacci se realiza sumando siempre los últimos 2 números (Todos los números presentes en la sucesión se llaman números de Fibonacci) de la siguiente manera:

F(0) = 1F(1) = 1F(n) = F(n-1) + F(n-2)(para n=2,3,...)    Secuencia valores resultado:1, 1, 2, 3, 5, 8, 13, 21, 34, 55 ...

Realizar un programa en C con programación paralela que permita mostrar la serie de Fibonacci
*/
//Leonardo Daniel Riojas Sanchez A00825968
//Código creado el 31/10/2021 🎃
#include <stdio.h>          //Librería para input/output
#include <stdlib.h>         //Librería para manejo de memoria
#include "omp.h"            //Librería para manejo de threads

static int fib(int n){
    int a, b, id;
    if(n < 2) return n;
    #pragma omp task shared (a) private (id)
    {
        a = fib(n - 1);
    }

    #pragma omp task shared (b) private (id)
    {
        b = fib(n - 2);
    }

    return (a + b);
}

int main() {
    int n_hilos, id_hilo;
    int n = 8;
    /* printf("Escriba hasta que iteración quiere la serie fibonacci: ");
    scanf("%d", &n); */
    
    #pragma omp parallel num_threads(4) private(id_hilo) 
    {
        #pragma omp single 
        {
            id_hilo = omp_get_thread_num();
            printf("Hilo número: (%d)\n", id_hilo);
            printf("Fib(%d)= %d por %d\n", n, fib(n), id_hilo);
        }
    } //Termina la parte paralela
    return 0;
}