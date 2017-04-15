#include <stdio.h>
#include <stdlib.h>
#define MAX 5

/**

    Otra forma de declarar una estructura

    typedef struct
    {
    char nombre[20];
    int nota;
    }alumno;

    alumno pers[MAX], aux;

    HACER FUNCION FGETS{
        cant=strlen(nombre);
        nombre[cant-1]='\0';
    }

**/

struct alumno
{
    char nombre[20];
    int nota;
};

void main(void)
{
    int i, j;

    struct alumno pers[MAX],aux;

    for(i=0; i<MAX; i++)
    {
        printf("Nombre: ");
        fflush(stdin);
        scanf("%s", pers[i].nombre);
        printf("Nota: ");
        scanf("%d", &pers[i].nota);
    }

    for(i=0; i<MAX-1; i++)
        for(j=i+1; j<MAX; j++)
            if((strcmp(pers[i].nombre,pers[j].nombre))>0)
            {
                aux=pers[i];
                pers[i]=pers[j];
                pers[j]=aux;
            }

    for(i=0; i<MAX; i++)
    {
        printf("%s \n", pers[i].nombre);
        printf("%d \n", pers[i].nota);
    }
}
