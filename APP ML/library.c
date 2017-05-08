#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#include "library.h"


/**
 * \brief Inicializa el status en un array de libros
 * \param bookArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param value Es el valor que se asignara a status
 * \return -
 *
 */
void setProductoEstado(producto arrayProducto[],int tam,int valor)
{
    int i;
    for(i=0;i < tam; i++)
    {
        arrayProducto[i].estado = valor;
    }
}



/**
 * \brief Busca la primer ocurrencia de un libro mediante su codigo
 * \param bookArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param code Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
int buscarProductoPorCodigo(producto arrayProducto[],int tam,int codigo)
{
    int i;
    for(i=0;i < tam; i++)
    {
        if(arrayProducto[i].codigo == codigo && arrayProducto[i].estado == 1)
        {
            return i;
        }
    }
    return -1;
}


/**
 * \brief Busca el primer lugar no utilizado en el array
 * \param bookArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 *
 */
int buscarLugarLibreEnProductos(producto arrayProducto[],int tam)
{
    int i;
    for(i=0;i < tam; i++)
    {
        if(arrayProducto[i].estado == 0)
        {
            return i;
        }
    }
    return -1;
}



/**
 * \brief Busca el precio promedio
 * \param bookArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay bookos activos (-1) y si lo hay el precio de ese booko
 *
 */
void ordenarProductosPorTitulo(producto arrayProducto[],int tam)
{
    producto auxProducto;
    int i,j;

    for(i=0; i < tam - 1; i++)
    {
        if(arrayProducto[i].estado == 0)
        {
            continue;
        }
        for(j=i+1; j < tam; j++)
        {
            if(arrayProducto[j].estado == 0)
            {
                continue;
            }
            if(strcmp(arrayProducto[j].titulo,arrayProducto[i].titulo)<0)
            {
                auxProducto = arrayProducto[j];
                arrayProducto[j] = arrayProducto[i];
                arrayProducto[i] = auxProducto;
            }
            else if(strcmp(arrayProducto[j].titulo,arrayProducto[i].titulo) == 0)
            {
                if(arrayProducto[i].codigo > arrayProducto[j].codigo)
                {
                    auxProducto = arrayProducto[j];
                    arrayProducto[j] = arrayProducto[i];
                    arrayProducto[i] = auxProducto;
                }
            }
        }
    }
}

/**
 * \brief Carga los valores del libro
 * \param bookArray Es el array de libros
 * \param freePlaceIndex Indica la posicion a setear
 * \param codeAux Codigo del libro
 * \param titleAux Titulo del libro
 * \param authorIdAux Id del autor
 * \param stockIdAux Cantidad de ejemplaes disponibles
 * \return -
 *
 */
void setearProducto(producto arrayProducto[],int lugarLibre, int codigoAux,char tituloAux[], int idUsuarioAux,int stockAux, float precioAux)
{

    arrayProducto[lugarLibre].usuarioID = idUsuarioAux;
    arrayProducto[lugarLibre].precio = precioAux;
    strcpy(arrayProducto[lugarLibre].titulo,tituloAux);
    arrayProducto[lugarLibre].stock = stockAux;
    arrayProducto[lugarLibre].codigo = codigoAux;
    arrayProducto[lugarLibre].estado = 1;
}

/**
 * \brief Muestra los libros activos por pantalla
 * \param bookArray Es el array de libros
 * \param arrayLenght Indica la logitud del array
 * \return -
 */
void mostrarProductos(producto arrayProducto[],int tam)
{
    int i;
    printf("\n| CODIGO  |                      TITULO              | PRECIO | USUARIO | STOCK |");
    for(i=0;i < tam; i++)
    {
        if(arrayProducto[i].estado != 0)
        {
            printf("\n| %6d  | %-40s | %-6.2f | %5d | %5d |",arrayProducto[i].codigo,arrayProducto[i].titulo,arrayProducto[i].precio,arrayProducto[i].usuarioID,arrayProducto[i].stock);
        }
    }

}

