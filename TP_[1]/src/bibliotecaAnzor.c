/*
 * bibliotecaAnzor.c
 *
 *  Created on: 18 sep. 2021
 *      Author: MAIA
 */
#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaAnzor.h"



//-------------MENU------------------
int menu(int banderaPrimerIngreso, int x, int banderaSegundoIngreso, int y)
{
	int opcion;

	system("cls");

	if(banderaPrimerIngreso == 0){

		printf(" Bienvenido a la 'Calculadora 2.0'\n Elija una opcion:\n\n");
		printf(" -Menu de opciones-\n\n");
		printf(" 1. Ingrese 1er operador\n");
	} else {
		printf("\n -Menu de opciones-\n\n");
		printf(" 1. Numero ingresado: (A = %d)\n", x);
	}

	if(banderaSegundoIngreso == 0){
		printf(" 2. Ingrese 2do operador\n");
	} else {
		printf(" 2. Numero ingresado: (B = %d)\n", y);
	}

	printf(" 3. Calcular todas las operaciones\n");

	printf(" 4. Informar resultados\n");

	printf(" 5. Salir\n\n");

	scanf("%d", &opcion);

	return opcion;
}
//-------------------------SUMA---------------
int sumar(int a, int b)
{
	int respuesta;

	respuesta = a + b;

	return respuesta;
}
//-------------------RESTA---------------
int restar(int x, int y)
{
	int resta;
	resta = x - y;

	return resta;
}

//----------------DIVISION----------------
int dividir(int x, int y, float* division)
{
	int error = 0;

	if(y != 0 && division != NULL){
		*division = (float) x / y;
		error = 1;//no hay error
	}


	return error;
}

//----------------factorial.-----
int multiplicar(int x, int y)
{
	int multiplicacion;
	multiplicacion = x * y;

	return multiplicacion;
}

//----------------FACTORIAL-------------

int factorial(int x, int* rtaFactorial){
	int error = 0;
	int factorial = 1;

	if(x >= 0 && rtaFactorial != NULL){
		for(int i = 1; i <= x; i++){
			factorial *= i;
		}
		*rtaFactorial = factorial;
		error = 1;//no hay error
	}

	return error;
}

//-----------------------------------
int hacerOperaciones(int x, int y, int* respuestaSuma, int* respuestaResta, int* respuestaMultiplicacion, int* errorA, int* errorB, int* errorDiv, int* respuestaFactorialA, int* respuestaFactorialB, float* respuestaDivision){

	int error = 0;

	if(respuestaSuma != NULL && respuestaResta != NULL && respuestaMultiplicacion != NULL && errorA != NULL && errorB != NULL && errorDiv != NULL){
		*respuestaSuma = sumar(x, y);
		*respuestaResta = restar(x, y);
		*respuestaMultiplicacion = multiplicar(x, y);
		*errorA = factorial(x, &*respuestaFactorialA);
		*errorB = factorial(y, &*respuestaFactorialB);
		*errorDiv = dividir(x, y, &*respuestaDivision);

		error = 1;//no hay error
	}

	return error;
}
//------------------------------------
void informarResultados(int x, int y, int suma, int resta, int multiplicacion, int errorFactA, int errorFactB, int errorDiv, int respuestaFactorialA, int respuestaFactorialB, float respuestaDivision){


	printf("\n Resultado de: %d + %d: %d\n", x, y, suma);
	printf(" Resultado de: %d - %d: %d\n", x, y, resta);

	if(errorDiv == 1){
		printf(" Resultado de: %d / %d: %.2f\n", x, y, respuestaDivision);
	} else {
		printf(" No se puede realizar la division\n");
	}

	printf(" Resultado de: %d * %d: %d\n", x, y, multiplicacion);

	if(errorFactA == 1){
		printf(" El factorial de !%d es: %d\n", x, respuestaFactorialA);
	} else {
		printf(" No se puede calcular factorial de !%d\n", x);
	}

	if(errorFactB == 1){
		printf(" El factorial de !%d es %d\n\n", y, respuestaFactorialB);
	} else {
		printf(" No se pudo calcular factorial de !%d\n\n", y);
	}

}

