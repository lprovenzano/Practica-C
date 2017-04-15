#include <stdio.h>
#include <stdlib.h>
#define MAX 50
void menu();
void cargarVector(int [], int [],int);
void buscarVectorPorNumero(int, int[], int [], int);
void mostrarVector(int [],  int [], int);

int main()
{
    int mesa[MAX], opcion, buscarMesa;
    int estado[MAX]= {0};
    menu();
    do
    {
        printf("\n\n\nOPCION: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            cargarVector(mesa, estado, MAX);
            opcion=5;
            break;
        case 2:
            system("CLS");
            menu();
            printf("\n\nNumero de Mesa: ");
            scanf("%d", &buscarMesa);
            system("CLS");
            menu();
            buscarVectorPorNumero(buscarMesa, mesa, estado, MAX);
            break;
        case 3:
            break;
        case 4:
            mostrarVector(mesa, estado,MAX);
            break;
        case 0:
            exit(0);
            break;
        }
        opcion=5;

    }
    while(opcion<0 || opcion>4);


    return 0;
}

void menu()
{
    printf("\nMENU\n-----------------\n\n 1. Cargar mesa \n 2. Registrar consumo \n 3. Mesas libres \n 4. Listado de mesas \n\n 0. Salir");
}

void cargarVector(int num[], int estado[], int tam)
{
    int i, flag;
    flag=0;

    for(i=0; i<tam; i++)
    {
        if(estado[i]==0)
        {
            system("CLS");
            menu();
            printf("\n\nNueva mesa: ");
            scanf("%d", &num[i]);
            estado[i]=1;
            flag=1;
            break;
        }
    }
    if (!flag)
    {
        system("CLS");
        menu();
        printf("\n\nTodas las mesas se encuentras ocupadas.");
    }
}

void buscarVectorPorNumero(int numBuscado, int num[], int estado[], int tam)
{
    int i, auxiliar, flag;
    flag=0;
    for(i=0; i<tam; i++)
    {
        if(estado[i]==1)
        {
            if(numBuscado==num[i])
            {
                auxiliar = numBuscado;
                printf("\n\nMesa (%d) \t $", auxiliar);
                flag=1;

            }
        }
    }
    if(flag==0)
    {
        printf("\n\nError! No existe esa mesa. \n");
    }

}

void mostrarVector(int num[], int estado[],int tam)
{
    int i, flag, acumulador, ocupadas, total;
    acumulador =0;
    ocupadas = 0;
    flag =0;
    printf("\n\nListado de mesas\n------------------\n\n");
    for(i=0; i<tam; i++)
    {
        acumulador++;
        if(estado[i]==1)
        {
            ocupadas++;
            printf("Mesa %d \t Consumo actual: $\n", num[i]);
            flag=1;
        }
    }
    if(!flag)
    {
        printf("\n\nLibre.");
    }
    total = acumulador-ocupadas;
    printf("\nQuedan %d mesas disponibles.", total);
}


