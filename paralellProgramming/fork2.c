#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    pid_t pro; /*Inicializar proceso padre*/

    pro = fork();

    switch (pro) {
    case -1:
        printf("No se pudo generar el proceso hijo \n");
        break;
    case 0:
        printf("El PID del hijo es %d\n", getpid());
        printf("El PID del padre es %d\n", getppid());
    }

    printf("Fin de la ejecucion del padre %d\n", getppid());

    return 0;
}