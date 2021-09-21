/*
La empresa PrograAvanzada tiene un modelo de máquinas expendedoras de refrescos, papas fritas y chocolates, que necesita un programa para que realice el cálculo de cuántas monedas de cada tipo debe devolver.
Para ello, en primer lugar, se introducirá por teclado la cantidad a devolver  (múltiplo de 5 centavos, que es la moneda más pequeña de la que se dispone), es decir, se tecleará 1.85 para 1 peso con 85 centavos. Este programa escribirá en pantalla cuántas monedas de cada tipo hay que devolver teniendo en cuenta que:
• Se dispone de monedas de 50 centavos, 20 centavos, 10 centavos y 5 centavos.
• Siempre se dispone de las monedas necesarias de cada tipo.
• Se debe devolver el menor número de monedas posible, es decir, intentar devolver con las de mayor valor.
Ejemplos:
• Si se introduce la cantidad de 1 peso con 85 céntimos, el programa debe imprimir:
              3 monedas de 50 centavos, 1 moneda de 20 centavos, 1 moneda de 10 centavos, 1 moneda de 5 centavos.
• Si se introduce la cantidad de 1 peso con 20 centavos, el programa debe imprimir:
             2 monedas de 50 centavos, 1 moneda de 20 centavos, 0 monedas de 10 centavos, 0 monedas de 5 centavos. 
*/
//Leonardo Daniel Riojas Sanchez A00825968 3/9/21
#include<stdio.h>
#include<math.h>

int main(){
    float fchange;
    int change;
    float values[] = {50, 20, 10, 5};
    int coins[] = {0, 0, 0, 0};
    int i = 0;

    //Leemos el valor y validamos que sea multiplo de 5
    do{
        printf("Teclee el valor a devolver: ");
        scanf("%f", &fchange);
        fchange *= 100;
        change = (int)fchange;
        if(change % 5 != 0){
            printf("!!Cambio no valido!! Debe ser multiplo de 5 \n");
        }
    }while (change % 5 != 0);
    

    while(change > 0){
        //printf("%d\n", change);
        if(change < values[i]) i++;
        else {
            change -= values[i];
            coins[i]++;
        }
    }

    printf("%d monedas de 50 centavos, %d monedas de 20 centavos, %d monedas de 10 centavos, %d monedas de 5 centavos.\n", coins[0], coins[1], coins[2], coins[3]);

    return 0;
}