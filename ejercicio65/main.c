#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAX 5

int main()
{
    int numero[MAX], i, opcion;
    char rta;
    rta='s';
    //Menu fijo.
    printf("\nMENU \n--------------------- \n \n 1. Cargar el vector \n 2. Ordenar el vector \n 3. Mostrar el vector \n\n 0. Salir \n \n \n");

    do
    {
        system("CLS");
        printf("\nMENU \n--------------------- \n \n 1. Cargar el vector \n 2. Ordenar el vector \n 3. Mostrar el vector \n\n 0. Salir \n \n \n");
        printf("OPCION: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            system("CLS");
            printf("\nMENU \n--------------------- \n \n 1. Cargar el vector \n 2. Ordenar el vector \n 3. Mostrar el vector \n\n 0. Salir \n \n \n");
            for(i=0; i<MAX; i++)
            {
                system("CLS");
                printf("\nMENU \n--------------------- \n \n 1. Cargar el vector \n 2. Ordenar el vector \n 3. Mostrar el vector \n\n 0. Salir \n \n \n");
                printf("Numero (%d - %d):", i+1, MAX);
                scanf("%d", &numero[i]);
            }
            break;
        case 2:
            do
            {
                system("CLS");
                printf("\n2. Ordenar el vector \n--------------------- \n \n 1. De menor a mayor \n 2. De mayor a menor \n\n 0. Salir \n \n \n");
                printf("OPCION: ");
                scanf("%d", &opcion);
                switch(opcion)
                {
                case 1:
                    ordenarVectorMenorAMayor(numero, MAX);
                    break;
                case 2:
                    ordenarVectorMayorAMenor(numero, MAX);
                    break;
                case 0:
                    rta='s';
                    break;
                }
            }
            while(opcion<0 || opcion>2);
            break;
        case 3:
            mostrarVector(numero, MAX);
            break;

        }

    }
    while(opcion<0 || opcion>3 || rta=='s');

    return 0;
}
