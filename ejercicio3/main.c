#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
        Escribir un programa que realice las siguientes acciones:
             Limpie la pantalla
             Asigne a 2 variables numero1 y numero2 valores distintos de cero
             Efectúe el producto de dichas variables
             Muestre el resultado pos pantalla
             Obtenga el cuadrado de numero1 y lo muestre par pantalla
    */

    int numero1, numero2, productoNumeros;

    do{
        system("CLS");

        printf("\n Ingrese un numero: ");
        scanf("%d", &numero1);

        printf("\n Ingrese otro numero: ");
        scanf("%d", &numero2);

        productoNumeros = numero1*numero2;
        numero1 *= numero1;

    }while(numero1 == 0 || numero2 == 0);

    printf("\n El producto de ambos numeros es: %d", productoNumeros);
    printf("\n El cuadrado del primer numero es: %d \n", numero1);

    return 0;
}
