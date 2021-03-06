#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "funciones.h"

void menu()
{
    printf("MENU\n----------------------------------\n\n");
    printf("1. Alta de programadores.\n");
    printf("2. Modificar datos de los programadores.\n");
    printf("3. Baja del programador.\n");
    printf("4. Asignar programador a proyecto.\n");
    printf("5. Listado de programadores.\n");
    printf("6. Listado de todos los proyectos.\n");
    printf("7. Listar proyectos de programador.\n");
    printf("8. Proyecto demandante.\n\n");
    printf("9. Salir.\n\n");

}

void inicializoEnCero(Programador arrayProgramador[], int tam, int valor)
{
    int i;
    for(i=0; i<tam; i++)
    {
        arrayProgramador[i].estado = valor;
    }
}

void cargarCategorias(Categoria niveles[])
{
    int categorias[3] = {1, 2, 3};
    char detalle[3][21] = {"JUNIOR", "SEMISR", "SENIOR"};
    float pago[3] = {10.5, 25.5, 55.5};
    int i;
    for(i=0; i<3; i++)
    {
        niveles[i].idCategoria = categorias[i];
        strcpy(niveles[i].descripcion, detalle[i]);
        niveles[i].pagoPorHora = pago[i];
    }
}

void altaProgramador(Programador arrayProgramador[], int tam)
{
    int i, flag=0;
    for(i=0; i<tam; i++)
    {
        if(arrayProgramador[i].estado==0)
        {
            arrayProgramador[i].id = i+1;
            getValidString("Nombre: ", "No puede contener numeros y/o simbolos.", arrayProgramador[i].nombre);
            getValidString("Apellido: ", "No puede contener numeros y/o simbolos.", arrayProgramador[i].apellido);
            printf("Categoria\n1. JUNIOR\n2. SEMISR\n3. SENIOR\n");
            arrayProgramador[i].idCategoria = getInt("");
            arrayProgramador[i].estado = 1;
            flag = 1;
            system("@cls||clear");
            printf("El programador se cargo con exito.");
            getChar("\n\nENTER (para continuar)");
            break;
        }
    }
    if(flag==0)
    {
        printf("No hay espacio disponible.");
    }
    system("@cls||clear");
    menu();
}

void cargarProgramador(Programador arrayProgramador[])
{
    //Cargo algunos por defecto para test
    int id[3] = {1, 2, 3};
    char nombre[3][21] = {"Carlos", "Christian", "Juan"};
    char apellido[3][21] = {"Molina", "Miro", "Perez"};
    int categoria[3] = {2,1,3};
    int k;
    for(k=0; k<3; k++)
    {
        arrayProgramador[k].id = id[k];
        strcpy(arrayProgramador[k].nombre, nombre[k]);
        strcpy(arrayProgramador[k].apellido, apellido[k]);
        arrayProgramador[k].idCategoria = categoria[k];
        arrayProgramador[k].estado = 1;
    }
}

void listarProgramador(Programador arrayProgramador[], Categoria niveles[],int tam, ProgramadorProyecto progProyecto[], Proyecto arrayProyecto[], int tamProy)
{
    int i,j,k;
    char auxCategoria[21], proyectoAux[51];
    //Carga secuencial por opcion
    system("@cls||clear");
    printf("LISTADO DE PROGRAMADORES\n");
    printf("-------------------------------------------------------\n\n");
    printf("| ID |    NOMBRE    |     APELLIDO     | CATEGORIA |  PROYECTO   | MONTO |\n\n");
    for(i=0; i<tam; i++)
    {
        if(arrayProgramador[i].estado!=0)
        {
            for(j=0; j<4; j++)
            {
                if(arrayProgramador[i].idCategoria == niveles[j].idCategoria)
                {
                    strcpy(auxCategoria, niveles[j].descripcion);
                    break;
                }
            }

            for(k=0;k<tam;k++)
            {
                if(arrayProgramador[i].id==progProyecto[k].idProgramador)
                {
                    for(j=0;j<tamProy;j++)
                    {
                        if(progProyecto[k].idProyecto == arrayProyecto[j].id)
                        {
                            strcpy(proyectoAux, arrayProyecto[j].titulo);
                            break;
                        }
                    }
                }
               break;
            }
            printf("  %d\t  %-10s\t%-11s\t%-10s\t%-s\n--------------------------------------------------------------------------------\n", arrayProgramador[i].id,arrayProgramador[i].nombre, arrayProgramador[i].apellido, auxCategoria, proyectoAux);
        }
    }
}

