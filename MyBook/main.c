#include <stdio.h>
#include <stdlib.h>
#include "inc/ArrayList.h"
#include "inc/utn.h"
#include "inc/mensaje.h"
#include "inc/usuario.h"

int main()
{
    ArrayList* listado_usuarios = al_newArrayList();
    ArrayList* listado_mensajes = al_newArrayList();
    int i;

    if((cargarUsuario(listado_usuarios))==0)
    {
        pause("Usuarios cargados correctamente.");
    }
    else
    {
        pause("No se cargaron los usuarios.");
    }
    if((cargarMensajes(listado_mensajes))==0)
    {
        pause("Mensajes cargados correctamente.");
    }
    else
    {
        pause("No se cargaron los mensajes.");
    }



    return 0;
}
