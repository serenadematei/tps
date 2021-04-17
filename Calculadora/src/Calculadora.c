/*
 ============================================================================
 Nombre        : Calculadora.c
 Autora        : Dematei Serena
 Descripcion   : Este programa pide el ingreso de dos numeros y realiza la
                 suma,resta,division y multiplicacion entre ambos, y el
                 factorial del primer numero ingresado. Luego,muestra los
                 resultados.
 Fecha         : 17/04/2021
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "operaciones.h"




int main()
{
	setbuf(stdout,NULL);
    int a;
    int b;

    int bandera1=0;
    int bandera2=0;
    int bandera3=0;
    int resultadoS;
    int resultadoM;
    float resultadoD;
    int resultadoR;
    int resultadoF;
    char salida='n';




     do
    {

        switch(Menu(bandera1,bandera2,a,b))
        {
        case 1:
            system("cls");

             a = pidoNumeros();
                bandera1=1;


            break;

        case 2:
            system("cls");

              if(bandera1)
            {
               b = pidoNumeros();
               bandera2=1;
            }
            else
            {

                printf("Primero debe ingresar el primer operando\n\n");
                system("pause");
            }

            break;




       case 3:
            system("cls");

            if(bandera1 && !bandera2)
            {
                printf("Primero debe ingresarse el segundo operando\n");
                system("pause");

            }
            else if(!bandera1)
            {
                printf("Primero debe ingresarse el primer operando\n");
                system("pause");
            }
            else
            {

                printf("\n\n************CALCULOS RESUELTOS************\n\n\n");
                printf("Ingrese opcion 4 en el menu para ver los resultados\n\n\n");
                bandera3=1;

               resultadoS=sumar(a,b);
               resultadoR=restar(a,b);
               resultadoM=multiplicar(a,b);
               resultadoD=dividir(a,b);
               resultadoF=factorizar(a);

                system("pause");

            }

            break;

       case 4:
            system("cls");
            if(bandera3)
            {
                muestroResultados(a,b,resultadoS,resultadoR,resultadoD,resultadoM,resultadoF);
                //reinicio las banderas
                bandera1=0;
                bandera2=0;
                bandera3=0;
                system("pause");
            }
            else
            {
                printf("Se deben realizar los calculos antes de informar los resultados\n\n\n");

                system("pause");
            }
            break;

       case 5:
            system("cls");
            verificaSalida(&salida);
            break;





             }


     printf("\n\n\n");



      }while (salida=='n');
    return 0;
}


