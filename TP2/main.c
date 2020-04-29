#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "validaciones.h"
#include "utn.h"
#include <conio.h>

#define CANTIDAD 1000

/*
1. ALTAS: Se debe permitir ingresar un empleado calculando autom�ticamente el n�mero
de Id. El resto de los campos se le pedir� al usuario.
2. MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector
3. BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.
4. INFORMAR:
1. Listado de los empleados ordenados alfab�ticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio.
*/



int main()
{
    eEmployee empleado[CANTIDAD];
    initEmployees(empleado, CANTIDAD);
    int opcion;
    int opcion4;


    do{
        opcion=funcionMenu("Menu opciones\n\n1.ALTA EMPLEADO\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n");
        switch(opcion){



        case 1:
            printf("1.ALTA EMPLEADO\n");
            addEmployee(empleado,CANTIDAD);
            break;

        case 2:
            mostrarTodos(empleado,CANTIDAD);
            modificarEmpleado(empleado,CANTIDAD);

            break;
        case 3:
            mostrarTodos(empleado,CANTIDAD);
            removeEmployee(empleado, CANTIDAD);
            break;

        case 4:
            opcion4=funcionMenu("1) Listado de empleados ordenados alfabeticamente por apellido y sector\n2) Total y promedio de los salarios, y cuantos empleados superan el salario promedio\n");
            switch(opcion4){
            case 1:
                sortEmployees(empleado, CANTIDAD);
                mostrarTodos(empleado, CANTIDAD);
                system("pause");
                break;

            case 2:
                promedioEmpleados(empleado,CANTIDAD);
                system("pause");
                break;

            }

            break;
        case 5:
            printf("Ha salido\n");
            break;
        default:
            printf("Opcion invalida\n");
            break;

            }


    system("cls");


    }while(opcion!=5);
    return 0;
}




