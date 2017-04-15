#include <stdio.h>
#include <stdlib.h>

/*
    Hacer el programa que imprima los números del 100 al 0 en orden decreciente
*/

int main()
{
    int numeros;


    //FOR
    /*for(numeros=100;numeros>0;numeros--)
    {
        printf("%d \n", numeros);
    }*/

    //WHILE
    numeros = 100;
    /*while(numeros>0)
    {
        printf("%d \n", numeros);
        numeros--;
    }*/

    //DO WHILE

    do
    {
        printf("%d \n", numeros);
        numeros--;
    }while(numeros>0);

    return 0;
}
