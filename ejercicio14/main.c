#include <stdio.h>
#include <stdlib.h>

/*Diseñar un programa que imprima y sume la serie de números 3,6,9,12,...,99.*/

int main()
{
    int serie;
    /*serie=0;
    do{
        printf("%d \n", serie);
        serie+=3;
    }while(serie<100);*/

    //FOR

    for(serie=0;serie<100;serie+=3)
    {
        printf("%d \n", serie);
    }

    return 0;
}
