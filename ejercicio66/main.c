#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int main()
{
    int edad[MAX], acumulador, promedio, mujeres, i, mayores;
    char sexo[MAX];
    acumulador = 0;

    mayores = 0;
    mujeres = 0;

    for(i=0;i<MAX;i++)
    {
        printf("LEGAJO (%d) \n \n Edad: ", i);
        scanf("%d", &edad[i]);
        do
        {
            printf("\n Sexo: ");
            fflush(stdin);
            gets(&sexo[i]);
        }while(sexo[i]!='m' && sexo[i]!='f');
        system("CLS");

        acumulador +=edad[i];
        promedio = acumulador/MAX;

        if(edad[i]>17)
        {
            mayores++;
        }
        if(edad[i]==39 && sexo[i]=='f')
        {
            mujeres++;
        }
    }

    system("CLS");
    printf("PROMEDIO EDAD: %d \n", promedio);
    printf("CANTIDAD MAYORES DE EDAD: %d \n", mayores);
    printf("CANTIDAD MUJERES NACIDAD EN 1978: %d \n", mujeres);

    return 0;
}
