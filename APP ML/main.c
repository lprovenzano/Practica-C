/******************************************************************
* Programa: APP ML
*
* Objetivo:
*           ALTA BAJA MODIFICACION DE PRODUCTOS Y USUARIOS.
*
* Version: 0.1 del 08 de mayor de 2017
* Autor: Luca Provenzano | 1F
*
*
* *******************************************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#include "library.h"



void adminProductos (producto arrayProducto[],usuario arrayUsuario[]);
void adminUsuarios(usuario arrayUsuario[]);

int main()
{
    // arrays de libros
    producto arrayProducto[MAXPRODUCTOS];
    setProductoEstado(arrayProducto,MAXPRODUCTOS,0);
    //________________________________________________

    // arrays de libros
    usuario arrayUsuario[MAXUSUARIOS];
    setUsuarioEstado(arrayUsuario,MAXUSUARIOS,0);
    //________________________________________________


    // Alta de datos para testing
    setearProducto(arrayProducto,1,1,"Oso de Peluche Gigante",1,777,300.432);
    setearProducto(arrayProducto,1,2,"Pelota de futbol 5",2,32,80.552);

    setearUsuario(arrayUsuario,1,2,"Esteban",7);
    //________________________________________________

    int option = 0;

    while(option != 4)
    {
        system("@cls||clear");
        printf("\n------------  MENU PRINCIPAL ------------");
        option = getInt("\n1 - ABM PRODUCTOS \n2 - ABM USUARIOS \n3 - LISTAR PRUBLICACIONES\n4 - SALIR\n\n\n");
        switch(option)
        {
            case 1: // ABM PRODUCTOS
                adminProductos(arrayProducto, arrayUsuario);
                break;
            case 2: // ABM USUARIOS
                adminUsuarios(arrayUsuario);
                break;
            case 3: // LISTAR
                system("@cls||clear");
                mostrarUsuarioProducto(arrayProducto,MAXPRODUCTOS,arrayUsuario,MAXUSUARIOS);
                getChar("\n\nENTER (para continuar)");

                break;

        }
    }


    return 0;
}


void adminUsuarios(usuario arrayUsuario[])
{
    // variables auxiliares
    char nombreAux[51];
    int idUsuarioAux;
    int califAux;
    //________________________________________________

    int lugarLibre;
    int indiceEncontrado;
    int option = 0;
    int i;

    while(option != 4)
    {
         system("@cls||clear");
         printf("\n------------  ABM USUARIOS ------------");
         option = getInt("\n1 - ALTA \n2 - BAJA \n3 - LISTAR\n4 - REGRESAR\n\n\n");
         switch(option)
         {
            case 1: // ALTA DE USUARIO

                lugarLibre = lugarLibreUsuarios(arrayUsuario,MAXUSUARIOS);
                if(lugarLibre == -1)
                {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }

                //idUsuarioAux = getValidInt("Ingrese el ID del usuario: ","El ID del usuario debe ser numerico\n", 1, 100);
                idUsuarioAux = getNumeroAleatorio(1,100,1);
                for(i=0;i<MAXUSUARIOS;i++) //VALIDO QUE NO SE REPITA EL RANDOM.
                {
                    if(idUsuarioAux == arrayUsuario[i].usuarioID)
                    {
                        idUsuarioAux = getNumeroAleatorio(1,100,1);
                        break;
                    }
                }
                /*if(buscarUsuarioPorID(arrayUsuario,MAXUSUARIOS,idUsuarioAux) != -1)
                {
                    printf("\n\nEL CODIGO YA EXISTE!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }*/

                getValidString("Ingrese el nombre del usuario: ","El nombre debe estar compuesto solo por letras\n", nombreAux);

                califAux = getValidInt("Ingrese la calificacion del usuario: ","Debe ser numérica de (1-10)\n", 1, 10);

                setearUsuario(arrayUsuario,lugarLibre,idUsuarioAux,nombreAux,califAux);

                break;

            case 2: // BAJA AUTOR

                idUsuarioAux = getValidInt("Ingrese el ID del usuario: ","El ID del usuario debe ser numerico\n", 1, 100);
                indiceEncontrado = buscarUsuarioPorID(arrayUsuario,MAXUSUARIOS,idUsuarioAux);
                if(indiceEncontrado == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE ID DE USUARIO\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }
                arrayUsuario[indiceEncontrado].estado = 0;
                break;

            case 3: // LISTAR
                system("@cls||clear");
                mostrarUsuarios(arrayUsuario,MAXUSUARIOS);
                getChar("\n\nENTER (para continuar)");
                break;


         }
    }
}








