#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inc/ArrayList.h"
#include "inc/utn.h"
#include "inc/mensaje.h"
#include "inc/usuario.h"
#include "inc/feed.h"

/** \brief Espacio en memoria para feed.
 *
 * \param -
 * \param -
 * \return Puntero a Feed.
 *
 */
Feed* new_Feed()
{
    Feed* this;
    this = (Feed*)malloc(sizeof(Feed));
    return this;
}

/** \brief Imprime en pantalla la estructura Feed
 *
 * \param Puntero a Feed.
 * \param -
 * \return void.
 *
 */

void list_printFeed(Feed* feed)
{
    printf("\nUSUARIO (%d): %s \t PUNTUACION: %d\n\n%s\n\nLIKES: %d", feed->id_usuario, feed->nick, feed->popularidad_usuario, feed->mensaje, feed->popularidad_mensaje);
    printf("\tPUBLICACION NRO: %d\n\n---------------------------------------------------------------------\n", feed->id_mensaje);
}

/** \brief compara 2 elementos del tipo Feed
 * \param primer elemento a comparar
 * \param segundo elemento a comparar
 * \return 1 - el primer elemento es mayor al segundo
          -1 - el primer elemento es menor al segundo
           0 - los dos elementos son iguales
 *
 */

int compare(Feed* elemento1, Feed* elemento2)
{
    int retorno = 0;
    if((elemento1->popularidad_usuario) > (elemento2->popularidad_usuario))
    {
        retorno = 1;
    }
    if((elemento1->popularidad_usuario) < (elemento2->popularidad_usuario))
    {
        retorno = -1;
    }

    if((elemento1->popularidad_usuario) == (elemento2->popularidad_usuario))
    {
        if((elemento1->popularidad_mensaje) > (elemento2->popularidad_mensaje))
        {
            retorno = 0;
        }
    }
    return retorno;
}


/** \brief Ordena los elementos de la lista de forma descendiente.
 *
 * \param Lista a ordenar.
 * \param -
 * \return 0 OK | -1 ERROR.
 *
 */

int ordenar(ArrayList* this)
{
    int retorno = 0;
    if((al_sort(this, compare, 0))!=0)
    {
        retorno = -1;
    }
    return retorno;
}

/** \brief Crea la lista Feed relacionando las listas de usuarios y publicaciones
 *
 * \param Lista de usuarios
 * \param Lista de mensajes
 * \return Puntero a Arraylist con la lista feed.
 *
 */

ArrayList* crearFeed(ArrayList* lista_usuarios, ArrayList* lista_mensajes)
{
    ArrayList* lista_feed = al_newArrayList();
    Post* mensaje;
    User* usuario;
    Feed* myFeed;
    int i, j, cont=0, k;

    if(lista_feed!=NULL)
    {
        for(i=0; i<al_len(lista_mensajes); i++)
        {
            mensaje = new_Post();

            if(mensaje!=NULL)
            {
                mensaje = (Post*)al_get(lista_mensajes, i);
                for(j=0; j<lista_usuarios->size; j++)
                {
                    usuario = new_User();

                    if(usuario!=NULL)
                    {
                        usuario = (User*)al_get(lista_usuarios, j);

                        if(usuario->id_usuario == mensaje->id_usuario)
                        {

                            /*if(cont %10 == 0)
                             {
                                 system("pause");
                             }
                             cont++;
                             printf("\nUSUARIO (%d): %s \t PUNTUACION: %d\n\n%s\n\nLIKES: %d", usuario->id_usuario, usuario->nick, usuario->popularidad, mensaje->mensaje, mensaje->popularidad);
                             printf("\tPUBLICACION NRO: %d\n\n---------------------------------------------------------------------\n", mensaje->id_mensaje);*/

                            myFeed = new_Feed();
                            if(myFeed!=NULL)
                            {

                                myFeed->id_mensaje = mensaje->id_mensaje;
                                strcpy(myFeed->mensaje, mensaje->mensaje);
                                myFeed->popularidad_mensaje = mensaje->popularidad;
                                myFeed->popularidad_usuario = usuario->popularidad;
                                myFeed->id_usuario = usuario->id_usuario;
                                strcpy(myFeed->nick, usuario->nick);
                                al_add(lista_feed, myFeed);


                                /* if(cont %10 == 0)
                                 {
                                     system("pause");
                                 }
                                 cont++;
                                 list_printFeed(myFeed);*/
                            }



                        }
                    }

                }

            }

        }

    }
    free(myFeed);
    free(usuario);
    free(mensaje);
    return lista_feed;
}


/** \brief Guarda en CSV la estructura Feed creada en la función crearFeed();
 * \param Lista feed.
 * \param -
 * \return void.
 *
 */
void guardarFeed(ArrayList* this)
{
    int i, retorno=-1;
    FILE* ARCHIVO;

    ARCHIVO =fopen("files\\feed.csv", "w+");
    Feed* myFeed = new_Feed();

    if(ARCHIVO == NULL)
    {
        printf("No se pudo crear el archivo\n");
    }
    else
    {

        for(i=0; i<al_len(this); i++)
        {
            myFeed = (Feed*)al_get(this,i);
            fprintf(ARCHIVO,"%d,%s,%d,%s,%d,%d \n",myFeed->id_usuario, myFeed->nick, myFeed->popularidad_usuario, myFeed->mensaje, myFeed->popularidad_mensaje, myFeed->id_mensaje);
        }
    }
    fclose(ARCHIVO);
    free(myFeed);

}

