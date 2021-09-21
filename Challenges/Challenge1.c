/*El agente 0069 lleva años utilizando un método de codificación de mensajes secretos. Si X es el mensaje original, éste se codifica en dos etapas:​

X se transforma en X' reemplazando cada sucesión de caracteres consecutivos que no sean vocales por su imagen especular.​

X' se transforma en la sucesión de caracteres X'' obtenida al ir tomando sucesivamente: el primer carácter de X', luego el último, luego el segundo, luego el penúltimo, etc.​

Por ejemplo, para X = "Bond, James Bond", resultan:​

X' = "BoJ ,dnameB sodn"​

y​

X'' = "BnodJo s, dBneam"​

Lo que el pobre agente 0069 no sabe es que el señor Fon Noiman ha analizado algunos mensajes cifrados y ha dado con el mecanismo que está utilizando. Lo único que le queda a Fon Noiman es hacer el programa que, dado un mensaje cifrado, lo descifre.

Input​

La entrada consistirá en distintos casos de prueba, cada uno en una línea. Cada línea contendrá un mensaje cifrado según el algoritmo anterior. El agente 0069 utiliza un teclado inglés, por lo que ninguna vocal tendrá tilde.​

Output​

Para cada caso de prueba se escribirá en una línea el mensaje cifrado leído de la entrada; tras ello aparecerá "=>" entre dos espacios y el mensaje original descifrado.​

Entrada de ejemplo​

    BnodJo s, dBneam​

    E. .n.ualn cnhuag aMda  rle​

    Aauirnedleiua nBo​

Salida de ejemplo​

    BnodJo s, dBneam => Bond, James Bond​

    E. .n.ualn cnhuag aMda  rle => En un lugar de la Mancha...​

    Aauirnedleiua nBo => Aureliano Buendia​
​*/
//Leonardo Daniel Riojas Sanchez A00825968 

#include<stdio.h>
#include<string.h>

int isVowel(char ch);

int main(){
    char encryptedMsg[100];
    int n = 0;
    fgets(encryptedMsg, sizeof(encryptedMsg), stdin); //Read Encrypted Message
    n = strlen(encryptedMsg);
    encryptedMsg[n - 1] = '\0';
    char originalMsg[n];
    //Convert X'' to X'
    int left = 0, right = n - 2;
    for(int i = 0; i < n - 1; i++){
        if(i % 2 == 0){
            originalMsg[left++] = encryptedMsg[i];
        }
        else{
            originalMsg[right--] = encryptedMsg[i];
        }
    }
    originalMsg[n - 1] = '\0';

    //puts(originalMsg); //Print the X'

    //Convert X' to X'
    int substringSize = 0;
    for(int i = 0; i < n ; i++){
        //if is a vowel or is the end of the string reverse the subrting between vowels
        if(isVowel(originalMsg[i]) || originalMsg[i] == '\0'){
           int left = i - substringSize;
           int right = i - 1;
           char aux;
           while(left < right){
               aux = originalMsg[left];
               originalMsg[left++] = originalMsg[right];
               originalMsg[right--] = aux;
           }
           substringSize = 0;   
       }
        else
            substringSize++;
    }

    originalMsg[n - 1] = '\0';
    //puts(originalMsg);
    printf("%s => %s\n", encryptedMsg, originalMsg);

    return 0;
}

int isVowel(char ch){
    switch (ch)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        return 1;
    default:
        return 0;
    }
}