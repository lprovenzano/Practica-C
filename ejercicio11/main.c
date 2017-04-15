#include <stdio.h>
#include <stdlib.h>

/*
    Hacer el programa que imprima los números pares entre el 1 y el 100
*/

int main()
{
    //Declaro variables
    int numeros;

    for(numeros=0;numeros<=100;numeros++)
    {
        if(numeros%2==1)
        {
            continue;
        }
        printf("%d \n", numeros);
    }
    return 0;
}
