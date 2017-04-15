#include <stdio.h>
#include <stdlib.h>

/*Hacer el programa que nos permita introducir un
número por teclado y nos informe si es par o impar*/

int main()
{
    //Defino variables
    int numero;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    if(numero%2==0)
    {
        printf("Numero PAR (%d) \n", numero);
    }
    if(numero%2==1)
    {
        printf("Numero IMPAR (%d) \n", numero);
    }


    return 0;
}
