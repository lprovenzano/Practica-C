#include <stdio.h>
#include <stdlib.h>
#define MAX 5


void cargarVector(int [], int);
void buscarVectorPorNumero(int, int[], int);
void buscarVectorPorIndice(int, int[], int);
void menu();

int main()
{
    int numero[MAX], opcion, numBuscado, indiceBuscado;
    menu();
    do
    {
        printf("\n \nOPCION: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            cargarVector(numero, MAX);
            system("CLS");
            menu();
            opcion=5;
            break;
        case 2:
            printf("\n\nIngrese numero a buscar: ");
            scanf("%d", &numBuscado);
            buscarVectorPorNumero(numBuscado, numero, MAX);
            break;
        case 3:
            printf("\n\nIngrese indice a buscar: ");
            scanf("%d", &indiceBuscado);
            buscarVectorPorIndice(indiceBuscado, numero, MAX);
            break;
        }
    }while(opcion<0 || opcion>3);

    return 0;
}

void menu()
{
    printf("MENU \n \n 1. Cargar vector \n 2. Buscar por numero \n 3. Buscar por indice \n \n 0. Salir");
}

void cargarVector(int num[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("Ingrese numero: ");
        scanf("%d", &num[i]);
    }
}

void buscarVectorPorNumero(int numBuscado, int num[], int tam)
{
    int i, auxiliar, posicion, flag;
    flag=0;
    for(i=0;i<tam;i++)
    {
        if(numBuscado==num[i])
        {
            auxiliar = numBuscado;
            posicion = i;
            printf("\n\nNumero: %d \t Indice: %d \n", auxiliar, posicion);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nError! Numero no encontrado. \n");
    }

}

void buscarVectorPorIndice(int indiceBuscado, int num[], int tam)
{
    int i, auxiliar, posicion, flag;
    flag=0;
    for(i=0;i<tam;i++)
    {
        if(indiceBuscado==i)
        {
            posicion = i;
            auxiliar = num[i];
            printf("\n\nNumero: %d \t Indice: %d \n", auxiliar, posicion);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nError! Indice no encontrado. \n");
    }

}
