#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void ordenarVectorMayorAMenor(int numero[], int tam)
{
    int i, j, auxiliar;
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(numero[i]<numero[j])
            {
                auxiliar = numero[i];
                numero[i] = numero[j];
                numero[j] = auxiliar;
            }
        }
    }
}

void ordenarVectorMenorAMayor(int numero[], int tam)
{
    int i, j, auxiliar;
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(numero[i]>numero[j])
            {
                auxiliar = numero[i];
                numero[i] = numero[j];
                numero[j] = auxiliar;
            }
        }
    }
}

void mostrarVector(int numero[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("%d \n", numero[i]);
    }
    system("PAUSE");
}
