#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
        De 10 números ingresadas indicar cuantos son mayores a cero y cuantos son menores a cero.
    */
    int numero, contador, cantidadPositivos, cantidadNegativos;

    //Declaro variables

    //Asigno valores
    contador=0;
    cantidadNegativos =0;
    cantidadPositivos = 0;

    do
    {
        contador++;

        do{
            printf("\n Ingrese un numero (%d): ", contador);
            scanf("%d", &numero);
        }while(numero == 0);

        if(numero<0)
        {
            cantidadNegativos++;
        }

        if(numero>0)
        {
            cantidadPositivos++;
        }
    }while(contador<10);

    printf("\n \n Cantidad de positivos: %d \n", cantidadPositivos);
    printf("\n Cantidad de positivos: %d \n \n", cantidadNegativos);

    return 0;
}
