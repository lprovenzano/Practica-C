#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAXPROGRAMADOR 50
#define MAXPROYECTO 1000


//Estructuras
typedef struct
{
    int id, idCategoria, estado; /*Estado (0) => Inactivo // Estado (1) => Activo**/
    char nombre[31];
    char apellido[31];
} Programador;

typedef struct
{
    int idCategoria;
    char descripcion[21];
    float pagoPorHora;
} Categoria;

typedef struct
{
    int id;
    char titulo[51];
} Proyecto;

void menu();
void inicializoEnCero(Programador arrayProgramador[], int tam, int valor);
void cargarCategorias(Categoria niveles[]);
//Programador
void hardCodeoProgramador(Programador arrayProgramador[]);
void altaProgramador(Programador arrayProgramador[], int tam);
void listarProgramador(Programador arrayProgramador[], int tam);
int buscarProgramadorId(Programador arrayProgramador[], int busqueda, int tam);
void modificarProgramador(Programador arrayProgramador[], int tam);
void borrarProgramador(Programador arrayProgramador[], int tam);



#endif // FUNCIONES_H


