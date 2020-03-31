
#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"



int main()
{
    int flag1=0;
    int flag2=0;
    int flag3=0;
    int flag4=0;
    int num1;
    int num2;
    int opcion;
    int auxSuma;
    int auxResta;
    int auxMultiplicacion;
    float auxDivision;
    int auxFact1;
    int auxFact2;

    //UTILIZO LOS FLAGS PARA CAMBIAR LAS LETRAS POR NUMEROS

   do{
    system("cls");
    printf ("ELIJA UNA OPCION DEL 1 al 5\n\n\n");
    if (flag1==0)
        {
            printf("1. Ingresar 1er operando (A=x)\n\n");
        }else{
            printf("1. Ingresar 1er operando (A=%d)\n\n",num1);
        }
//---------------FIN FLAG1-----------------------
    if(flag2==0)
        {
            printf("2. Ingresar 2do operando (B=y)\n\n");
        }else{
            printf("2. Ingresar 2do operando (B=%d)\n\n",num2);
        }

//---------------FIN FLAG2-----------------------
    if (flag3==0)
    {
        printf("3. Calcular todas las operaciones\n\n");
        printf("a) Calcular la suma (A+B)\nb) Calcular la resta (A-B)\nc) Calcular la division (A/B)\nd) Calcular la multiplicacion (A*B)\ne) Calcular el factorial (A!)\n\n");
    }else{
        printf("3. Calcular todas las operaciones\n\n");
        printf("a) Calcular la suma (%d+%d)\n",num1,num2);
        printf("b) Calcular la resta (%d-%d)\n",num1,num2);
        printf("c) Calcular la division (%d/%d)\n",num1,num2);
        printf("d) Calcular la multiplicacion (%d*%d)\n",num1,num2);
        printf("e) Calcular el factorial primer num (%d!), factorial segundo num (%d!)\n\n",num1,num2);
    }
//---------------FIN FLAG3-----------------------
    if (flag4==0){
            printf("4. Informar resultados\n\n");
            printf("a) El resultado de A+B es: r\nb) El resultado de A-B es: r\nc) El resultado de A/B es: r o No es posible dividir por cero\nd) El resultado de A*B es: r\ne) El factorial de A es: r1 y El factorial de B es: r2\n\n");
    }else{
        printf("4. Informar resultados\n\n");
        printf("a) El resultado de %d+%d es: %d\n",num1,num2,auxSuma);
        printf("b) El resultado de %d-%d es: %d\n",num1,num2,auxResta);
        if (num2!=0){
                printf("c) El resultado de %d/%d es: %.2f\n",num1,num2,auxDivision);
        }else{
            printf("No es posible dividir por cero\n");
        }
        printf("d) El resultado de %d*%d es: %d\n",num1,num2,auxMultiplicacion);
        printf("e) El factorial de %d es: %d y El factorial de %d es: %d\n\n",num1,auxFact1,num2,auxFact2);

    }
//---------------FIN FLAG4-----------------------
    printf("5. Salir\n\n");

    scanf("%d", &opcion);


    switch(opcion)
    {
        case 1:
            printf("Ingresa primer operando: \n");
            scanf("%d", &num1);
            flag1=1;
            break;

        case 2:
            printf("Ingresa segundo operando: \n");
            scanf("%d", &num2);
            flag2=1;
            break;

        case 3:
           if (flag1==0&&flag2==0)
           {
               printf("Faltan los dos numeros\n");

           }else if(flag1==1&&flag2==0)
            {
            printf("Falta el segundo numero\n");
            }else if(flag1==0&&flag2==1)
            {
                printf("Falta el primer numero\n");
            }else{
                auxSuma= suma(num1,num2);
                auxResta= resta(num1,num2);
                auxMultiplicacion= multiplicacion(num1,num2);
                if(num2!=0)
                    {
                        auxDivision= division(num1,num2);

                    }else{
                        printf("No se puede dividir por cero\n");
                    }

                auxFact1= factorial(num1);
                auxFact2= factorial(num2);


            }
            printf("Calculos terminados\n");
            flag3=1;
            break;

        case 4:
            if (flag3==1)
            {
                flag4=1;
            }
            break;


    }//FIN DEL SWITCH

   }while(opcion!=5);
    return 0;
}
