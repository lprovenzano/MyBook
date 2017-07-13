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
User* new_User()
{
    User* this;
    this = (User*)malloc(sizeof(User));
    return this;
}

/** \brief Lee el txt con el listado de personas y carga dicha estructura.
 *
 * \param Lista donde se encuentra la estructura.
 * \param Estructura con datos a mostrar.
 * \return [-1]=> Error / NULL. || [0]=> Si se leyó en el txt satisfactoriamente.
 *
 */
int cargarUsuario(ArrayList* this)
{
    int retorno = 0, flag=0;
    FILE* f;
    User* usuario;
    char idAux[5];
    char nickAux[51];
    char popularidadAux[10];

    if((f = fopen("files\\usuarios.csv", "r"))==NULL)
    {
        retorno =-1;
    }

    else
    {
        rewind(f);
        while(!(feof(f)))
        {
            usuario=new_User();
            if(usuario!=NULL)
            {
                if(flag==0)
                {
                    fscanf(f,"%[^,],%[^,],%[^\n]\n", idAux, nickAux, popularidadAux);
                    flag=1;
                }
                else
                {
                    fscanf(f,"%[^,],%[^,],%[^\n]\n", idAux, nickAux, popularidadAux);
                    usuario->id_usuario = atoi(idAux);
                    strcpy(usuario->nick, nickAux);
                    usuario->popularidad = atoi(popularidadAux);
                    al_add(this, usuario);
                    //printf("%d\t%s\t%d\n", usuario->id_usuario, usuario->nick, usuario->popularidad);
                }
            }
        }
    }
    fclose(f);
    free(usuario);
    return retorno;
}

/** \brief Imprime en pantalla la estructura User
 *
 * \param Puntero a User.
 * \param -
 * \return void.
 *
 */
void list_printUsuario(User* usuario)
{
    printf("%d\t%s\t%d\n", usuario->id_usuario, usuario->nick, usuario->popularidad);
}