void adminProductos(producto arrayProducto[], usuario arrayUsuario[])
{
    // variables auxiliares
    char tituloAux[51];

    int idUsuarioAux;
    int codigoAux;
    int stockAux;
    float precioAux;
    //________________________________________________

    int lugarLibreProducto;
    int indiceEncontrado;
    int option = 0;
    int i;
    int validoLetras;

    while(option != 6)
    {
         system("@cls||clear");
         printf("\n------------  ABM PRODUCTO ------------");
         option = getInt("\n1 - ALTA \n2 - BAJA \n3 - MODIFICACION\n4 - LISTAR\n5 - ORDENAR\n6 - REGRESAR\n\n\n");
         switch(option)
         {
            case 1: // ALTA DE PRODUCTO

                lugarLibreProducto = buscarLugarLibreEnProductos(arrayProducto,MAXPRODUCTOS);
                if(lugarLibreProducto == -1)
                {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }

                //codigoAux = getValidInt("Ingrese el codigo del libro: ","El codigo del libro debe ser numerico\n", 1, 1000);
                codigoAux = getNumeroAleatorio(1,1000,1);
                for(i=0;i<MAXPRODUCTOS;i++) //VALIDO QUE NO SE REPITA EL RANDOM.
                {
                    if(codigoAux == arrayProducto[i].codigo)
                    {
                        codigoAux = getNumeroAleatorio(1,1000,1);
                        break;
                    }
                }
                if(buscarProductoPorCodigo(arrayProducto,MAXPRODUCTOS,codigoAux) != -1)
                {
                    printf("\n\nEL CODIGO YA EXISTE!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }

                idUsuarioAux =  getValidInt("Ingrese el ID del usuario autor: ","El ID del autor debe ser numerico\n", 1, 100);
                indiceEncontrado = buscarUsuarioPorID(arrayUsuario,MAXUSUARIOS,idUsuarioAux);
                while(indiceEncontrado == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE ID DE USUARIO\n");
                    getChar("\n\nENTER (para continuar)");
                    idUsuarioAux =  getValidInt("Ingrese el ID del usuario autor: ","El ID del autor debe ser numerico\n", 1, 100);
                    indiceEncontrado = buscarUsuarioPorID(arrayUsuario,MAXUSUARIOS,idUsuarioAux);
                }

                /*getValidString("Ingrese el titulo: ","El titlo debe estar compuesto solo por letras\n", tituloAux);*/
                do
                {
                    printf("Ingrese titulo: ");
                  fflush(stdin);
                  gets(tituloAux);
                  validoLetras=esSoloLetras(tituloAux);
                }while(validoLetras==0);

                stockAux = getValidInt("Ingrese la cantidad de unidades: ","La cantidad debe ser numerica\n", 1, 1000);

                precioAux = getFloat("Precio del producto: $");

                setearProducto(arrayProducto,lugarLibreProducto,codigoAux,tituloAux,idUsuarioAux,stockAux, precioAux);

                break;

            case 2: // BAJA PRODUCTO

                codigoAux = getValidInt("Ingrese el codigo de producto a dar de baja: ","El codigo del producto debe ser numerico\n", 1, 1000);
                indiceEncontrado = buscarProductoPorCodigo(arrayProducto,MAXPRODUCTOS,codigoAux);
                if(indiceEncontrado == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }
                arrayProducto[indiceEncontrado].estado = 0;
                break;

            case 3: // MODIFICAR PRODUCTO

                codigoAux = getValidInt("Ingrese el codigo del producto a modificar: ","El codigo del producto debe ser numerico\n", 1, 1000);
                indiceEncontrado = buscarProductoPorCodigo(arrayProducto,MAXPRODUCTOS,codigoAux);
                if(indiceEncontrado == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }


                //idUsuarioAux =  getValidInt("Ingrese el ID del autor de la publicacion: ","El ID del autor debe ser numerico\n", 1, 100);

                stockAux = getValidInt("Ingrese la cantidad de unidades: ","La cantidad debe ser numerica\n", 1, 10000);

                getValidString("Ingrese el titulo: ","El titulo debe estar compuesto solo por letras\n", tituloAux);

                precioAux = getFloat("Precio del producto: $");

                setearProducto(arrayProducto,lugarLibreProducto,codigoAux,tituloAux,idUsuarioAux,stockAux, precioAux);

                break;

            case 4: // LISTAR
                system("@cls||clear");
                mostrarProductos(arrayProducto,MAXPRODUCTOS);
                getChar("\n\nENTER (para continuar)");
                break;

            case 5: // ORDENAR
                ordenarProductosPorTitulo(arrayProducto,MAXPRODUCTOS);
                getChar("\n\nOrdenados. ENTER (para continuar)");
                break;


         }
    }
}
