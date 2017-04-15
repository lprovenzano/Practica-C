#include <stdio.h>
#include <stdlib.h>

//Escribir en y codificar en C un programa que muestre los múltiplos de 6 comprendidos entre 0 y 100.

int main()
{
    int multiplos;

    /*for(multiplos=0;multiplos<100;multiplos++)
    {
        if(multiplos%6==0)
        {
            printf("%d \n", multiplos);
        }
    }*/
    multiplos=0;
    do
    {


        if(multiplos%6==0)
        {
            printf("%d \n", multiplos);
        }
    multiplos++;

    }while(multiplos<100);

    return 0;
}
