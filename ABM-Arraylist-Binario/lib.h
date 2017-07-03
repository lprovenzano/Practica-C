#include "ArrayList.h"

typedef struct{
    char nombre[21];
    char apellido[51];
    int edad;
}Persona;

char menu();
Persona* newPersona();
int unaPersona(Persona* p);
void printPersona(ArrayList* this, Persona* p);
void baseListado();
int comparaEdad(Persona* personaA, Persona* personaB);
int comparaApellido(Persona* personaA, Persona* personaB);
void ordenarEdadApellido(ArrayList* this);
void ordenarPorApellido(ArrayList* this);

//Archivos
int crearBinario(ArrayList* this, Persona* p);
int cargarBinario(ArrayList* this, Persona* p);
