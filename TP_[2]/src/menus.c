/*
 * menus.c
 *
 *  Created on: 16 oct. 2021
 *      Author: MAIA
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "validaciones.h"
#include "menus.h"

int menu(){

	int opcion;

	printf("                             **********************************************************************  ");
	printf("\n                                                          ABM EMPLEADOS                           \n");
	printf("                             **********************************************************************  \n\n");

	printf("--------------------------------------------------------------\n");
	printf("                      MENU DE OPCIONES                  \n");
	printf("--------------------------------------------------------------\n\n");
	printf(" 1. ALTAS EMPLEADOS\n");
	printf(" 2. MODIFICAR EMPLEADOS\n");
	printf(" 3. BAJA EMPLEADOS\n");
	printf(" 4. INFORMAR\n");
	printf(" 5. Salir\n\n");

	printf("Ingrese opcion deseada: ");
	scanf("%d", &opcion);

	return opcion;
}


int modifyMenu(){

	int option;

	printf("---------------------------------------------------------------------\n");
	printf("                         MENU DE MODIFICACIONES                      \n");
	printf("---------------------------------------------------------------------\n\n");

	printf(" 1. Nombre.\n");
	printf(" 2. Apellido\n");
	printf(" 3. Salario\n");
	printf(" 4. Sector\n\n");

	printf("Ingrese la opcion que desee modificar: ");
	scanf("%d", &option);

	return option;
}


int menuSortEmployees()
{
	int option;

	printf("---------------------------------------------------------------\n");
	printf("                       MENU DE INFORMES                    \n");
	printf("-----------------------------------------------------------------\n");

	printf("1. Informar empleados alfabeticamente por apelliodo y sector. \n");
	printf("2. Informar sueldo total, promedio y cantidad de empleados que superan promedio total.\n");
	printf("3. Volver al menu principal\n\n");

	printf("Elija opcion de que desea informar: ");
	scanf("%d", &option);


	return option;
}