int buscarProgramadorId(Programador arrayProgramador[], int busqueda, int tam)
{
    int i, flag=0;
    for(i=0; i<tam; i++)
    {
        if(busqueda == arrayProgramador[i].id)
        {
            flag=1;
            break;
        }
    }
    return flag;
}

void modificarProgramador(Programador arrayProgramador[], Categoria niveles[], int tam)
{
    //listarProgramador(arrayProgramador, niveles, tam);
    int i, idAuxiliar, validoBusqueda,flag=0, opcion;
    printf("\n--------------------------------------------------------------------------------\n\n");
    idAuxiliar = getValidInt("ID de Programador a modificar: ", "Error! solo numerico.", 1,50);
    validoBusqueda = buscarProgramadorId(arrayProgramador, idAuxiliar, tam);
    while(validoBusqueda!=1)
    {
        printf("Ese ID no existe.");
        getChar("\n\nENTER (para continuar)");
        system("@cls||clear");
//        listarProgramador(arrayProgramador, niveles, tam);
        printf("\n--------------------------------------------------------------------------------\n\n");
        idAuxiliar = getValidInt("ID de Programador a modificar: ", "Error! solo numerico.", 1,50);
        validoBusqueda = buscarProgramadorId(arrayProgramador, idAuxiliar, tam);
    }
    system("@CLS||clear");
//    listarProgramador(arrayProgramador, niveles, tam);
    opcion = getValidInt("\nParametro a modificar: \n\n 1. Nombre \n 2. Apellido \n 3. Categoria\n\n", "Solo numerico", 1,3);
    for(i=0; i<tam; i++)
    {
        if(idAuxiliar==arrayProgramador[i].id)
        {
            switch(opcion)
            {
            case 1:
                getValidString("\nNombre: ", "Solo letras.", arrayProgramador[i].nombre);
                flag=1;
                break;
            case 2:
                getValidString("\nApellido: ", "Solo letras.", arrayProgramador[i].apellido);
                flag=1;
                break;
            case 3:
                printf("\nCategoria\n1. JUNIOR\n2. SEMISR\n3. SENIOR\n");
                arrayProgramador[i].idCategoria= getValidInt("", "Solo numerico.", 1,3);
                flag=1;
                break;
            }
//            listarProgramador(arrayProgramador, niveles, tam);
            printf("\n\nSe ha modificado con exito");
            getChar("\n\nENTER (para continuar)");
            break;
        }
    }
    if(flag==0)
    {
        printf("No se ha podido modificar");
    }
    system("@cls||clear");
    menu();

}

void borrarProgramador(Programador arrayProgramador[], Categoria niveles[], int tam)
{
//    listarProgramador(arrayProgramador, niveles, tam);
    int i, idAuxiliar, validoBusqueda,flag=0;
    printf("\n--------------------------------------------------------------------------------\n\n");
    idAuxiliar = getValidInt("ID de Programador a borrar: ", "Error! solo numerico.", 1,50);
    validoBusqueda = buscarProgramadorId(arrayProgramador, idAuxiliar, tam);
    while(validoBusqueda!=1)
    {
        printf("Ese ID no existe.");
        getChar("\n\nENTER (para continuar)");
        system("@cls||clear");
//        listarProgramador(arrayProgramador, niveles,tam);
        printf("\n--------------------------------------------------------------------------------\n\n");
        idAuxiliar = getValidInt("ID de Programador a borrar: ", "Error! solo numerico.", 1,50);
        validoBusqueda = buscarProgramadorId(arrayProgramador, idAuxiliar, tam);
    }
    system("@CLS||clear");
    for(i=0; i<tam; i++)
    {
        if(idAuxiliar==arrayProgramador[i].id && arrayProgramador[i].estado==1)
        {
            arrayProgramador[i].estado=0;
            flag=1;
            printf("Se ha borrado con exito.");
            getChar("\n\nENTER (para continuar)");
            system("@cls||clear");
            break;
        }
    }
    if(flag==0)
    {
        printf("No se ha podido borrar.");
        getChar("\n\nENTER (para continuar)");
        system("@cls||clear");
        menu();
    }
    menu();
}

