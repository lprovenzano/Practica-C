#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main()
{
    //Variables
    int numero[MAX], j, i, auxiliar;

    for(i=0; i<MAX; i++)
    {
        do
        {
            printf("Numero (%d): ", i);
            scanf("%d", &numero[i]);
        }
        while(numero[i]==0);
    }

    //Muestro en pantalla el primer ingreso
    printf("\nNUMEROS\n----------------------\n\n");
    for(i=0; i<MAX; i++)
    {
        printf("%d \n", numero[i]);
    }

    //Ordeno de forma decreciente los positivos
    for(i=0; i<MAX-1; i++)
    {
        for(j=i+1; j<MAX; j++)
        {

            if(numero[i]<numero[j])
            {
                auxiliar = numero[i];
                numero[i] = numero[j];
                numero[j] = auxiliar;
            }

        }
    }

    printf("\nNUMEROS POSITIVOS\n----------------------\n\n");
    for(i=0; i<MAX; i++)
    {
        if(numero[i]>0)
        {
            printf("%d \n", numero[i]);
        }
    }

    //Ordeno de forma creciente los negativos
    for(i=0; i<MAX-1; i++)
    {
        for(j=i+1; j<MAX; j++)
        {

            if(numero[i]>numero[j])
            {
                auxiliar = numero[i];
                numero[i] = numero[j];
                numero[j] = auxiliar;
            }

        }
    }

    printf("\nNUMEROS NEGATIVOS\n----------------------\n\n");
    for(i=0; i<MAX; i++)
    {
        if(numero[i]<0)
        {
            printf("%d \n", numero[i]);
        }
    }


    return 0;
}
