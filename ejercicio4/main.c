#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
        Escribir un programa que realice las siguientes acciones:
         Limpie la pantalla
         Declare 2 variables y les asigne sendos valores
         Realice la resta de dichas variables y muestre por pantalla la leyenda
        "Resultado positivo" en caso de ser mayor que cero o "Resultado negativo" si es menor que cero.
    */

    //Declaro variables
    int numero1, numero2, totalNumeros;

    //Asigno valores
    printf("\n Primer numero: ");
    scanf("%d", &numero1);
    printf("\n Segundo numero: ");
    scanf("%d", &numero2);

    totalNumeros = numero1-numero2;

    if(totalNumeros<0)
    {
        printf("\n Negativo (%d) \n ", totalNumeros);
    }
    if(totalNumeros>0)
    {
        printf("\n Positivo (%d) \n", totalNumeros);
    }
    if(totalNumeros==0)
    {
        printf("\n Cero (%d)\n", totalNumeros);
    }
    return 0;
}