void cargarProyecto(Proyecto arrayProyecto[])
{
    int i;
    int idProyecto[3] = {5,6,7};
    char descripcion [3][51] = {"Programador Android","Programador PHP/MySQL","Programador JAVA"};
    //int cantidad[3] = {3,1,2};

    for(i=0; i<3; i++)
    {
        arrayProyecto[i].id = idProyecto[i];
        strcpy(arrayProyecto[i].titulo, descripcion[i]);
        arrayProyecto[i].cantProgramadores = 0;
    }
}

void listarProyecto(Proyecto arrayProyecto[], int tam)
{
    int j;
    printf("| ID |          NOMBRE          |   CANT. PROGRAMADORES\n\n");
    for(j=0; j<tam; j++)
    {
        printf("  %d\t%-25s\t%d\n", arrayProyecto[j].id,arrayProyecto[j].titulo, arrayProyecto[j].cantProgramadores);
    }
}

void asignarProgramador(Programador arrayProgramador[], int tamProg, Proyecto arrayProyecto[], int tamProy, ProgramadorProyecto progProyecto[], Categoria niveles[])
{
    int idAuxiliarProgramador,idAuxiliarProyecto,validoBusqueda, i,j,k,horas, flag=0;
//    listarProgramador(arrayProgramador, niveles,tamProg);
    printf("\n--------------------------------------------------------------------------------\n\n");
    idAuxiliarProgramador = getValidInt("ID de Programador: ", "Error! solo numerico.", 1,50);
    validoBusqueda = buscarProgramadorId(arrayProgramador, idAuxiliarProgramador, tamProg);
    while(validoBusqueda!=1)
    {
        printf("Ese ID no existe.");
        getChar("\n\nENTER (para continuar)");
        system("@cls||clear");
//        listarProgramador(arrayProgramador, niveles,tamProg);
        printf("\n--------------------------------------------------------------------------------\n\n");
        idAuxiliarProgramador = getValidInt("ID de Programador: ", "Error! solo numerico.", 1,50);
        validoBusqueda = buscarProgramadorId(arrayProgramador, idAuxiliarProgramador, tamProg);
    }
    system("@cls||clear");
    listarProyecto(arrayProyecto, tamProy);
    printf("\n--------------------------------------------------------------------------------\n\n");
    idAuxiliarProyecto = getValidInt("ID de Proyecto: ", "Error! solo numerico.", 5,7);
    horas = getFloat("Cantidad de horas: ");
    //Cargo estructura relacional.
    int auxCant=0;
    for(i=0; i<tamProg; i++)
    {
        progProyecto[i].idProgramador = idAuxiliarProgramador;
        progProyecto[i].idProyecto = idAuxiliarProyecto;
        progProyecto[i].cantHoras = horas;
        auxCant += 1;
        for(j=0;j<3;j++)
        {
            if(progProyecto[i].idProyecto == arrayProyecto[j].id)
            {
                arrayProyecto[j].cantProgramadores = auxCant;
                break;
            }
        }
        flag=1;
        printf("Se ha asignador correctamente el programador al proyecto.");
        getChar("\n\nENTER (para continuar)");
        system("@cls||clear");
        break;
    }
    if(flag==0)
    {
        printf("No se ha podido asignar.");
        getChar("\n\nENTER (para continuar)");
        system("@cls||clear");
    }
    menu();
}
