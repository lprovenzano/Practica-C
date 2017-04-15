#include <stdio.h>
#include <stdlib.h>

/*Diseñar un programa que lea 4 números e imprima el mayor de los cuatro*/

int main()
{
    //Declaro variables
    int numero, numeroMax, flag, contador;

    //Inicializo

    flag = 0;

    for(contador=0; contador<4;contador++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numero);

        if(flag == 0)
        {
            numeroMax = numero;
            flag = 1;
        }

        if(numero>numeroMax)
        {
            numeroMax = numero;
        }
    }

    printf("El numero mas grande es: %d \n", numero);

    return 0;
}
