#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAXPROGRAMADOR 50
#define MAXPROYECTO 1000


//Estructuras
typedef struct
{
    int id, idCategoria, estado; /**Estado (0) => Inactivo // Estado (1) => Activo**/
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
    int cantProgramadores;
} Proyecto;

typedef struct
{
    int idProgramador, idProyecto;
    float cantHoras;
} ProgramadorProyecto;



void menu();
void inicializoEnCero(Programador arrayProgramador[], int tam, int valor);
void cargarCategorias(Categoria niveles[]);
//Programador
void cargarProgramador(Programador arrayProgramador[]);
void altaProgramador(Programador arrayProgramador[], int tam);
void listarProgramador(Programador arrayProgramador[], Categoria niveles[],int tam);
int buscarProgramadorId(Programador arrayProgramador[], int busqueda, int tam);
void modificarProgramador(Programador arrayProgramador[], Categoria niveles[],int tam);
void borrarProgramador(Programador arrayProgramador[], Categoria niveles[], int tam);
void programadorEnProyecto(Programador arrayProgramador[], int tamP, Proyecto arrayProyecto[], int tamY);


#endif // FUNCIONES_H


