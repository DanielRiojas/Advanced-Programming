#include<stdio.h>
#include<unistd.h>

int valor, l;

int main() {
    pid_t pid; /*Inicializar proceso padre */

    printf("Este es el PID (Process ID) del proceso que comienza %d   \n", getpid());   /*La función getpid() regresa el PID del padre*/

    pid = fork();   /*La función fork genera un hijo del proceso que estamos manejando*/

    printf("PID (Process ID) %d          pid = %d\n", getpid(), pid);

    //pid = fork() /*Aquí se crearía otro proceso hijo, uno hijo del padre y un hijo del hijo*/

    if(pid > 0) valor = 88; /*El proceso padre le está dando el valor*/
    else valor = 55; /*El proceso hijo le está dando este valor*/

    while (1) {
        sleep(5);
        printf("PID = %d          Valor = %d\n", getpid(), valor);
    }
    


    return 0;
}