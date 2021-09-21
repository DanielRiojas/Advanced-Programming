/*
Una frutería comercializa tres productos: Manzana, Naranja y Limón. Se desea realizar un programa que calcule las ventas realizadas de cada producto. Para ello, se leerá la cantidad vendida (máximo 500000) y el precio de cada producto y se mostrará un informe de ventas como el que sigue:

 Producto Ventas Precio Total

--------------------------------------------

Manzana  100,000  0.17  170000.00

Naranja    350,000  0.20   70000.00

Limón      500,000  0.19   95000.00

                               TOTAL   335,000.00
*/
//Leonardo Daniel Riojas Sanchez A00825968

#include<stdio.h>

int main() {
    //Definimos el primer array para imprimir
    float ticket[4][3];
    float total = 0;
    char products[4][10] = {
        "Manzana",
        "Naranja",
        "Limón",
        "TOTAL"
    };

    //Leyendo los datos de cantidad y precio
    printf("Ingrese la cantidad y precio de cada producto:\n");
    for(int i = 0; i < 3; i++){
        printf("----------------------\n");
        printf("%s \n", *(products + i));
        for(int j = 0; j < 2; j++){
            (j == 0) ? printf("Cantidad: ") : printf("Precio: ");
            scanf("%f", *(ticket + i) + j);
            //Validamos que la cantidad no sea mayor a 500,000
            while(j == 0 && *(*(ticket + i) + j) > 500000){
                printf("¡¡¡Cantidad maxima rebasada, ingrese maximo 500,000!!!\n");
                printf("Nueva cantidad de %s: ", *(products + i));
                scanf("%f", *(ticket + i) + j);
            }
        }
    }

    //Calculando el total
    for(int i = 0; i < 3; i++){
        total += *(*(ticket + i) + 2) = *(*(ticket + i) + 0) * *(*(ticket + i) + 1);
    }
    *(*(ticket + 3) + 2) = total;
    
    //Imprimiendo el ticket
    printf("Producto\t\tVentas\t\tPrecio\t\tTotal\n");
    printf("--------------------------------------------\n");
    for(int i = 0; i < 4; i++){
        printf("%s\t\t", *(products + i));
        for(int j = 0; j < 3; j++){
            if(i < 3 || j > 1){
                printf("%.2f\t\t", *(*(ticket + i) + j));
            }
            else{
                printf("\t\t");
            }
        }
        printf("\n");
    }

    


    return 0;
}