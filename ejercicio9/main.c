#include <stdio.h>
#include <stdlib.h>


int main()
{
    /*
        Escribir un programa que realice lea por teclado 20 caracteres.
        Luego de la lectura indicar cuantas "a" se ingresaron, cuantas "e, i, o, u"
    */

    int contador, cantidadA, cantidadE, cantidadI, cantidadO, cantidadU, otrasLetras;
    char cuentaLetras;

    cantidadA = 0;
    cantidadE = 0;
    cantidadI = 0;
    cantidadO = 0;
    cantidadU = 0;
    otrasLetras = 0;

    for(contador=0; contador<20; contador++)
    {
        printf("\n Ingrese una vocal (%d): ", contador);
        scanf("%c", &cuentaLetras);
        fflush(stdin);

        switch(cuentaLetras)
        {
        case 97:
            cantidadA++;
            break;
        case 101:
            cantidadE++;
            break;
        case 105:
            cantidadI++;
            break;
        case 111:
            cantidadO++;
            break;
        case 117:
            cantidadU++;
            break;
        default:
            otrasLetras++;
            break;
        }
    }

    printf("\n Cantidad letras A: %d \n ", cantidadA);
    printf("\n Cantidad letras E: %d \n ", cantidadE);
    printf("\n Cantidad letras I: %d \n ", cantidadI);
    printf("\n Cantidad letras O: %d \n ", cantidadO);
    printf("\n Cantidad letras U: %d \n ", cantidadU);
    printf("\n No vocales: %d \n ", otrasLetras);

    return 0;
}
