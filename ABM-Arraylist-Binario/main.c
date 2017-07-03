/*******************************************************************
*
*   Programa:
*   ~ ArrayList | Implementacion personal.
*
*   Objetivo:
*   Implementacion de la biblioteca ArrayList con archivos de tipo binario (Lectura-Escritura).
*
*
*   Version:
*   0.1 del 02 de julio de 2017.
*
*   Autor:
*   Luca Provenzano | 1F.
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayList.h"
#include "lib.h"
#include "utn.h"

int main()
{
    ArrayList* ListadoPersonas = al_newArrayList();

    Persona* personita;
    char seguir='s', opcionModificacion, guardar;
    int validacion, i, checkIndex;

    if((cargarBinario(ListadoPersonas, personita))==0)
    {
        pause("Archivo binario cargado con exito. (ENTER)");
    }
    else
    {
        pause("Ups! hubo un error... (ENTER)");
    }

    do
    {
        ordenarPorApellido(ListadoPersonas);
        system("CLS");
        switch(menu())
        {
        case '1':
            system("CLS");
            personita = newPersona();
            printf("Para regresar escriba 'salir'\n\n");
            validacion = unaPersona(personita);
            if(validacion!=-1)
            {
                al_add(ListadoPersonas, personita);
                system("CLS");
                pause("\nLa persona se dio de alta correctamente.");
            }
            else
            {
                system("CLS");
                pause("\nSe ha cancelado la operacion.");
            }
            break;
        case '2':
            system("CLS");
            baseListado();

            for(i=0; i<al_len(ListadoPersonas); i++)
            {
                printPersona(ListadoPersonas, al_get(ListadoPersonas,i));
            }

            printf("\nID a dar de baja: ");
            scanf("%d", &checkIndex);

            if(al_remove(ListadoPersonas, checkIndex)!=-1)
                pause("\nLa persona se dio de baja correctamente.");
            else
                pause("\nLa persona no existe.");
            break;

        case '3':
            system("CLS");
            baseListado();
            for(i=0; i<al_len(ListadoPersonas); i++)
            {
                printPersona(ListadoPersonas, al_get(ListadoPersonas,i));
            }

            printf("\nID a modificar: ");
            scanf("%d", &checkIndex);
            personita = (Persona*)al_get(ListadoPersonas, checkIndex);

            if((personita)!=NULL)
            {
                printf("\n1. Nombre.\n2. Apellido.\n3. Edad.\n");
                opcionModificacion = getch();

                switch(opcionModificacion)
                {
                case '1':
                    fflush(stdin);
                    getValidString("\nNombre: ", "Debe ser un nombre valido", personita->nombre);
                    break;
                case '2':
                    fflush(stdin);
                    getValidString("\nApellido: ", "Debe ser un apellido valido", personita->apellido);
                    break;
                case '3':
                    personita->edad = getValidInt("\nEdad: ", "Solo numerico", 0, 100);
                    break;
                }
                pause("\nSe modifico el parametro correctamente.");
            }
            else
            {
                pause("\nLa persona no existe.");
            }
            break;
        case '4':
            system("CLS");
            baseListado();

            for(i=0; i<al_len(ListadoPersonas); i++)
            {
                printPersona(ListadoPersonas, al_get(ListadoPersonas,i));
            }

            pause("\n(ENTER) para regresar.");
            break;
        case '5':
            guardar = tolower(getChar("Desea guardar los cambios realizados? (s|n): "));
            while(guardar!='s' && guardar!='n')
            {
                system("cls");
                printf("Caracter incorrecto. Solo 's' o 'n'\n\n");
                guardar = tolower(getChar("Desea guardar los cambios realizados? (s|n): "));
            }
            if(guardar == 's')
            {
                crearBinario(ListadoPersonas, personita);
                pause("\nSe guardaron los cambios satisfactoriamente.");
            }
            else
            {
                pause("\nNo se guardaron los cambios.");
            }
            seguir ='n';
            break;
        }

    }
    while(seguir=='s');
    return 0;
}
