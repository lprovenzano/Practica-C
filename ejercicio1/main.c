#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Ingresar 5 números y calcular su media */

    //Defino variables
    int numero, acumulador, contador;

    //Asigno valores e inicializo
    acumulador = 0;
    contador = 0;

    do
    {
        contador++;
        printf("Ingrese un numero (%d - 5): ", contador);
        scanf("%d", &numero);
        acumulador +=numero;

    }while(contador<5);

    printf("\n La suma es: %d", acumulador);
    printf("\n El promedio es: %d \n \n", acumulador/contador);

    return 0;
}
