#include <stdlib.h>
#include <stdio.h>
#define MAX 5

void main(void)
{
    int vec[MAX],i,mayor,menor,num,flag=0;
    //Carga el vector
    for(i=0;i<MAX;i++)
    {
        printf("Ingrese nro");
        scanf("%d",&vec[i]);
    }

        mayor=vec[0];
        menor=vec[0];

        for(i=0;i<MAX;i++)
        {
            if(vec[i]>mayor)
            {
                mayor=vec[i];
            }
        }

        for(i=0;i<MAX;i++)
        {
            if(vec[i]<menor)
            {
                menor=vec[i];
            }

        }
        printf("\n El mayor es: %d \n", mayor);
        printf("\n El menor es: %d \n", menor);

}
