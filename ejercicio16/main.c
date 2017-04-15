#include <stdio.h>
#include <stdlib.h>

/*
    Hacer el programa que nos permita
    introducir un número por teclado y nos informe si es positivo o negativo
*/

int main()
{
    //Declaro variables
    int numero;

    //Asigno
    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    if(numero<0)
    {
        printf("\n Negativo.\n");
    }
    if(numero>0)
    {
        printf("\n Positivo.\n");
    }
    if(numero==0)
    {
        printf("\n Cero.\n");
    }

    return 0;
}
