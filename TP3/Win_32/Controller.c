#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "utn.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* f;

    if( path!= NULL && pArrayListEmployee != NULL)
    {
        f= fopen(path, "r");
        if(f!= NULL)
        {
            parser_EmployeeFromText(f, pArrayListEmployee);
            fclose(f);
            todoOk = 1;
        }else{
            printf("No se pudo abrir el archivo");
    }


    }
    return todoOk;
}
//-------------------------------------------------------------------------------------------
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk =0;
    FILE* f;

    if( path!= NULL && pArrayListEmployee != NULL)
    {
        f= fopen(path, "rb");
        if(f!= NULL)
        {
            parser_EmployeeFromBinary(f, pArrayListEmployee);
            fclose(f);
            todoOk = 1;
        }else{
            printf("No se pudo abrir el archivo");
    }


    }
    return todoOk;
}
//-------------------------------------------------------------------------------------------
/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* nuevoEmp;
    nuevoEmp = employee_new();

    int todoOk = 0;
    int auxId;
    int auxHoras;
    int auxSueldo;
    char auxNombre[30];
    char auxSueldoGet[30];
    char auxHorasGet[30];

    system("cls");
    printf("****** ALTA EMPLEADO ****\n");

    if(pArrayListEmployee != NULL)
    {
        auxId = controller_proximoID(pArrayListEmployee);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(auxNombre);

        while(esSoloLetras(auxNombre)==0 || strlen(auxNombre)< 3 || strlen(auxNombre)>21)
        {
            printf("ERROR, ingrese un nombre correcto entre 3 y 21 letras: ");
            fflush(stdin);
            gets(auxNombre);
        }
        strupr(auxNombre);



        printf("Ingrese sueldo entre 10.000 y 80.000: ");
        fflush(stdin);
        gets(auxSueldoGet);
        while(esNumerico(auxSueldoGet)==0 || atoi(auxSueldoGet)<10000 || atoi(auxSueldoGet)>60000)
        {
            printf("ERROR, ingrese un sueldo correcto entre 10.000 y 80.000: ");
            fflush(stdin);
            gets(auxSueldoGet);
        }
        auxSueldo = atoi(auxSueldoGet);



        printf("Ingrese la cantidad de horas trabajadas: ");
        fflush(stdin);
        gets(auxHorasGet);
        while(esNumerico(auxHorasGet)==0)
        {
            printf("ERROR. Ingrese la cantidad de horas trabajadas mayor a 0: ");
            fflush(stdin);
            gets(auxHorasGet);
        }
        auxHoras = atoi(auxHorasGet);

        if(nuevoEmp != NULL)
        {
            employee_setId(nuevoEmp, auxId);
            employee_setNombre(nuevoEmp, auxNombre);
            employee_setSueldo(nuevoEmp, auxSueldo);
            employee_setHorasTrabajadas(nuevoEmp, auxHoras);
            ll_add(pArrayListEmployee, nuevoEmp);
            printf("\nSe dio de alta el empleado con exito\n");
            todoOk = 1;
        }
    }
    return todoOk;
}
//-------------------------------------------------------------------------------------------
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* emp;

    int i;
    int todoOk = 0;
    int auxId;
    int idEmp;
    int auxSueldo;
    int auxHoras;

    char id[30];
    char nombre[30];
    char sueldo[30];
    char horas[30];
    int tam = ll_len(pArrayListEmployee);


    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese el ID del empleado: ");
        fflush(stdin);
        gets(id);

        while(esNumerico(id)==0)
        {
            printf("ERROR. Ingrese un ID correcto: ");
            fflush(stdin);
            gets(id);
        }
        auxId = atoi(id);

        for(i = 0; i< tam; i++)
        {
            emp = ll_get(pArrayListEmployee,i);
            employee_getId(emp,&idEmp);



            if(idEmp == auxId)
            {
                system("cls");


                switch(menuModificar())
                {
                case 1:
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(nombre);

                    while(esSoloLetras(nombre)==0 || strlen(nombre)<3 || strlen(nombre)>21)
                    {
                        printf("ERROR. Ingrese nombre entre 3 y 21 letras: ");
                        fflush(stdin);
                        gets(nombre);
                    }
                    strupr(nombre);
                    employee_setNombre(emp, nombre);
                    printf("Se modifico el nombre con exito\n");
                    todoOk = 0;
                    break;

                case 2:
                    printf("Ingrese un nuevo sueldo entre 10.000 y 60.000: ");
                    fflush(stdin);
                    gets(sueldo);

                    while(esNumerico(sueldo)==0 || atoi(sueldo)<10000 || atoi(sueldo)>60000)
                    {
                        printf("ERROR. Ingrese un sueldo correcto entre 10.000 y 60.000: ");
                        fflush(stdin);
                        gets(sueldo);
                    }

                    auxSueldo = atoi(sueldo);
                    employee_setSueldo(emp, auxSueldo);
                    printf("Se modifico el sueldo con exito\n");
                    todoOk = 0;
                    break;

                case 3:
                    printf("Ingrese la cantidad de horas: ");
                    fflush(stdin);
                    gets(horas);
                    while(esNumerico(horas)==0)
                    {
                        printf("ERROR. Ingrese una cantidad correcta mayor a 0: ");
                        fflush(stdin);
                        gets(horas);
                    }
                    auxHoras = atoi(horas);
                    employee_setHorasTrabajadas(emp, auxHoras);
                    printf("Se modificaron las horas con exito\n");
                    todoOk = 0;
                    break;

                case 4:
                    printf("\nSe cancelo la operacion\n\n");
                    break;

                default:
                    printf("ERROR. Opcion invalida.\n");
                    break;
                }
            }else{
                printf("No se encontro un empleado con el ID ingresado\n");
                system("pause");
                break;
            }
        }
    }
    return todoOk;
}

