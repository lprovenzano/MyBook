typedef struct
{
    int id_usuario;
    char nick[51];
    int popularidad;
} User;

User* new_User();
int cargarUsuario(ArrayList* this);
void list_printUsuario(User* usuario);
