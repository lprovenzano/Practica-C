#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 2

int main()
{
    int legajo[CANTIDAD],contador, edad[CANTIDAD];
    float salario[CANTIDAD], auxiliar;
    char nombre[CANTIDAD][21];

    for(contador=0;contador<CANTIDAD;contador++)
    {
        system("CLS");

        printf("Ingrese el nombre del empleado N %d: ", contador+1);
        fflush(stdin);
        fgets(nombre[contador], 21, stdin);

        printf("Ingrese el legajo del empleado N %d: ", contador+1);
        scanf("%d", &legajo[contador]);

        printf("Ingrese el salario del empleado N %d: ", contador+1);
        scanf("%f", &auxiliar);
        salario[contador] = auxiliar;

        printf("Ingrese la edad del empleado N %d: ", contador+1);
        scanf("%d", &edad[contador]);

    }

    system("CLS");

    for(contador=0;contador<CANTIDAD;contador++)
    {
        printf("Nombre %d: %s \n", contador+1, nombre[contador]);
        printf("Legajo %d: %d \n \n", contador+1, legajo[contador]);
        printf("Salario %d: %.2f \n \n", contador+1, salario[contador]);
        printf("Edad %d: %d \n \n \n", contador+1, edad[contador]);
        printf("------------------------------------------------------- \n");
    }


}
