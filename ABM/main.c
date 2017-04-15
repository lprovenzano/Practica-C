#include <stdio.h>
#include <stdlib.h>
#define E 5

void cargarEmpleado(int[], char[][20], float[], int[], int);
void eliminarEmpleado(int[], char[][20], float[], int[], int);
void modificarEmpleado(int[], char[][20], float[], int[], int);

int main()
{
    /*legajo nombre sueldo*/

    int legajos[E], estado[E]= {0}, i, j;
    int auxInt, flagEncontro=0;
    char nombres[E][20], auxString[20];
    float sueldos[E], auxFloat;
    int opcion;
    char seguir ='s', respuesta;;

    do
    {
        printf("1.Alta\n2.Baja\n3.Modificacion\n4.ordenar\n5. mostrar\n6.salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            cargarEmpleado(legajos, nombres, sueldos, estado, E);
            break;
        case 2:
            eliminarEmpleado(legajos, nombres, sueldos, estado, E);
            break;
        case 3:

            modificarEmpleado(legajos, nombres, sueldos, estado, E);
            break;
        case 4:
            for(i=0; i<E-1; i++)
            {
                for(j=i+1; j<E; j++)
                {
                    if(strcmp(nombres[i], nombres[j])>0)
                    {
                        strcpy(auxString, nombres[i]);
                        strcpy(nombres[i], nombres[j]);
                        strcpy(nombres[j], auxString);

                        auxInt=legajos[i];
                        legajos[i] = legajos[j];
                        legajos[j] = auxInt;

                        auxFloat = sueldos[i];
                        sueldos[i] = sueldos[j];
                        sueldos[j] = auxFloat;

                        auxInt=estado[i];
                        estado[i] = estado[j];
                        estado[j] = auxInt;


                    }
                    else
                    {
                        if(strcmp(nombres[i], nombres[j])==0)
                        {
                            if(legajos[i]>legajos[j])
                            {
                                auxInt=legajos[i];
                                legajos[i] = legajos[j];
                                legajos[j] = auxInt;

                                auxFloat = sueldos[i];
                                sueldos[i] = sueldos[j];
                                sueldos[j] = auxFloat;

                                auxInt=estado[i];
                                estado[i] = estado[j];
                                estado[j] = auxInt;
                            }
                        }
                    }
                }
            }





            break;

        case 5:

            printf("Legajo\tnombre\tsueldo\n");
            for(i=0; i<E; i++)
            {
                if(estado[i]!=0)
                    printf("%d\t%s\t%.2f\n", legajos[i],nombres[i],sueldos[i]);
            }

            break;
        case 6:
            seguir='n';
            break;

        }




    }
    while(seguir=='s');






    printf("Hello world!\n");
    return 0;
}

void cargarEmpleado(int legajos[], char nombres[][20], float sueldos[], int estados[], int tam)
{
    int flagEncontro = 0, i;
    for(i=0; i<tam; i++)
    {
        if(estados[i]==0)
        {
            printf("Ingrese legajo: ");
            scanf("%d", &legajos[i]);
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nombres[i]);
            printf("Ingrese sueldo: ");
            scanf("%f", &sueldos[i]);

            estados[i] = 1;
            flagEncontro = 1;

            break;
        }
    }
    if(!flagEncontro)
    {
        printf("No hay espacio suficiente!!!");
    }
}

 void eliminarEmpleado(int legajos[], char nombres[][20], float sueldos[], int estados[], int tam)
    {
        int flagEncontro=0, i;
        int auxInt;
        char respuesta;
        printf("Ingrese legajo: ");
        scanf("%d", &auxInt);
        for(i=0; i<tam; i++)
        {
            if(estados[i]==1)
            {
                if(auxInt == legajos[i])
                {
                    printf("%d\t%s\t%.2f\n", legajos[i],nombres[i],sueldos[i]);

                    printf("Esta seguro de eliminar el dato s/n: ");
                    respuesta = getche();
                    if(respuesta=='s')
                    {
                        estados[i] = 0;
                    }
                    else
                    {
                        printf("Accion cancelada por el usuario!!!");
                    }

                    flagEncontro=1;
                    break;

                }

            }
        }
        if(flagEncontro==0)
        {
            printf("Dato inexistente");
        }
    }

void modificarEmpleado(int legajos[], char nombres[][20], float sueldos[], int estados[], int tam)
{
    int flagEncontro=0, i, auxInt;
    float auxFloat;
    char respuesta;
            printf("Ingrese legajo: ");
            scanf("%d", &auxInt);
            for(i=0; i<tam; i++)
            {
                if(estados[i]==1)
                {
                    if(auxInt == legajos[i])
                    {
                        printf("%d\t%s\t%.2f\n", legajos[i],nombres[i],sueldos[i]);
                        printf("Ingrese sueldo a modificar");
                        scanf("%f", &auxFloat);
                        printf("Esta seguro de realizar la modificacion s/n: ");
                        respuesta = getche();
                        if(respuesta=='s')
                        {
                            sueldos[i] = auxFloat;
                        }
                        else
                        {
                            printf("Accion cancelada por el usuario!!!");
                        }

                        flagEncontro=1;
                        break;

                    }

                }
            }
            if(flagEncontro==0)
            {
                printf("Dato inexistente");
            }
}
