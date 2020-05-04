#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "validaciones.h"
#include <conio.h>

#define CANTIDAD 1000

/*
1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
*/



int main()
{
    eEmployee empleado[CANTIDAD];
    initEmployees(empleado, CANTIDAD);
    int opcion;
    int opcion4;
    int flagAlta =0;



    do{
        opcion=funcionMenu("Menu opciones\n\n1.ALTA EMPLEADO\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n5.SALIR\n");
        switch(opcion){



        case 1:
            printf("1.ALTA EMPLEADO\n");
            addEmployee(empleado,CANTIDAD);
            flagAlta = 1 ;
            break;

        case 2:
            if (flagAlta ==1) {
                printEmployees(empleado,CANTIDAD);
                modificarEmpleado(empleado,CANTIDAD);
            }else{
                printf("Debe cargar un empleado primero \n");
                system("pause");
            }

            break;
        case 3:
            if(flagAlta ==1){
                printEmployees(empleado,CANTIDAD);
                removeEmployee(empleado, CANTIDAD);
            }else{
                printf("Debe cargar un empleado primero \n");
                system("pause");
            }
            break;

        case 4:
            if(flagAlta==1){
                opcion4=funcionMenu("1) Listado de empleados ordenados alfabeticamente por apellido y sector\n2) Total y promedio de los salarios, y cuantos empleados superan el salario promedio\n");
                switch(opcion4){
                    case 1:
                        sortEmployees(empleado, CANTIDAD);
                        printEmployees(empleado, CANTIDAD);
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
                    system("pause");
                    break;

            }else{
                printf("Debe cargar un empleado primero \n");
                system("pause");
            }
        }


    system("cls");


    }while(opcion!=5);
    return 0;
}





