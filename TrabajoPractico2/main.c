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
    eEmployee empleado[CANTIDAD]; //= { {1, "Claudia", "Aris", 3000, 2, 0}, {2, "Franco", "Festinese", 4000, 3, 0}, {3, "Guadalupe", "Festinese", 3500, 3, 0}, {4, "Camila", "Davo", 4500, 1, 0}, {5, "Norberto", "Davo", 3000, 1, 0} };
    initEmployees(empleado, CANTIDAD);
    int flagAlta =0;
    char opcion=0;



    do{

        switch(menu()){



        case 1:
            printf("1.ALTA EMPLEADO\n");
            addEmployee(empleado,CANTIDAD);
            flagAlta = 1 ;
            break;

        case 2:
            if(flagAlta == 1){
                modificarEmpleado(empleado,CANTIDAD);
            }else{
                printf("Debe cargar un empleado primero\n");
                system("pause");
            }
            break;

        case 3:
            system("cls");
            if(flagAlta==1){
                removeEmployee(empleado, CANTIDAD);
            }else{
                printf("Debe cargar un empleado primero\n");
                system("pause");
            }
            break;

        case 4:
            if (flagAlta==1){
                switch(menuInformes())
                {
                    case 1:
                        sortEmployees(empleado, CANTIDAD);
                        system("pause");
                        break;

                    case 2:
                        promedioEmpleados(empleado,CANTIDAD);
                        system("pause");
                        break;
                }

            }else{
                printf("Debe cargar un empleado primero\n");
                system("pause");
            }
            break;



                default:
                    printf("Opcion invalida\n");
                    system("pause");
                    break;




    system("cls");


    }


}while(opcion != 10);
 return 0;
}
