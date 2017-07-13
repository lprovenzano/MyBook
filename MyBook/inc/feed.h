typedef struct{
    int id_mensaje;
    char mensaje[5000];
    int popularidad_mensaje;
    int popularidad_usuario;
    int id_usuario;
    char nick[51];
} Feed;

Feed* new_Feed();
ArrayList* crearFeed(ArrayList* lista_usuarios, ArrayList* lista_mensajes);
void list_printFeed(Feed* feed);
int compare(Feed* elemento1, Feed* elemento2);
int ordenar(ArrayList* this);
void guardarFeed(ArrayList* this);
