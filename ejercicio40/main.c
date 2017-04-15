#include <stdio.h>
#include <stdlib.h>

/*
    Se ingresa por consola la cantidad de agua caída, en milímetros día a día durante un mes.
    Se pide determinar el día de mayor lluvia, el de menor y el promedio
*/

int main()
{
    //Declaro variables
    int cantidadAgua, diaMayor, diaMenor, flag, mes, acumulador;

    flag = 0;
    acumulador=0;

    for(mes=0; mes<30; mes++)
    {
        do
        {
            printf("Cuantos milimetros cayeron hoy? ");
            scanf("%d", &cantidadAgua);
        }while(cantidadAgua<0);

        if(flag == 0)
        {
            diaMayor = cantidadAgua;
            diaMenor = cantidadAgua;
            flag = 1;
        }

        if(cantidadAgua>diaMayor)
        {
            diaMayor = cantidadAgua;
        }

        if(cantidadAgua<diaMenor)
        {
            diaMenor = cantidadAgua;
        }
        acumulador+=cantidadAgua;
    }

    printf("Mayor cantidad de agua: %d mm \n", diaMayor);
    printf("Menor cantidad de agua: %d mm \n", diaMenor);
    printf("En promedio cayeron %d mm de agua", acumulador/mes);

    return 0;
}

