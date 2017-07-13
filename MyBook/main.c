#include <stdio.h>
#include <stdlib.h>
#include "inc/ArrayList.h"
#include "inc/utn.h"
#include "inc/mensaje.h"
#include "inc/usuario.h"
#include "inc/feed.h"

int main()
{
    ArrayList* listado_usuarios = al_newArrayList();
    ArrayList* listado_mensajes = al_newArrayList();
    ArrayList* listado_feed = al_newArrayList();


    if((cargarUsuario(listado_usuarios))==0)
    {
        printf("Usuarios cargados correctamente.\n");
    }
    else
    {
        printf("No se cargaron los usuarios.\n");
    }
    if((cargarMensajes(listado_mensajes))==0)
    {
        printf("Mensajes cargados correctamente.\n\n");
    }
    else
    {
        printf("No se cargaron los mensajes.\n\n");
    }

    pause("(ENTER) para generar feed...");

    if((listado_feed = crearFeed(listado_usuarios, listado_mensajes))!=NULL)
    {
        if((ordenar(listado_feed))==0)
        {
            guardarFeed(listado_feed);
            pause("Se genero el feed con exito (files/feed.csv)");
        }
    }
    else
    {
        pause("No se ha podido crear el feed :(");
    }

    return 0;
}
