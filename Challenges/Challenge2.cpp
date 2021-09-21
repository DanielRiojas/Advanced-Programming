/*
A continuación les envío la descripción  de lo que son los numeros narcisistas:

un número narcisista es aquel que es igual a la suma de sus dígitos elevados a la potencia de su número de cifras.

Por ejemplo, 371 es un número narcisista, ya que:

3^3 + 7^3 + 1^3 = 27 + 343 + 1 = 371

También lo es, por ejemplo, 93084:

9^5 + 3^5 + 0^5 + 8^5 + 4^5 = 59049 + 243 + 0 + 32768 + 1024 = 93084

El objetivo es realizar un programa que identifique cuales son  dichos números dado un límite máximo, por ejemplo, ¿cuales son números narcisistas hasta el 1000?, y como resultado tiene que desplegar: 1, 2, 3, 4, 5, 6, 7, 8, 9, 153, 370, 371, 407
*/

#include<iostream>
#include<math.h>
using namespace std;

//Funcion recursiva para saber los digitos
int countDigits(int num) {
    if(num == 0) return 0;

    return 1 + countDigits(num / 10);
}

bool isNarcissist(int num){
    //Mandamos contar los dígitos
    int digits = countDigits(num);
    //Creamos copia del numero para irlo reduciendo
    int copy = num;
    //Hacemos la suma de cada digito elevado a la digits
    int sum = 0;
 
    
    while (copy != 0) {
        sum += pow(copy % 10, digits);
        copy /= 10;
    }
 
    return num == sum;
}

int main() {
    //Definimos el limite máximo
    int maxLimit;
    cout<<"Ingresa el limite maximo: ";
    cin>>maxLimit;

    //Iteramos por todos los numero hasta el limite y vamos imprimiendo si es narcisista
    cout<<"Los numeros narcisistas del 1 al "<<maxLimit<<" son: "<<endl;
    for(int i = 1; i <= maxLimit; i++){
        if(isNarcissist(i)){
            cout<<i<<endl;
        }
    }

    return 0;
}