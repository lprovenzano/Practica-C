#include <stdio.h>
#include <stdlib.h>

/*
    Ingresar un número entero por consola y efectuar la suma de todos los números que le anteceden,
    comenzando desde 0 y mostrar el resultado por pantalla
*/

int main()
{
    //Defino variables
    int numero, antecesores, acumulador;

    //Defino variables y bucle

    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    acumulador = 0;

    for(antecesores=numero;antecesores>0;antecesores--)
    {
        acumulador+=antecesores;
    }
    printf("\n La suma de los predecesores es: %d \n", acumulador);
    return 0;
}
