#include <stdio.h>
#include <stdlib.h>

/*
    Diseñar en un programa que permita ingresar 10 números, ninguno de ellos igual a cero.
    Se pide sumar los positivos, obtener el producto de los negativos y luego mostrar ambos resultados
*/

int main()
{
    //Defino variables
    int contador, numero, numerosNegativos, numerosPositivos;

    //Asigno valores a las variables e inicializo
    numerosNegativos = 1;
    numerosPositivos = 0;

    for(contador=0; contador<10; contador++)
    {
        do
        {
           printf("Ingrese un numero distinto de cero: ");
           scanf("%d", &numero);
        }while(numero == 0);

        if(numero<0)
        {
            numerosNegativos *= numero;
        }
        if(numero>0)
        {
            numerosPositivos += numero;
        }
    }
    printf("\n Suma de positivos: %d", numerosPositivos);
    printf("\n Producto de negativos: %d \n", numerosNegativos);

    return 0;
}
