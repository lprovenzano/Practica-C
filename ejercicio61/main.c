#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main()
{
    int numero[MAX], i, diaMayor,flag, numeroDia;

    for(i=0;i<MAX;i++)
    {
        printf("Numero (%d): ", i);
        scanf("%d", &numero[i]);

        if(flag)
        {
            diaMayor = numero[i];
            flag=!flag;
        }
        if(numero[i]>diaMayor)
        {
            diaMayor=numero[i];
            numeroDia = i;
        }
    }
        printf("El dia que mas gasto fue el nro: %d \t ($%d)", numeroDia, diaMayor);
    return 0;
}
