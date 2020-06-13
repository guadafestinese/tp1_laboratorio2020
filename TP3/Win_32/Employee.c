#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"


/** \brief Muestra un empleado
 *
 * \param Employee* emp, puntero a la estructura empleado
 * \param -
 * \return 1 si hay un error, 0 si esta todo bien
 *
 */

int mostrarEmpleado(Employee* emp){
    int error=1;

    if(emp != NULL)
    {
        printf("%4d %20s           %4d          %6d\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
        error = 0;
    }
    return error;
}
//----------------------------------------------------------------------------------------------------------

/** \brief Muestra menu de opciones
 *
 * \param -
 * \param -
 * \return la opcion elegida
 *
 */

int menu(){
    int opcion;
    system("cls");

     printf("MENU:\n");
     printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
     printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario). \n");
     printf("3. Alta de empleado \n");
     printf("4. Modificar datos de empleado \n");
     printf("5. Baja de empleado \n");
     printf("6. Listar empleados \n");
     printf("7. Ordenar empleados \n");
     printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto). \n");
     printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario). \n");
     printf("10. Salir \n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

  return opcion;
  }


//----------------------------------------------------------------------------------------------------------
/** \brief Crea un empleado en memoria dinamica
 *
 * \param -
 * \param -
 * \return -
 *
 */

Employee* employee_new(){
    Employee* nuevoEmp;
    nuevoEmp = (Employee*) malloc (sizeof(Employee));
    if(nuevoEmp != NULL)
    {
        nuevoEmp->id = 0;
        strcpy(nuevoEmp->nombre, "");
        nuevoEmp->horasTrabajadas=0;
        nuevoEmp->sueldo = 0;
    }

    return nuevoEmp;
}
//-------------------------------------------------------------------------------------------
/** \brief Crea un empleado en memoria dinamica pasandole cadenas de caracteres y chequea que este todo bien
 *
 * \param char* idStr , puntero char a ID
 * \param char* nombreStr, puntero char a nombre
 * \param char* horasTrabajadasStr, puntero char a horas trabajadas
 * \param char* sueldo, puntero char a sueldo
 * \return -
 *
 */

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo){

    Employee* nuevoEmp;

    nuevoEmp = employee_new();

    int auxId, auxHorasTrab, auxSueldo;

    auxId = atoi(idStr);
    auxHorasTrab= atoi(horasTrabajadasStr);
    auxSueldo = atoi(sueldo);

    if(nuevoEmp != NULL && idStr != NULL && horasTrabajadasStr!= NULL && nombreStr != NULL && sueldo !=NULL)
    {

        if( employee_setId(nuevoEmp, auxId)
        || employee_setNombre(nuevoEmp, nombreStr)
        || employee_setHorasTrabajadas(nuevoEmp, auxHorasTrab)
        || employee_setSueldo(nuevoEmp, auxSueldo)
        ){
            free(nuevoEmp);
            nuevoEmp = NULL;
        }
    }

    return nuevoEmp;
}

//-------------------------SETTERS----------------------------------------------

/** \brief Chequea que el ID sea correcto
 *
 * \param Employee* this, puntero a estructura
 * \param int id, id que se le pasa
 * \return 1 si estaa todo mal, 0 si esta todo bien
 *
 */

int employee_setId(Employee* this,int id){
    int error = 1;

    if(this != NULL && id>0)
    {
        this->id = id;
        error = 0;
    }

    return error;
}

/** \brief Chequea que el nombre sea correcto
 *
 * \param Employee* this, puntero a estructura empleado
 * \param char* nombre
 * \return 1 si esta todo mal, 0 si esta todo bien
 *
 */

int employee_setNombre(Employee* this, char* nombre){
    int error = 1;

    if(this != NULL && strlen(nombre)>= 3 && strlen(nombre)<20)
    {
        strcpy(this->nombre, nombre);
        error = 0;
    }

    return error;
}

