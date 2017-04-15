#include <stdio.h>
#include <stdlib.h>

/*
    Hacer el programa que nos permita contar los
    múltiplos de 3 desde la unidad hasta un número que introducimos por teclado
*/

int main()
{
    //Defino variables
    int numero, contador;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);


    for(contador=3; contador<=numero; contador++)
    {
        if(contador%3==0)
        {
            printf("%d \n", contador);
        }
    }

    return 0;
}
