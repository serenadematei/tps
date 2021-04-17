/*
 * operaciones.c
 *
 *  Created on: 14 abr. 2021
 *      Author: Sere
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "operaciones.h"



int Menu(int bandera1, int bandera2,int a, int b)
{
     int opcion;

      system("cls");
      printf("*** Menu de opciones ***\n\n\n\n");

        printf("1- Ingresar primer operando");
         if (bandera1==1)
        {
            printf(" = %d",a);
        }
        else
        {
            printf(" = x");
        }

        printf("\n2- Ingresar segundo operando");
         if (bandera2==1)
        {
            printf(" = %d",b);
        }
        else
        {
            printf(" = y");
        }


        printf("\n3- Calcular todas las operaciones\n");
        printf("\t a)Calcular la suma (A+B)\n");
        printf("\t b)Calcular la resta (A-B)\n");
        printf("\t c)Calcular la division (A/B)\n");
        printf("\t d)Calcular la multiplicacion (A*B)\n");
        printf("\t e)Calcular el factorial (A!)\n");

        printf("4- Informar resultados\n");
        printf("5- Salir\n");

        printf("\nIngrese opcion del 1 al 5:\n");
        scanf("%d",&opcion);
        while(opcion<1||opcion>5)
        {
            printf("ERROR.Ingrese opcion del 1 al 5:  ");
            scanf("%d",&opcion);
        }


        return opcion;
}

char verificaSalida(char* pSalida)
{
    char salidaVerificada;

    if (pSalida!=NULL)
    {
        printf("¿Confirma salida?  s/n: ");
        fflush(stdin);
        scanf("%c",&salidaVerificada);
        salidaVerificada=tolower(salidaVerificada);
       *pSalida= salidaVerificada;



       while(!((salidaVerificada=='s') || (salidaVerificada=='n')))
                  {
                      printf("Reintente el ingreso (s/n): ");
                      fflush(stdin);
                      scanf("%c",&salidaVerificada);
                      salidaVerificada=tolower(salidaVerificada);
                      *pSalida= salidaVerificada;
                  }


    }







    return salidaVerificada;


}



int pidoNumeros()
{
    int numeroIngresado;
    printf("Ingrese un numero:\n");
    scanf("%d",&numeroIngresado);

    return numeroIngresado;
}


int sumar (int a,int b)
{
    int resultadoS;
    resultadoS=a+b;

    return resultadoS;
}


float dividir(int a,int b)
{
    float resultadoD;
    resultadoD= (float)a/b;
    return resultadoD;

}

int multiplicar(int a,int b)
{
    int resultadoM;
    resultadoM=a*b;

    return resultadoM;
}

int restar(int a,int b)
{
    int resultadoR;
    resultadoR=a-b;

    return resultadoR;
}


long long int factorizar(int a)
{
    long long int resultadoF=1;

    for (int i=1 ; i<=a ; i++)
    {
        resultadoF *=i;
    }

    return resultadoF;
}

void muestroResultados(int a,int b,int resultadoS,int resultadoR, float resultadoD, int resultadoM,long long int resultadoF)

{

   printf("\n*****************RESULTADOS*****************\n\n\n\n");
   printf("El resultado de la suma es: %d\n", resultadoS);
   printf("El resultado de la multiplicacion es: %d\n", resultadoM);
   printf("El resultado de la resta es: %d\n",resultadoR);

     if(b!=0)
            {
                printf("El resultado de la division es: %.2f \n",resultadoD);
            }
            else
            {
                printf("No pudo realizarse la division\n");
            }

   printf("El resultado del factorial del primer numero es: %I64u\n\n\n",resultadoF);

   //ACLARACION: %I64u es la unica mascara para long long int que no me produce warnings
}

