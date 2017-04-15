#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Declaro variables
    int flag, numero, maximo, minimo, contador, acumulador;
    char rta;

    //Asigno valores
    flag = 0;
    contador = 0;
    acumulador = 0;

    do{
        system("cls");
        printf("Ingrese un numero: ");
        scanf("%d", &numero);

        /*Numero maximo, numero minimo.*/

        if(flag==0)
        {
            maximo = numero;
            minimo = numero;
            flag = 1;
        }

        if(numero>maximo)
        {
            maximo = numero;
        }

        if(numero<minimo)
        {
            minimo = numero;
        }
        //Cantidad de numeros ingresados
        contador++;

        //Sumatoria en acumulacion
        acumulador += numero;

        printf("Desea seguir ingresando numeros? (s/n): ");
        fflush(stdin);
        scanf("%c", &rta);

    }while(rta=='s');

    printf("\n \n Numero maximo: %d", maximo);
    printf("\n \n Numero minimo: %d", minimo);
    printf("\n \n Cantidad de numeros ingresados: %d", contador);
    printf("\n \n Sumatoria de numeros ingresados: %d", acumulador);
    printf("\n \n Promedio de numeros ingresados: %d \n \n", acumulador/contador);

    return 0;
}
