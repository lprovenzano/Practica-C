#include <stdio.h>
#include <stdlib.h>

/*
    Escribir en C un programa que muestre los números impares entre 0 y 100 y que
    imprima cuantos impares hay.
*/

int main()
{
    //Defino variables
    int contador, cantidadImpares;

    //Asigno valores e inicializo variables
    cantidadImpares = 0;

    for(contador=0;contador<100;contador++)
    {
        if(contador%2==0)
        {
            continue;
        }
        printf("%d \n", contador);
        cantidadImpares++;
    }

    printf("\n Hay: %d", cantidadImpares);
    printf(" numeros impares. \n \n");

    return 0;
}
