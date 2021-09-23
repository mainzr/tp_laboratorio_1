/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaAnzor.h"

//-------------------------MAIN-----------------
int main() {
	setbuf(stdout, NULL);

	int a;
	int b;
	char seguir = 'n';
	int flagUno = 0;
	int flagDos = 0;
	int suma;
	int resta;
	int multiplicacion;
	int respuestaFactorialA;
	int respuestaFactorialB;
	float respuestaDivision;
	int errorFactA;
	int errorFactB;
	int flagTres = 0;
	int errorDivision;
	int calculadora;

	do{

		switch(menu(flagUno, a, flagDos, b)){
			 case 1:
				 printf("Ingrese 1er operador\n");
				 scanf("%d", &a);
				 flagUno = 1;
				 break;


			 case 2:

				 if(flagUno == 0){
					 printf("Debe ingresar el 1er operando\n");

				 }else{
					 printf("Ingrese 2do operador\n");
					 scanf("%d", &b);
					 flagDos = 1;
				 }
				 break;
			 case 3:
				 if(flagUno == 0 && flagDos == 0){
					 printf("Se debe ingresar 1er y 2do operando\n");

				 } else{
					 if(flagUno == 1 && flagDos == 0){
						 printf("Se debe ingresar 2do operando\n");
					 } else {
						 if(flagUno == 0 && flagDos == 1) {
							 printf("Ingrese 1er operando\n");
						 } else {
							 calculadora = hacerOperaciones(a, b, &suma, &resta, &multiplicacion, &errorFactA, &errorFactB, &errorDivision, &respuestaFactorialA, &respuestaFactorialB, &respuestaDivision);

							 if(calculadora != 1){
								 printf("No se pudieron realizar operaciones\n");
							 }

							 flagTres = 1;
						 }
					 }
				 }
				 break;
			 case 4:
				 if(flagUno == 1 && flagDos == 0){
					 printf("\nSe debe ingresar 2do operando\n");
				 } else {
					 if(flagTres == 0){
						 printf("\nSe deben calcular todas las operaciones\n");
					 } else {
						 /*
						 informar resultados*/
						 informarResultados(a, b, suma, resta, multiplicacion, errorFactA, errorFactB, errorDivision, respuestaFactorialA, respuestaFactorialB, respuestaDivision);

					 }
				 }
				 break;

			 case 5:
				 flagUno = 1;
				 flagDos = 1;
				 flagTres = 1;
				 printf("¿Seguro desea salir majestad? (s/n)\n");
				 fflush(stdin);
				 scanf("%c", &seguir);
				 break;
			 default:
				 printf("Ingreso una opcion invalida...\nReintentelo nuevamente.\n\n");
				 break;
		}

		system("pause");

	} while(seguir == 'n');

	return EXIT_SUCCESS;
}


