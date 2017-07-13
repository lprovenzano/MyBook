typedef struct{
    int id_mensaje;
    char mensaje[5000];
    int popularidad;
    int id_usuario;
} Post;

Post* new_Post();
int cargarMensajes(ArrayList* this);
void list_printMensaje(Post* post);
