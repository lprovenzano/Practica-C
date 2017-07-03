typedef struct{
    int id_mensaje;
    char mensaje[300];
    int popularidad;
    int id_usuario;
} Post;

Post* new_Post();
int cargarMensajes(ArrayList* this);
