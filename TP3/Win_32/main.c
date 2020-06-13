#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int flagHayEmp = 0;


    do{
        switch(menu())
        {
            case 1:
                if( controller_loadFromText("data.csv",listaEmpleados) == 1){
                    printf("Se cargo el archivo con exito\n");
                    flagHayEmp = 1;
                    system("pause");
                }else{
                    printf("No se pudo cargar el archivo\n");
                    system("pause");
                }
                break;
            case 2:
                if( controller_loadFromBinary("data.csv",listaEmpleados) == 1){
                        printf("Se cargo el archivo con exito\n");
                        flagHayEmp = 1;
                        system("pause");
                }else{
                    printf("No se pudo cargar el archivo\n");
                    system("pause");
                }
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                system("pause");
                flagHayEmp = 1;
                break;
            case 4:
                if(flagHayEmp == 0){
                    printf("Debe ingresar empleados primero\n");
                    break;
                }else{
                    controller_ListEmployee(listaEmpleados);
                    controller_editEmployee(listaEmpleados);
                    system("pause");
                    break;
                }

            case 5:
                if(flagHayEmp == 0){
                    printf("Debe ingresar empleados primero\n");
                    break;
                }else{
                    controller_ListEmployee(listaEmpleados);
                    controller_removeEmployee(listaEmpleados);
                    system("pause");
                    break;
                }
            case 6:
                if(flagHayEmp== 0){
                    printf("Debe cargar empleados primero\n");
                }else{
                    controller_ListEmployee(listaEmpleados);
                    system("pause");
                }
                break;
            case 7:
                if(flagHayEmp== 0){
                    printf("Debe cargar empleados primero\n");
                    system("pause");
                }else{
                    controller_sortEmployee(listaEmpleados);
                    controller_ListEmployee(listaEmpleados);
                    system("pause");
                }
                break;
            case 8:
                if(controller_saveAsText("data.csv", listaEmpleados) == 1 )
                {
                        printf("Se guardo el archivo de texto con exito\n");
                        system("pause");
                }else{
                    printf("No se pudo guardar el archivo\n");
                    system("pause");
                }
                break;
            case 9:
                if(controller_saveAsBinary("data.bin", listaEmpleados) == 1)
                  {
                        printf("Se guardo el archivo binario con exito\n");
                        system("pause");
                }else{
                    printf("No se pudo guardar el archivo\n");
                    system("pause");
                }
                break;

            case 10:
                printf("El programa ha finalizado\n");
                break;

        }
    }while(option != 10);

    ll_deleteLinkedList(listaEmpleados);
    return 0;

}




