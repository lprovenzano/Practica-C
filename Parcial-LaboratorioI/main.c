#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "funciones.h"


int main()
{
    //Defino los array de estructuras.
    Categoria niveles[4];
    Programador arrayProgramador[MAXPROGRAMADOR];
    Proyecto arrayProyecto[MAXPROYECTO];

    //-----------------------------------
    inicializoEnCero(arrayProgramador, MAXPROGRAMADOR, 0);
    cargarCategorias(niveles);
    hardCodeoProgramador(arrayProgramador);
    int opcion;
    menu();
    do
    {
       opcion = getValidInt("", "Debe ser un numero valido.",0,9);
       switch(opcion)
       {
       case 1:
           altaProgramador(arrayProgramador, MAXPROGRAMADOR);
        break;
        case 2:
            modificarProgramador(arrayProgramador, MAXPROGRAMADOR);
        break;
        case 3:
            borrarProgramador(arrayProgramador, MAXPROGRAMADOR);
        break;
        case 4:
        break;
        case 5:
            listarProgramador(arrayProgramador, MAXPROGRAMADOR);
            getChar("\n\nENTER (para continuar)");
            system("@cls||clear");
            menu();
        break;
        case 6:
        break;
        case 7:
        break;
        case 8:
        break;
       }
    }while(opcion!=0);
    return 0;
}
