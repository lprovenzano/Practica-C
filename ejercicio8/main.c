#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
        Diseñar un programa que calcule la superficie de un triángulo
        a partir del ingreso de su base y altura y muestre el resultado.
    */

    float base, altura, total;

    do
    {
        printf("Ingrese la base (cm): ");
        scanf("%f", &base);
        printf("Ingrese la altura (cm): ");
        scanf("%f", &altura);

        total = (base*altura)/2;

    }while(base<0 || altura<0);

    printf("\n Superficie: %f \n", total);

    return 0;
}
