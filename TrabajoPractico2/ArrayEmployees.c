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


        auxSector= menuSector();
        empleado[i].sector = auxSector;

        while(empleado[i].sector<1||empleado[i].sector>4)
        {
            printf("ERROR. Ingrese un sector correcto\n");
            auxSector= menuSector();
            empleado[i].sector = auxSector;
        }


            empleado[i].isEmpty = 0;
            empleado[i].id = i+1;


            break;

        system("cls");
        break;
    } //FIN FOR
 }

}

//-----------------------------------
int findEmployeeById(int id, eEmployee empleado[], int tam){

int indice= -1;

for(int i=0; i<tam; i++){
if(empleado[i].id == id){
indice= i;
break;
}
}
return indice;
}

//--------------------------

void mostrarEmpleado(eEmployee empleado){

    printf("ID   Sector           Apellido            Nombre      Salario\n\n");
    printf("%d   %d     %20s %20s    %10.2f\n",empleado.id, empleado.sector, empleado.lastName, empleado.name, empleado.salary);
}

//---------------------------------------------

void printEmployees (eEmployee empleado [], int cantidad){

    int i;
    printf("ID   Sector           Apellido            Nombre      Salario\n\n");
    for (i=0; i<cantidad; i++){
        if(empleado[i].isEmpty==0){

        printf("%d   %d     %20s %20s    %10.2f\n", empleado[i].id, empleado[i].sector, empleado[i].lastName, empleado[i].name, empleado[i].salary);

    }
    }

}

//--------------------------------------------------

void modificarEmpleado (eEmployee empleado[], int cantidad){


    int auxId;

    printEmployees(empleado, cantidad);
    printf("Ingrese el ID del empleado que quiera modificar: \n");
    scanf("%d", &auxId);


    for (int i=0; i<cantidad; i++){
        if(empleado[i].id == auxId)
        {
            printf("\nDATOS ENCONTRADOS\n");
            mostrarEmpleado(empleado[i]);
            break;
        }else{
            printf("Datos incorrectos, no se encontro el ID\n");
            break;
        }
    }

            mostrarEmpleado(empleado[auxId]);
            switch(menuModificar()){

            case 1:
                printf("Ingrese nuevo nombre: \n");
                myFgets(empleado[auxId].name,51);
                strupr(empleado[auxId].name);
                break;

            case 2:
                printf("Ingrese nuevo apellido: \n");
                myFgets(empleado[auxId].lastName,51);
                strupr(empleado[auxId].lastName);
                break;

            case 3:

                printf("Ingrese nuevo salario: \n");
                scanf("%f", &empleado[auxId].salary);

                    while(empleado[auxId].salary<0)
                    {
                        printf("ERROR. Ingrese nuevo salario mayor a 0: \n");
                        scanf("%f", &empleado[auxId].salary);
                    }
                break;

            case 4:

                    printf("Ingrese nuevo sector: \n");
                    empleado[auxId].sector = menuSector();

                while(empleado[auxId].sector<0||empleado[auxId].sector>4)
                {
                    printf("ERROR. Ingrese nuevo sector: \n");
                    empleado[auxId].sector = menuSector();
                }
            break;

            case 5:
                printf("No se modifico ningun dato\n");
                getch();
                break;

            }//FIN SWITCH



}

//----------------------------------------------------------

void removeEmployee (eEmployee empleado [], int cantidad){
    int id;
    int indice;
    char confirma;
    system("cls");
    printf("*** Baja notebook ***\n");
    printEmployees(empleado, cantidad);
    printf("Ingrese id: \n");
    scanf("%d", &id);

    indice = findEmployeeById(id, empleado, cantidad);

    if(indice == -1){
        printf("No hay registro de un empleado con el id %d\n", id);
    }else{
        mostrarEmpleado(empleado[indice]);
        printf("Confima baja? \n");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's'){
            empleado[indice].isEmpty = 1;
            printf("Se ha realizado la baja con exito\n");
        }else{
            printf("Se ha cancelado la operacion\n");
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
    printEmployees(empleado, cantidad);
}
//------------------------------------------------------

void promedioEmpleados (eEmployee empleado[], int cantidad){

    int i;
    float acumulador=0;
    int contSalarios=0;
    float promedio;
    int contadorMayores=0;

    for (i=0; i<cantidad; i++)
    {
        if((empleado[i].salary>0)&&(empleado[i].isEmpty ==0))
            {
                acumulador = acumulador + empleado[i].salary;
                contSalarios++;
            }
    }

    promedio= (float) acumulador/contSalarios;

    for(int e=0; e<cantidad; e++){
        if(empleado[e].salary > promedio){
        contadorMayores++;
        }
    }


    printf("La cantidad de salarios es %d y suma %.2f \n", contSalarios, acumulador);
    printf("El promedio de salarios es %.2f\n", promedio);
    printf("La cantidad de salarios que superan el promedio es: %d\n", contadorMayores );

}
