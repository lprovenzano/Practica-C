#define MAX_QTY 200
#define MAXUSUARIOS 100
#define MAXPRODUCTOS 1000

typedef struct{
    char title[51];
    int code;
    int stock;
    int authorId;
    int status; /**< Active (1) or Inactive (0)  */
}book;

typedef struct{
    char name[51];
    char lastName[51];
    int authorId;
    int status; /**< Active (1) or Inactive (0)  */
}author;

typedef struct{
    char nombre[51];
    int usuarioID;
    int calificacion;
    int estado; /**< Activo (1) o Inactivo (0)  */
}usuario;

typedef struct{
    char titulo[51];
    int codigo;
    int stock;
    float precio;
    int usuarioID;
    int estado; /**< ActivO (1) oO InactivO (0)  */
}producto;



void setProductoEstado(producto arrayProducto[],int tam,int valor);
int buscarProductoPorCodigo(producto arrayProducto[],int tam,int codigo);
int buscarLugarLibreEnProductos(producto arrayProducto[],int tam);
void setearProducto(producto arrayProducto[],int lugarLibre, int codigoAux,char tituloAux[], int idUsuarioAux,int stockAux, float precioAux);
void mostrarProductos(producto arrayProducto[],int tam);
void ordenarProductosPorTitulo(producto arrayProducto[],int tam);

void setUsuarioEstado(usuario arrayUsuario[],int tam,int valor);
int buscarUsuarioPorID(usuario arrayUsuario[],int tam,int idUsuario);
void setearUsuario(usuario arrayUsuario[],int lugarLibre, int idUsuarioAux,char nombreAux[], int califiAux);
void mostrarUsuarios(usuario arrayUsuario[],int tam);
int lugarLibreUsuarios(usuario arrayUsuario[],int tam);

//void showBookAuthorArray(book bookArray[],int arrayLenght,author authorArray[],int authorArrayLenght);
void mostrarUsuarioProducto(producto arrayProducto[],int tamProducto,usuario arrayUsuario[],int tamUsuario);
