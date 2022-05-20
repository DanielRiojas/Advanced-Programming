/*
    Realizar un programa en lenguaje C que genere 3 hijos con la función fork(), donde el padre realice una multiplicación de 3 números y los hijos realicen la raiz cuadrada de un número proporcionado por teclado.   El programa debe mostrar cuales son los PID de los procesos Padre e Hijos
*/
#include <math.h>
#include <stdio.h>
#include <unistd.h>


int main() {
    pid_t pid;
    printf("El PID del padre es %d\n", getpid());

    pid = fork();
    if(pid > 0) {
        printf("El PID del primer hijo es %d\n", pid);
        pid = fork();
        if(pid > 0) printf("El PID del segndo hijo es %d\n", pid);
    }
    sleep(1);
    if(pid > 0){
        int a, b, c;
        printf("Teclea tres números: ");
        scanf("%d %d %d", &a, &b, &c);
        printf("La multiplicación es: %d\n", a*b*c);
        sleep(5);
    }
    else{
        sleep (5);
        double a;
        double result;
        printf("Teclea un número: ");
        scanf("%lf", &a);
        result = sqrt(a);
        printf("La raíz cuadrada es: %lf", result);
    }

    return 0;
}