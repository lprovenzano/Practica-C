#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Suma de dos numeros*/

    //Declaro variables
    int numeroUno, numeroDos, sumaNumeros;

    //Asigno valores
    printf("\n Ingrese un numero: ");
    scanf("%d", &numeroUno);

    printf("\n Ingrese otro numero: ");
    scanf("%d", &numeroDos);

    sumaNumeros = numeroUno+numeroDos;

    printf("\n El resultado es: %d \n \n", sumaNumeros);
    return 0;
}
