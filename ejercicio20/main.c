#include <stdio.h>
#include <stdlib.h>

/*
    Hacer el programa que imprima todos los n�meros naturales
    que hay desde la unidad hasta un n�mero que introducimos por teclado
*/

int main()
{
    //Defino variables
    short int numero, contador;

    do
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numero);
    }while(numero<=0);

    for(contador=0; contador<=numero; contador++)
    {
        printf("%d \n", contador);
    }

    return 0;
}
