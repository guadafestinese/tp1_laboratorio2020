/*#include <stdlib.h>
#include <stdio.h>

int opcionMenu (int opcion)
{
    printf ("ELIJA UNA OPCION DEL 1 al 5\n\n\n");
    printf("1. Ingresar 1er operando (A=x)\n\n");
    printf("2. Ingresar 2do operando (B=y)\n\n");
    printf("3. Calcular todas las operaciones\n\n");
    printf("a) Calcular la suma (A+B)\nb) Calcular la resta (A-B)\nc) Calcular la division (A/B)\nd) Calcular la multiplicacion (A*B)\ne) Calcular el factorial (A!)\n\n");
    printf("4. Informar resultados\n\n");
    printf("a) El resultado de A+B es: r\nb) El resultado de A-B es: r\nc) El resultado de A/B es: r o No es posible dividir por cero\nd) El resultado de A*B es: r\ne) El factorial de A es: r1 y El factorial de B es: r2\n\n");
    printf("5. Salir\n\n");


    return opcion;
}
*/
//--------------------------------------------------------------------------------------------

//CALCULAR OPERACIONES

int suma (int x, int y)
{
    return x+y;
}

int resta (int x, int y)
{
    return x-y;
}

int multiplicacion (int x, int y)
{
            return x*y;
}

float division (int x, int y)
{
    return (float) x/y;
}

int factorial (int num)
{
    int fact = 1;
   for (int i=1; i<=num; i++){
    fact = fact * i;
   }

    return fact;

}