//_____________________USUARIOS______________________________

/**
 * \brief Inicializa el status en un array de autores
 * \param authorArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param value Es el valor que se asignara a status
 * \return -
 *
 */
void setUsuarioEstado(usuario arrayUsuario[],int tam,int valor)
{
    int i;
    for(i=0;i < tam; i++)
    {
        arrayUsuario[i].estado = valor;
    }
}

/**
 * \brief Busca la primer ocurrencia de un autor mediante su codigo
 * \param authorArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param authorIdAux Es el id que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
int buscarUsuarioPorID(usuario arrayUsuario[],int tam,int idUsuario)
{
    int i;
    for(i=0;i < tam; i++)
    {
        if(arrayUsuario[i].usuarioID == idUsuario && arrayUsuario[i].estado == 1)
        {
            return i;
        }
    }
    return -1;
}


/**
 * \brief Carga los valores del autor
 * \param authorArray Es el array de autores
 * \param freePlaceIndex Indica la posicion a setear
 * \param authorIdAux Id del autor
 * \param nameAux Nombre del autor
 * \param lastNameAux Apellido del autor
 * \return -
 *
 */
void setearUsuario(usuario arrayUsuario[],int lugarLibre, int idUsuarioAux,char nombreAux[], int califiAux)
{

    arrayUsuario[lugarLibre].usuarioID = idUsuarioAux;
    strcpy(arrayUsuario[lugarLibre].nombre,nombreAux);
    arrayUsuario[lugarLibre].calificacion = califiAux;
    arrayUsuario[lugarLibre].estado = 1;

}


/**
 * \brief Busca el primer lugar no utilizado en el array
 * \param authorArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 *
 */
int lugarLibreUsuarios(usuario arrayUsuario[],int tam)
{
    int i;
    for(i=0;i < tam; i++)
    {
        if(arrayUsuario[i].estado == 0)
        {
            return i;
        }
    }
    return -1;
}

/**
 * \brief Muestra los autores activos por pantalla
 * \param authorArray Es el array de autores
 * \param arrayLenght Indica la logitud del array
 * \return -
 */
void mostrarUsuarios(usuario arrayUsuario[],int tam)
{
    int i;
    printf("\n| ID USUARIO  |      NOMBRE      |    CALIFICACION     ");
    for(i=0;i < tam; i++)
    {
        if(arrayUsuario[i].estado != 0)
        {
            printf("\n| %-10d  | %-15s  | %-15d",arrayUsuario[i].usuarioID, arrayUsuario[i].nombre,arrayUsuario[i].calificacion);
        }
    }

}


/**
 * \brief Muestra los libros activos por pantalla indicando el apellido del Autor
 * \param bookArray Es el array de libros
 * \param arrayLenght Indica la logitud del array libros
 * \param authorArray Es el array de autores
 * \param arrayLenght Indica la logitud del array autores
 * \return -
*/
void mostrarUsuarioProducto(producto arrayProducto[],int tamProducto,usuario arrayUsuario[],int tamUsuario)
{
    int i;
    //char auxAuthor[51];
    char auxUsuario[51];
    int usuarioIdAux;
    printf("\n| CODIGO  |            TITULO            |     AUTOR    | STOCK |  PRECIO |");
    for(i=0;i < tamProducto; i++)
    {
        if(arrayProducto[i].estado != 0)
        {
            usuarioIdAux = buscarUsuarioPorID(arrayUsuario,tamUsuario,arrayProducto[i].usuarioID);
            if( usuarioIdAux != -1)
            {
                strcpy(auxUsuario,arrayUsuario[usuarioIdAux].nombre);
            }
            else
            {
                sprintf(auxUsuario, "? (Id:%d)", arrayProducto[i].usuarioID);
            }
            printf("\n| %6d  | %-28s | %-12s | %5d | %6.2f |",arrayProducto[i].codigo,arrayProducto[i].titulo,auxUsuario,arrayProducto[i].stock, arrayProducto[i].precio);
        }
    }

}
