#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inc/ArrayList.h"
#include "inc/utn.h"
#include "inc/mensaje.h"
#include "inc/usuario.h"

/** \brief Espacio en memoria para un usuario.
 *
 * \param -
 * \param -
 * \return Puntero a User.
 *
 */
Post* new_Post()
{
    Post* this;
    this = (Post*)malloc(sizeof(Post));
    return this;
}

/** \brief Lee el txt con el listado de personas y carga dicha estructura.
 *
 * \param Lista donde se encuentra la estructura.
 * \param Estructura con datos a mostrar.
 * \return [-1]=> Error / NULL. || [0]=> Si se leyó en el txt satisfactoriamente.
 *
 */
int cargarMensajes(ArrayList* this)
{
    int retorno = 0, flag=0;
    FILE* f;
    Post* post;

    char idPost[5];
    char idUser[5];
    char popularidadAux[10];
    char textMensaje[2048];

    if((f = fopen("files/mensajes.csv", "r"))==NULL)
    {
        retorno = -1;
    }

    else
    {
        rewind(f);
        while(!(feof(f)))
        {
            post=new_Post();
            if(post!=NULL)
            {
                if(flag==0)
                {
                    fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n", idPost, idUser, popularidadAux, textMensaje);
                    flag=1;
                }
                else
                {
                    fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n", idPost, idUser, popularidadAux, textMensaje);
                    post->id_usuario = atoi(idPost);
                    post->id_mensaje = atoi(idUser);
                    post->popularidad = atoi(popularidadAux);
                    strcpy(post->mensaje, textMensaje);
                    al_add(this, post);
                    //printf("%d--%d--%d--%s\n\n",post->id_mensaje, post->id_usuario, post->popularidad, post->mensaje);
                }
            }
        }
    }
    fclose(f);
    return retorno;
}