/** \brief Chequea que las horas sean correctas
 *
 * \param Employee* this, puntero a estructura empleado
 * \param int horasTrabajadas
 * \return 1 si esta todo mal, 0 si esta todo bien
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    int error = 1;

    if(this != NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas = horasTrabajadas;
        error = 0;
    }

    return error;
}

/** \brief Chequea que el sueldo sea correcto
 *
 * \param Employee* this, puntero a estructura empleado
 * \param int sueldo
 * \return 1 si esta todo mal, 0 si esta todo bien
 *
 */
int employee_setSueldo(Employee* this,int sueldo){
    int error = 1;

    if(this != NULL && sueldo>=0)
    {
        this->sueldo = sueldo;
        error = 0;
    }

    return error;
}

//-------------------------GETTERS----------------------------------------------------------------------------
int employee_getId(Employee* this,int* id){
    int error = 1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        error = 0;
    }
    return error;
}
int employee_getNombre(Employee* this,char* nombre){
    int error = 1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        error = 0;
    }

    return error;
}


int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas){
    int error = 1;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        error = 0;
    }
    return error;
}

int employee_getSueldo(Employee* this, int* sueldo){
    int error = 1;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        error = 0;
    }
    return error;
}



void employee_delete(Employee* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

//-------------------------------------------------------------------------------------------
int employee_ordenarEmpleados(LinkedList* pArrayListEmployee)
{
    int opcion;
    int todoOk = 0;

    if(pArrayListEmployee != NULL)
    {
        printf("\n\n***** OPCIONES ******\n");
        printf("1) Ordernar empleados por nombre \n");
        printf("2) Ordenar por sueldo (menor a mayor)\n");
        printf("3) Ordenar empleados por horas trabajadas (menor a mayor)\n");
        printf("4) Cancelar\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            printf("\n\n*** LISTA DE EMPLEADOS ORDENADOS POR NOMBRE *****\n");
            ll_sort(pArrayListEmployee, employee_ordenarPorNombre, 1);
            break;

        case 2:
            printf("\n\n*** LISTA DE EMPLEADOS ORDENADOS POR SUELDO *****\n");
            ll_sort(pArrayListEmployee, employee_ordenarPorSueldo, 1);
            break;

        case 3:
            printf("\n\n*** LISTA DE EMPLEADOS ORDENADOS POR HORAS TRABAJADAS *****\n");
            ll_sort(pArrayListEmployee, employee_ordenarPorHoras, 1);
            break;

        case 4:
            opcion=4;
            printf("Se cancelo la operacion\n");
            break;

        default:
            printf("ERROR. Opcion invalida\n");
            break;
        }

        todoOk= 0;
    }
    return todoOk;
}

//-------------------------------------------------------------------------------------------
int employee_ordenarPorSueldo(void* emp1, void* emp2)
{
    int sueldoEmp1;
    int sueldoEmp2;
    int todoOk = 0;

    employee_getSueldo(emp1, &sueldoEmp1);
    employee_getSueldo(emp2, &sueldoEmp2);

    if(sueldoEmp1 > sueldoEmp2)
    {
        todoOk = 1;
    }
    else if(sueldoEmp1 < sueldoEmp2)
    {
        todoOk = -1;
    }

    return todoOk;
}

//-------------------------------------------------------------------------------------------
int employee_ordenarPorNombre(void* emp1, void* emp2)
{
    char nombreEmp1[20];
    char nombreEmp2[20];
    int todoOk = 0;

    employee_getNombre(emp1, nombreEmp1);
    employee_getNombre(emp2, nombreEmp2);

    if(strcmp(nombreEmp1, nombreEmp2) > 0)
    {
        todoOk = 1;
    }
    else if(strcmp(nombreEmp1, nombreEmp2) < 0)
    {
        todoOk = -1;
    }

    return todoOk;
}

//-------------------------------------------------------------------------------------------

int employee_ordenarPorHoras(void* emp1, void* emp2)
{
    int horasEmp1;
    int horasEmp2;
    int todoOk = 0;

    employee_getHorasTrabajadas(emp1, &horasEmp1);
    employee_getHorasTrabajadas(emp2, &horasEmp2);

    if(horasEmp1 > horasEmp2)
    {
        todoOk = 1;
    }
    else if(horasEmp1 < horasEmp2)
    {
        todoOk = -1;
    }

    return todoOk;
}
