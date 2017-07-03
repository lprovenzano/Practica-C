typedef struct
{
    int id_usuario;
    char nick[31];
    int popularidad;
} User;

User* new_User();
int cargarUsuario(ArrayList* this);
