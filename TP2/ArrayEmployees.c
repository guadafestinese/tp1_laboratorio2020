#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "validaciones.h"
#include <conio.h>

void initEmployees(eEmployee empleado[], int len)
{
        int i;
        for (i=0; i <len; i++)
        {
            empleado[i].isEmpty = 1;
        }
 }

//---------------------------------------------------


void addEmployee (eEmployee empleado[], int cantidad){

    int auxSector;
    int i;



    for(i=0;i<cantidad;i++){

        if(empleado[i].isEmpty==1){


        printf("Nombre: \n");
        myFgets(empleado[i].name, 51);
        strupr(empleado[i].name);

        printf("Apellido: \n");
        myFgets(empleado[i].lastName, 51);
        strupr(empleado[i].lastName);


        printf("Salario: \n");
        scanf("%f", &empleado[i].salary);

        while(empleado[i].salary<0||empleado[i].salary==0)
        {
            printf("ERROR. Ingrese salario mayor a 0: \n");
            scanf("%f", &empleado[i].salary);
        }


        auxSector= funcionMenu("SECTOR\n1. Atencion al cliente\n2. Ventas\n3. Compras\n4. Recursos humanos\n");
        empleado[i].sector = auxSector;

        while(empleado[i].sector<1||empleado[i].sector>4)
        {
            printf("ERROR. Ingrese un sector correcto\n");
            auxSector= funcionMenu("SECTOR\n1. Atencion al cliente\n2. Ventas\n3. Compras\n4. Recursos humanos\n");
            empleado[i].sector = auxSector;
        }


        empleado[i].isEmpty=0;
        empleado[i].id = i+1;

        system("cls");
        break;
    } //FIN FOR
 }

}

//-----------------------------------

void findEmployeeById (eEmployee empleado [], int cantidad){
    int i;
    int auxId;

    printf("Ingrese el numero de ID que desea buscar: \n");
    scanf("%d", &auxId);

    for (i=0;i<cantidad; i++)
    {
        if (empleado[i].id == auxId)
            {
                printf("Se encontro el empleado\n");
                mostrarEmpleado(empleado[i]);


            }else{
                printf("No se encontro el empleado\n");
                getch();
            }
        break;
    }
}

//--------------------------

void mostrarEmpleado(eEmployee empleado){
    printf("ID   Sector           Apellido            Nombre      Salario\n\n");
    printf("%d   %d     %20s %20s    %8.2f\n",empleado.id, empleado.sector, empleado.lastName, empleado.name, empleado.salary);
}

//---------------------------------------------

void mostrarTodos (eEmployee empleado [], int cantidad){
    int i;
    printf("ID   Sector           Apellido            Nombre      Salario\n\n");
    for (i=0; i<cantidad; i++){
        if(empleado[i].isEmpty==0){

        printf("%d   %d     %20s %20s    %8.2f\n", empleado[i].id, empleado[i].sector, empleado[i].lastName, empleado[i].name, empleado[i].salary);

    }
    }

}

//--------------------------------------------------

void modificarEmpleado (eEmployee empleado[], int cantidad){

    int i;
    int auxId;
    int auxModificar;
    int nuevoSector;

    printf("Ingrese el ID del empleado que quiera modificar: \n");
    scanf("%d", &auxId);


    for (i=0; i<cantidad; i++){
        if(empleado[i].id == auxId)
        {
            printf("\nDATOS ENCONTRADOS\n");
            mostrarEmpleado(empleado[i]);
            printf("\n---------------------------------------------\n\n");
            auxModificar=funcionMenu("1.Nuevo nombre\n2.Nuevo Apellido\n3.Nuevo Salario\n4.Nuevo sector\n5.Salir\n");

            switch(auxModificar){

            case 1:
                printf("Ingrese nuevo nombre: \n");
                myFgets(empleado[i].name,51);
                strupr(empleado[i].name);
                break;

            case 2:
                printf("Ingrese nuevo apellido: \n");
                myFgets(empleado[i].lastName,51);
                strupr(empleado[i].lastName);
                break;

            case 3:

                printf("Ingrese nuevo salario: \n");
                scanf("%f", &empleado[i].salary);

                    while(empleado[i].salary<0)
                    {
                        printf("ERROR. Ingrese nuevo salario mayor a 0: \n");
                        scanf("%f", &empleado[i].salary);
                    }
                break;

            case 4:

                    printf("Ingrese nuevo sector: \n");
                    nuevoSector=funcionMenu("SECTOR\n1. Atencion al cliente\n2. Ventas\n3. Compras\n4. Recursos humanos\n");
                    empleado[i].sector = nuevoSector;

                while(empleado[i].sector<0||empleado[i].sector>4)
                {
                    printf("ERROR. Ingrese nuevo sector: \n");
                    nuevoSector=funcionMenu("SECTOR\n1. Atencion al cliente\n2. Ventas\n3. Compras\n4. Recursos humanos\n");
                    empleado[i].sector = nuevoSector;
                }
            break;

            case 5:
                printf("No se modifico ningun dato\n");
                getch();
                break;

            }//FIN SWITCH


        }
    }

}

//----------------------------------------------------------

void removeEmployee (eEmployee empleado [], int cantidad){

    int i;
    int auxBaja;
    printf("Ingrese el ID a dar de baja \n");
    scanf("%d", &auxBaja);

    for (i=0; i<cantidad; i++){

        if(empleado[i].id == auxBaja){
            empleado[i].isEmpty = 1;
            printf("Se dio de baja el empleado\n");
        }
    }
}

//------------------------------------------

void sortEmployees (eEmployee empleado[], int cantidad){
    int i;
    int j;
    eEmployee auxiliar;

    for(i=0; i<cantidad-1; i++){

        for(j=i+1; j<cantidad; j++)
        {

            if ((empleado[i].sector==empleado[j].sector)&&(strcmp(empleado[i].lastName,empleado[j].lastName)>0))
                {
                    auxiliar = empleado[i];
                    empleado[i] = empleado[j];
                    empleado[j] = auxiliar;
                }
            if((strcmp(empleado[i].lastName, empleado[j].lastName)== 0)&& (strcmp(empleado[i].name, empleado[j].name)>0))
                {
                    auxiliar = empleado[i];
                    empleado[i] = empleado[j];
                    empleado[j] = auxiliar;
                }
            if (empleado[i].sector > empleado[j].sector)
                {
                    auxiliar = empleado[i];
                    empleado[i] = empleado[j];
                    empleado[j] = auxiliar;
                }
            }
    }
}
//------------------------------------------------------

void promedioEmpleados (eEmployee empleado[], int cantidad){

    int i;
    float acumulador=0;
    int contSalarios=0;
    float promedio;

    for (i=0; i<cantidad; i++)
    {
        if((empleado[i].salary>0)&&(empleado[i].isEmpty ==0))
            {
                acumulador = acumulador + empleado[i].salary;
                contSalarios++;
            }
    }

    promedio= (float) acumulador/contSalarios;
    printf("La cantidad de salarios es %d y suma %.2f \n", contSalarios, acumulador);
    printf("El promedio de salarios es %.2f\n", promedio);

}
