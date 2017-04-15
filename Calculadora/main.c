#include <stdio.h>
#include <stdlib.h>
#define SUMA 1
#define RESTA 2
#define MULTIPLICACION 3
#define DIVISION 4

int main()
{
    int numero1;
    int numero2;
    int total;
    char rta;
    int operacion;

do{
    system("cls");

    do{
        printf("1er numero: ");
        scanf("%d", &numero1);
    }while(numero1<=0);

    do{
        printf("2do numero: ");
        scanf("%d", &numero2);
    }while(numero2<=0);

    do{
        system("cls");
        printf("\nMENU----------------------------------\n \n Elija una operacion: \n 1- SUMA \n 2- RESTA \n 3- MULTIPLICACION \n 4- DIVISION \n \n 5- SALIR \n \n Respuesta: ");
        scanf("\n \n%d", &operacion);
    }while(operacion<=0 || operacion>5);

    switch(operacion)
    {
        case SUMA:
        total = numero1+numero2;
        break;
        case RESTA:
        total = numero1-numero2;
        break;
        case MULTIPLICACION:
        total = numero1*numero2;
        break;
        case DIVISION:
        total = numero1/numero2;
        break;
        default: //CONFIGURAR Y PROGRAMAR
        return 0;
        break;
    }

    printf("\nEl total de la operacion es: %d", total);

    printf("\nDesea continuar? ");
    fflush(stdin);
    scanf("%c", &rta);
}while(rta=='s');


   return 0;
}

