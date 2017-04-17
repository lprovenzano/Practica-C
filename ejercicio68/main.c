#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAX 50

int main()
{
    int mesa[MAX], opcion, buscarMesa;
    float consumo;
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
            opcion=5;
            break;
        case 3:
            system("CLS");
            menu();
            printf("\n\nMonto: $ ");
            scanf("%.2f", &consumo);
            system("CLS");
            menu();
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