//-------------------------------------------------------------------------------------------

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
   Employee* emp;

    int todoOk = -1;
    int tam= ll_len(pArrayListEmployee);
    char id[100];
    int auxId;
    int idEmp;
    int opcion;


    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese el ID del empleado: ");
        fflush(stdin);
        gets(id);

        while(esNumerico(id)==0)
        {
            printf("ERROR. Ingrese ID correcto: ");
            fflush(stdin);
            gets(id);
        }
        auxId=atoi(id);

        for(int i=0; i< tam; i++)
        {
            emp = ll_get(pArrayListEmployee,i);
            employee_getId(emp, &idEmp);

            if(idEmp == auxId)
            {
                printf("\nQuiere dar de baja?\n");
                printf("1)Si\n");
                printf("2)No\n");
                printf("Ingrese opcion: ");
                scanf("%d",&opcion);

                switch(opcion)
                {
                case 1:
                    employee_delete(emp);
                    ll_remove(pArrayListEmployee,i);
                    printf("Se dio de baja el empleado\n");
                    todoOk = 0;
                    break;

                case 2:
                    todoOk = -2;
                    printf("No se dio de baja el empleado\n");
                    break;

                default:
                    printf("Opcion invalida\n");
                    todoOk = -2;
                    break;
                }
            }
        }
    }
    return todoOk;
}

//-------------------------------------------------------------------------------------------

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int flag = 0;
    int tam = ll_len(pArrayListEmployee);
    Employee* auxEmpleado;

    printf("***** LISTA EMPLEADOS ***** \n");
    if(pArrayListEmployee != NULL)
    {
        todoOk =1;
        printf("ID              NOMBRE       HORAS TRABAJADAS       SUELDO\n");
        for (int i=0; i< tam; i++)
        {
            auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
            if(auxEmpleado != NULL)
            {
                mostrarEmpleado(auxEmpleado);
                flag =1;
            }
        }
        if(flag == 0)
        {
            printf("No hay empleados que mostrar\n");

        }
    }
    return todoOk;
}

//-------------------------------------------------------------------------------------------
/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;

    if(pArrayListEmployee != NULL)
    {
        employee_ordenarEmpleados(pArrayListEmployee);
        todoOk = 1;
    }
    return todoOk;
}

//-------------------------------------------------------------------------------------------

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    Employee* emp;

    int todoOk = 0;
    int tam= ll_len(pArrayListEmployee);
    int* auxId;
    char* auxNombre;
    int* auxSueldo;
    int* auxHoras;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        auxId = malloc(sizeof(int));
        auxNombre = malloc(sizeof(char)*100);
        auxSueldo = malloc(sizeof(int));
        auxHoras = malloc(sizeof(int));

        f = fopen(path, "w");
        fprintf(f,"ID , NOMBRE, HORAS TRABAJADAS, SUELDO\n");

        for(int i=0; i< tam; i++)
        {
            emp = ll_get(pArrayListEmployee,i);
            employee_getId(emp,auxId);
            employee_getSueldo(emp,auxSueldo);
            employee_getNombre(emp, auxNombre);
            employee_getHorasTrabajadas(emp,auxHoras);
            fprintf(f,"%d, %s , %d, %d\n",*auxId, auxNombre,*auxSueldo,*auxHoras);
            todoOk = 1;
        }

        free(auxNombre);
        free(auxId);
        free(auxSueldo);
        free(auxHoras);

        fclose(f);
    }
    return todoOk;
}
//-------------------------------------------------------------------------------------------
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    Employee* emp;

    int todoOk = 0;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        f = fopen(path,"wb");

        for(int i=0; i< ll_len(pArrayListEmployee); i++)
        {
            emp = (Employee*)ll_get(pArrayListEmployee,i);
            fwrite(emp, sizeof(Employee),1,f);
            todoOk = 1;
        }
        fclose(f);
    }
    return todoOk;
}
//-------------------------------------------------------------------------------------------
/** \brief Incrementa el ID
 *
 * \param LinkedList* pArrayListEmployee, puntero a la lista de empleados
 * \return 1 si esta todo bien, 0 si esta mal
 *
 */

int controller_proximoID(LinkedList* pArrayListEmployee)
{
    Employee* auxEmp;

    int aux;
    int id = 0;
    int tam;
    int idAnt;

    if(pArrayListEmployee != NULL)
    {
        tam = ll_len(pArrayListEmployee);
        if(tam > 0)
        {
            for(int i = 0; i<tam; i++)
            {
                auxEmp = (Employee*)ll_get(pArrayListEmployee,i);
                employee_getId(auxEmp,&aux);
                if(aux > id)
                {
                    idAnt = id;
                    id = aux;
                    if(idAnt + 1 != id)
                    {
                        id = idAnt;
                        break;
                    }
                }
            }
            id++;
        }
        else
        {
            id = 1;
        }
    }
    return id;
}

//-------------------------------------------------------------------------------------------

 /** \brief Muestra menu de opciones para modificar empleado
  *
  * \param -
  * \param -
  * \return La opcion elegida
  *
  */

 int menuModificar(){
                int opcion;

                system("cls");
                printf("\n\n******OPCIONES A MODIFICAR*****\n");
                printf("1) Nombre\n");
                printf("2) Sueldo\n");
                printf("3) Horas trabajadas\n");
                printf("4) Cancelar\n");
                printf("\n\nIngrese opcion: ");

                scanf("%d" , &opcion);
                return opcion;
            }
