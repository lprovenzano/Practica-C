#include <stdio.h>
#include <stdlib.h>

/*
    Por teclado se ingresa el valor hora de un empleado.
    Posteriormente se ingresa el nombre del empleado,
    la antigüedad y la cantidad de horas trabajadas en el mes. Se pide calcular
    el importe a cobrar teniendo en cuenta que el total resulta de multiplicar
    el valor hora por la cantidad de horas trabajadas, hay que sumarle la cantidad de años
    trabajados multiplicados por $30, y al total de todas esas operaciones restarle el 13% en
    concepto de descuentos. Imprimir el recibo correspondiente con el nombre,
    la antigüedad, el valor hora,
    el total a cobrar en bruto, el total de descuentos y el valor neto a cobrar
*/

int main()
{
    //Defino variables
    int horasTrabajadas, antiguedadEmpleado;
    float valorHora, importeACobrar, totalBruto, totalNeto, cantidadDescuentos;
    char nombre[20];

    //Asigno

    do
    {
        printf("Ingrese el valor de la hora: $");
        scanf("%f", &valorHora);

        //Como valido para que sean solo letras?
        //do
        //{
            printf("Nombre del empleado: ");
            scanf("%s", nombre);

        //}while();

        printf("Antiguedad laboral (anios): ");
        scanf("%d", &antiguedadEmpleado);

        printf("Horas trabajadas: ");
        scanf("%d", &horasTrabajadas);

    }while(valorHora<0 || horasTrabajadas<0 || antiguedadEmpleado<0);

    importeACobrar = valorHora*horasTrabajadas;
    importeACobrar += antiguedadEmpleado*30;

    totalBruto = importeACobrar;

    cantidadDescuentos = totalBruto*0.13;

    totalNeto = totalBruto-cantidadDescuentos;

    system("CLS");

    printf("\n %s \n \n", nombre);

    //Limito a dos caracteres %.2f

    printf("Total a cobrar (bruto): %.2f \n", totalBruto);
    printf("Descuentos: %.2f \n", cantidadDescuentos);
    printf("Total a cobrar (neto): %.2f \n", totalNeto);

    return 0;
}
