#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// strupr(cadena); CADENA A MAYUSC
// strlwr(cadena); CADENA A MINUSC

//tolower(caracter); CARACTER MINUSCULA
//toupper(caracter); CARACTER MAYUSCULA

// nombre[0] = toupper[0]; //PRIMER CARACTER A MAYUSCULA

int main()
{
    char palabra[2][20], ejemploCopy[20], nombres[3][20];
    int i;
    int resultado;

    nombres[3][20]='\0';

    for(i=0;i<2;i++)
    {
        printf("Nombre %d: ", i+1);
        fflush(stdin);
        fgets(&palabra[i], 20, stdin); //Con esta funcion strlen trae todos los caracteres incluyendo \0
        //scanf("%s", &palabra[i]); Con esta trae los caracteres reales sin \0
    }

   /* if(strcmp(&palabra[0], &palabra[1])==0)
    {
        printf("\n Son iguales");
    }
    else
    {
        printf("\n NO son iguales");
    }

    resultado = strcmp(palabra[0], palabra[1]);

    printf("%d", resultado);*/
    system("CLS");
    /*resultado = strcpy(ejemploCopy, palabra);
    printf("%s \n", ejemploCopy);
    resultado = strlen(ejemploCopy);
    printf("%d \n", resultado);*/

    nombres[0][20] = strcat(nombres, palabra[0]);
    nombres[1][20]= strcat(nombres[1], " ");
    nombres[2][20] = strcat(nombres[2], palabra[1]);

    printf("%s", nombres[3][20]);


    return 0;
}
