#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char buffer[4][100];
    int todoOk = 0;
    Employee* auxEmpleado;
    int cant;

   if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while (!feof(pFile))
        {
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n],", buffer[0], buffer[1], buffer[2], buffer[3]);

            if(cant == 4)
            {
                auxEmpleado = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
                ll_add(pArrayListEmployee, auxEmpleado);
                todoOk = 1;
            }else{
                break;
            }
        }


    }
    return todoOk;
}
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee){

    int todoOk = 0;
    Employee* auxEmpleado;
    int cant;
    while(!feof(pFile))
    {
        auxEmpleado=employee_new();
        cant=fread(auxEmpleado,sizeof(Employee),1,pFile);
        if(cant==1)
        {
            ll_add(pArrayListEmployee,auxEmpleado);
            todoOk = 1;
        }
    }
    return todoOk;
}
