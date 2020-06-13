#include "LinkedList.h"
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

int menu();
int mostrarEmpleado(Employee* emp);
int employee_ordenarPorNombre(void* emp1, void* emp2);
int employee_ordenarPorHoras(void* emp1, void* emp2);
int employee_ordenarPorSueldo(void* emp1, void* emp2);
int employee_ordenarEmpleados(LinkedList* pArrayListEmployee);

Employee* employee_new(); //OK
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo); //OK

void employee_delete(); //OK

int employee_setId(Employee* this,int id); //OK
int employee_getId(Employee* this,int* id); //OK

int employee_setNombre(Employee* this,char* nombre); //OK
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas); //OK
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas); //OK

int employee_setSueldo(Employee* this,int sueldo); //OK
int employee_getSueldo(Employee* this,int* sueldo);//OK

#endif // employee_H_INCLUDED
