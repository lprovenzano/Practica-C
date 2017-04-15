#include <stdio.h>
#include <stdlib.h>

/*
    En una empresa se carga por teclado los siguientes datos:
    nombre del empleado, nacionalidad (A argentino, E -extranjero),
    estudios cursados (1- primaria, 2 - secundario, 3 - universitario) y antigüedad.
    Se pide emitir un listado con aquellos empleados que sean extranjeros,
    tengan estudios universitarios y tengan una antigüedad igual o mayor a 20 años
    y por último indicar cuantos son y qué porcentaje son respecto del total de empleados de la empresa
*/

int main()
{
    //Defino variables
    char nombreEmpleado[20], nacionalidad, rta;
    int  estudios, antiguedad, cantidadEmpleadosExt;

    do {
        system("CLS");

        printf("Nombre empleado: ");
        fflush(stdin);
        scanf("%s", nombreEmpleado);

        do
        {
            printf("\n Nacionalidad ---------------------------------- \n \n A - Argentina \n E - Extranjero \n \n Respuesta: ");
            fflush(stdin);
            scanf("%c", &nacionalidad);
            if(nacionalidad!='a' && nacionalidad!='e')
            {
                system("CLS");
            }
        }while(nacionalidad!='a' && nacionalidad!='e');

        do
        {
            printf("\n Estudios ---------------------------------- \n \n 1 - Primaria \n 2 - Secundario \n 3 - Universitario \n \n Respuesta: ");
            scanf("%d", &estudios);
            if(estudios<1 || estudios>3)
            {
                system("CLS");
            }

        }while(estudios<1 || estudios>3);

        printf("\n Antiguedad laboral (anios): ");
        scanf("%d", &antiguedad);
        contador++;

        printf("Desea cargar otro alumno? (s|n): ");
        fflush(stdin);
        scanf("%c", &rta);
    }while(rta == 's');

    if(nacionalidad=='e' && estudios==3 && antiguedad>20)
    {
        printf("%s \n", nombreEmpleado);
    }

    return 0;
}
