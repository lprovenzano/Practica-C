#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main()
{
    int numero[MAX], i, numeroMayor, flag, j, auxiliarInt;

    flag=0;
    for(i=0; i<MAX; i++)
    {
        printf("Ingrese numero: ");
        scanf("%d", &numero[i]);
        //MAYOR
        if(flag==0)
        {
            numeroMayor=numero[i];
            flag=1;
        }
        if(numero[i]>numeroMayor)
        {
            numeroMayor = numero[i];
        }
    }

    //Ordeno y muestro
    for(i=0;i<MAX-1;i++)
    {
        for(j=i+1;j<MAX;j++)
        {
            if(numero[i]>numero[j])
            {
                auxiliarInt=numero[i];
                numero[i]=numero[j];
                numero[j]=auxiliarInt;
            }
        }
    }

    system("CLS");

    for(i=0; i<MAX; i++)
    {
        printf("Numero: %d \t Indice: %d \n", numero[i], i);
    }
        printf("\n El numero mayor es: %d", numeroMayor);

    return 0;
}
