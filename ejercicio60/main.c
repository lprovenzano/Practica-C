#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main()
{
    int numero[MAX], i, j, auxiliarInt;

    //Cargo el vector.
    for(i=0; i<MAX; i++)
    {
        printf("Numero: ");
        scanf("%d", &numero[i]);
    }

    //Limpio y muestro por pantalla los numeros.
    system("CLS");
    for(i=0; i<MAX; i++)
    {
        printf("%d \n", numero[i]);
    }

    //Ordeno los numeros de menor a mayor por burbujeo.
    for(i=0;i<MAX-1;i++)
    {
        for(j=i+1;j<MAX;j++)
        {
            if(numero[i]>numero[j])
            {
                auxiliarInt = numero[i];
                numero[i] = numero[j];
                numero [j] = auxiliarInt;
            }
        }
    }
    system("CLS");
    printf("ORDEN DE MENOR A MAYOR \n");
    for(i=0; i<MAX; i++)
    {
        printf("%d \n", numero[i]);
    }


    return 0;
}
