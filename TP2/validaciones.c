#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "validaciones.h"
#include <conio.h>
void myFgets (char nombre [], int cant)
{
    fflush (stdin);
    fgets(nombre, cant, stdin);
    nombre[strcspn(nombre, "\r\n")] = 0;
}

int funcionMenu(char opcion[])
    {

        int auxOpcion;
        printf("%s", opcion);
        fflush(stdin);
        scanf ("%d", &auxOpcion);
        return auxOpcion;


    }
