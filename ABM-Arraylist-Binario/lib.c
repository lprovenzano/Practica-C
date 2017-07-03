#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayList.h"
#include "lib.h"
#include "utn.h"

/** \brief Menu Principal del ABM.
 *
 * \param -
 * \param -
 * \return Caracter ingresado por teclado.
 *
 */
char menu()
{
    char c;
    printf("1. Nueva persona\n");
    printf("2. Dar de baja una persona\n");
    printf("3. Modificar persona\n");
    printf("4. Listar personas\n");
    printf("\n5. Salir\n\n");
    c=getch();
    return c;
}

/** \brief Espacio en memoria para una Persona.
 *
 * \param -
 * \param -
 * \return Puntero a Persona.
 *
 */
Persona* newPersona()
{
    Persona* this;
    this = (Persona*)malloc(sizeof(Persona));
    return this;
}

/** \brief Compara edad.
 *
 * \param Puntero "A" a estructura "Persona"
 * \param Puntero "B" a estructura "Persona"
 * \return [-1]=> A<B  || [1]=> A>B || [0] No comparó.
 *
 */
int comparaEdad(Persona* personaA, Persona* personaB)
{
    if((personaA->edad) > (personaB->edad))
    {
        return 1;
    }
    if((personaA->edad) < (personaB->edad))
    {
        return -1;
    }
    return 0;
}

/** \brief Compara apellidos.
 *
 * \param Puntero "A" a estructura "Persona"
 * \param Puntero "B" a estructura "Persona"
 * \return [-1]=> A<B  || [1]=> A>B || [0] No comparó.
 *
 */
int comparaApellido(Persona* personaA, Persona* personaB)
{
    if((strcmp(personaA->apellido, personaB->apellido))==1)
    {
        return 1;
    }
    if((strcmp(personaA->apellido, personaB->apellido))==-1)
    {
        return -1;
    }
    return 0;
}

/** \brief Agrega una nueva persona a la estructura.
 *
 * \param Puntero a Persona.
 * \return [0]=> Si se agregó satisfactoriamente. // [-1]Si se pulsa "salir" (cancelar operacion)
 *
 */
int unaPersona(Persona* p)
{
    int retorno = 0;

    fflush(stdin);
    getValidString("Nombre: ", "Debe ser un nombre valido", p->nombre);
    fflush(stdin);
    getValidString("Apellido: ", "Debe ser un nombre valido", p->apellido);
    if((strncmp(p->nombre,"salir",5)==0) || (strncmp(p->apellido,"salir",5)==0))
    {
        retorno = -1;
    }
    p->edad = getValidInt("Edad: ", "Solo numerico", 0, 100);

    return retorno;
}

/** \brief Forma del listado orientativo.
 *
 * \param -
 * \param -
 * \return void.
 *
 */
void baseListado()
{
    printf("*************************************************\n");
    printf("************** L I S T A D O ********************\n");
    printf("*************************************************\n");
    printf("*                                               *\n");
    printf("* ID ----- NOMBRE -------- APELLIDO ------ EDAD *\n\n");
}

/** \brief Muestra en pantalla el contenido de la estructura dentro de la lista.
 *
 * \param Lista donde se encuentra la estructura.
 * \param Estructura con datos a mostrar.
 * \return void.
 *
 */
void printPersona(ArrayList* this, Persona* p)
{
    printf("   %-8d%-15s%-18s%-d\n", al_indexOf(this, p),p->nombre,p->apellido, p->edad);

}

//ARCHIVOS

/** \brief Escribe en un archivo de texto los datos de la estructura Persona.
 *
 * \param Lista donde se encuentra la estructura.
 * \param Estructura con datos a mostrar.
 * \return [-1]=> Error / NULL. || [0]=> Si se escribio en el txt satisfactoriamente.
 *
 */
int crearBinario(ArrayList* this, Persona* p)
{
    FILE *f;
    int i;

    f = fopen("bin.dat","wb+");
    if(f == NULL)
    {
        printf("\nError al abrir el archivo");
    }
    else
    {
        for(i=0; i<this->size; i++)
        {
            p = al_get(this,i);
            fwrite(p,sizeof(Persona),1,f);
        }
    }
    fclose(f);
}

/** \brief Lee el txt con el listado de personas y carga dicha estructura.
 *
 * \param Lista donde se encuentra la estructura.
 * \param Estructura con datos a mostrar.
 * \return [-1]=> Error / NULL. || [0]=> Si se leyó en el txt satisfactoriamente.
 *
 */
int cargarBinario(ArrayList* this, Persona* p)
{
    int retorno = 0, cant;
    FILE* f;
    f=fopen("bin.dat","rb");

    if(f==NULL)
    {
        if((f=fopen("bin.dat","wb"))==NULL)
        {
            printf("\nEl archivo no puede ser abierto");
            retorno = -1;
        }
    }
    else
    {
        while(!(feof(f)))
        {
            p=newPersona();
            fflush(stdin);
            cant = fread(p, sizeof(Persona), 1,f);
            if(cant!=1)
            {
                if(feof(f))
                {
                    break;
                }
                else
                {
                    printf("No se leyo el ultimo registro.");
                    break;
                }
            }
            fflush(stdin);
            al_add(this, p);
        }
    }
    fclose(f);
    return retorno;
}

void ordenarPorEdad(ArrayList* this)
{
    al_sort(this, comparaEdad,0);
}

void ordenarPorApellido(ArrayList* this)
{
    al_sort(this, comparaApellido,1);
}





