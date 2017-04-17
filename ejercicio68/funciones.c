#include <stdio.h>
#include <stdlib.h>

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

float cargarConsumo()
{
    float consumo;
    printf("\n\nIngrese monto: $");
    scanf("%f", &consumo);
    return consumo;
}

void buscarVectorPorNumero(int numBuscado, int num[], int estado[], int tam)
{
    int i, auxiliar, flag;
    float ventas, sumoVenta;
    sumoVenta=0;
    flag=0;
    char rta;
    for(i=0; i<tam; i++)
    {
        if(estado[i]==1)
        {
            if(numBuscado==num[i])
            {
                auxiliar = numBuscado;
                do
                {
                ventas=cargarConsumo();
                printf("\n\nCargar otro monto para esta mesa? (s|n)");
                fflush(stdin);
                rta=getch();
                sumoVenta+=ventas;
                }while(rta=='s');
                system("CLS");
                menu();
                printf("\n\nMesa (%d) \t $ %.2f", auxiliar, sumoVenta);
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

