#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main()
{
    int legajo, edad[MAX], acumulador, i, promedioEdades;
    float salario[MAX];

    acumulador = 0;

    for(i=0; i<MAX; i++)
    {
        printf("LEGAJO: %d \t EDAD: ", i+1);
        scanf("%d", &edad[i]);
        //Sumo edades
        acumulador += edad[i];

        //Promedio edades
        promedioEdades=acumulador/MAX;

    }

    printf("\n PROMEDIO (%d)", promedioEdades);
    printf("\n-----------------------------\n\n");
    for(i=0; i<MAX; i++)
    {
        //Filtro solo los mayores a promedioEdades
        if(edad[i]>promedioEdades)
        {
            legajo = i+1;
            printf("Empleado legajo NRO: %d \n", legajo);
        }
    }

    return 0;
}
