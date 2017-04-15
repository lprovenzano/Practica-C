#include <stdio.h>
#include <stdlib.h>

/*
    Diseñar un programa que permita calcular el promedio de un alumno sabiendo que se
    ingresa por alumno la nota de 6 materias y su nombre. No se sabe la cantidad de alumnos.

    Se pide un listado impreso que diga:

    NOMBRE DEL ALUMNO: PROMEDIO:
*/

int main()
{
    //Declaro variables
    int materias, nota, acumulador, promedio;
    char nombre[15], rta;

    //Asgino valores
    acumulador =0;

    do
    {
        materias=0;
        printf("Nombre del alumno: ");
        fflush(stdin);
        scanf("%s", nombre);

        printf("\n ---- NOTAS ----- \n");

        do{
            materias++;
            do
            {
                printf("\n \n Materia (%d): ", materias);
                scanf("%d", &nota);

                if(nota<0 || nota>10)
                {
                    system("CLS");
                }

            }while(nota<0 || nota>10);

            acumulador +=nota;
            promedio = acumulador / materias;

        }while(materias<6);

        if(materias==6)
            {
                if(promedio<7)
                {
                    printf("\n NOMBRE DEL ALUMNO: %s", nombre);
                    printf("\t PROMEDIO: %d", promedio);
                    printf("\t Aprueba: NO");
                }
                else
                {
                    printf("\n NOMBRE DEL ALUMNO: %s", nombre);
                    printf("\t PROMEDIO: %d", promedio);
                    printf("\t Aprueba: SI");
                }
            }

        printf("\n \n Desea agregar otro alumno? (s|n)");
        fflush(stdin);
        scanf("%c", &rta);
        system("CLS");

    }while(rta == 's');
    return 0;
}
