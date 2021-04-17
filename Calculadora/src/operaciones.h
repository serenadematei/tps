/*
 * operaciones.h
 *
 *  Created on: 14 abr. 2021
 *      Author: Sere
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "operaciones.h"

/** \brief Muestra la lista de opciones del Menú y pide al usuario ingresar opcion seleccionada
*
* \param int Primer entero a evaluar(dato ingresado por el usuario)
* \param int Segundo entero a evaluar(dato ingresado por el usuario)
* \param int Bandera que evalua si el usuario ingresó o no el primer entero
* \param int Bandera que evaluar si el usuario ingresó o no el segundo entero
* \return int Opcion elegida por el usuario
*
*/
int Menu(int,int,int,int);


/** \brief Pide al usuario el ingreso de un entero
*
* \return int Primer y segundo entero ingresados por el usuario
*
*/
int pidoNumeros();


/** \brief Realiza la suma de dos enteros y devuelve el resultado
*
* \param  int Primer entero a evaluar
* \param  int Segundo entero a evaluar
* \return int Resultado de la suma
*
*/
int sumar (int,int);


/** \brief Realiza la multiplicacion de dos enteros y devuelve el resultado
*
* \param int Primer entero a evaluar
* \param int Segundo entero a evaluar
*
* \return int Resultado de la multiplicacion
*
*/
int multiplicar (int,int);


/** \brief Calcula la diferencia entre los dos enteros y devuelve el resultado
*
* \param int Primer entero a evaluar
* \param int Segundo entero a evaluar
* \return int Resultado de la resta
*
*/
int restar (int,int);


/** \brief Realiza la division entre los dos enteros, castea el resultado y lo devuelve
*
* \param int Primer entero a evaluar
* \param int Segundo entero a evaluar
* \return float Resultado de la division
*
*/
float dividir (int,int);


/** \brief Calcula el factorial del primer entero ingresado y devuelve el resultado
*
* \param int Primer entero a evaluar
*
* \return long long int Factorial del primer entero
*
*/
long long int factorizar (int);


/** \brief Muestra los resultados de los calculos realizados
*
* \param int Primer entero a evaluar
* \param int Segundo entero a evaluar
* \param int Resultado de la funcion suma
* \param int Resultado de la funcion resta
* \param float Resultado de la funcion dividir
* \param int Resultado de la funcion multiplicar
* \param long long int Resultado de la funcion factorizar
*
*/
void muestroResultados(int ,int ,int ,int , float , int ,long long int );



/** \brief Pide al usuario la confirmación de la salida
*
* \param char Puntero a la variable salida
*
* \return char Opcion elegida por el usuario
*
*/
char verificaSalida(char*);


#endif /* OPERACIONES_H_ */
