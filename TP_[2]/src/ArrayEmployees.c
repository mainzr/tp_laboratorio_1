#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "inputs.h"

int resetFlag(eEmployee* list, int len, int* flag){
	int error = -1;
	//int flag = 0;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 1)
			{
				*flag = 0;
			}
			else
			{
				*flag = 1;
				break;
			}
		}
		error = 0;
	}



	return error;
}

int initEmployees(eEmployee* list, int len){
	int error = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			list[i].isEmpty = 1;
		}

		error = 0;
	}
	return error;
}


int searchFree(eEmployee list[], int len){

	int index = -1;

	if(list != NULL && len > 0)
	{

		for(int i = 0; i < len; i++)
		{

			if(list[i].isEmpty == 1)
			{
				index = i;

				break;
			}
	   }
	}

	return index;
}



int addEmployees(eEmployee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	int error = -1;
	int index;
	eEmployee auxEmployee;
	//eEmployee aux;
	//char auxName[100];



	if(list != NULL && len > 0 && name != NULL && lastName != NULL)
	{
		 printf("--------------------------------------------------------------\n");
		 printf("                        ALTA EMPLEADOS                       \n");
		 printf("--------------------------------------------------------------\n\n");

		 index = searchFree(list, len);

		 if(index == -1)
		 {
			 printf("\nNo existe lugar disponible...\n");
			 error = -1;
		 }
		 else
		 {
			 auxEmployee.id = id;

			getString(name, len, "Ingrese nombre del empleado: ", "Error al ingresar nombre...Reeintentelo nuevamnete.", 51);
			strcpy(auxEmployee.name, name);


			getString(lastName, len, "Ingrese apellido del empleado: ", "Error al ingresar apellido....Reintentelo nuevamente: ", 51);
			validateLetters(lastName);
			strcpy(auxEmployee.lastName, lastName);

			getFloat(&salary, "Ingrese monto del salario (entre 1 - 500000): ", "Error al ingresar salario...Reintentelo nuevamente: ", 1, 500000);
			auxEmployee.salary = salary;


			getInteger(&sector, "Ingrese sector del empleado (entre 1 - 20): ", "Error al ingresar sector...Reintentelo nuevamente: ", 1, 20);
			auxEmployee.sector = sector;


			auxEmployee.isEmpty = 0;
			list[index] = auxEmployee;
			error = 0;

		 }
	}
	system("cls");

	return error;
}


int findEmployeeById(eEmployee* list, int len, int id){

	int idFound = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 0 && list[i].id == id){
				idFound = i;
			}
		}
	}

	return idFound;
}


void printEmployee(eEmployee oneEmployee) {
	printf("    %-10d     %-20s    %-11s          $ %-12.2f        %-5d",
			oneEmployee.id,
			oneEmployee.name,
			oneEmployee.lastName,
			oneEmployee.salary,
			oneEmployee.sector);
}

int printEmployees(eEmployee* list, int length){
	int error = -1;
	int flag = 1;

	if(list != NULL && length > 0)
	{

		 printf("\n                                  LISTA DE EMPLEADOS                             \n");
		 printf(" -------------------------------------------------------------------------------------------\n");
		 printf("    ID              NOMBRE                 APELLIDO             SALARIO            SECTOR     \n");
		 printf(" -------------------------------------------------------------------------------------------\n\n");

		for(int i = 0; i < length; i++){

			if(list[i].isEmpty == 0)
			{
				printEmployee(list[i]);
				flag = 0;
				printf("\n");
			}

		}
		printf("\n\n");

		if(flag == 1)
		{
			printf("No existen empleados para mostrar.\n");
		}


		error = 0;
	}

	return error;
}


int modifyEmployee(eEmployee* list, int len)
{
	int error = -1;
	int id;
	int index;
	char confirm;
	char auxChar[20];
	float auxFloat;
	int auxInt;


	if(list != NULL && len > 0)
	{

		system("cls");

		printf("--------------------------------------------------------------\n");
		printf("                        MODIFICAR EMPLEADOS                       \n");
		printf("--------------------------------------------------------------\n");

		printEmployees(list, len);
		printf("Ingrese ID del empleado que desea modificar: ");
		scanf("%d", &id);

		index = findEmployeeById(list, len, id);

		if(index == -1)
		{
			printf("\nNo existe un empleado con ese ID...\n");
		}
		else
		{
			printEmployee(list[index]);

			printf("\n\n¿Desea confirmar la modificacion de este empleado? (s/n): ");
			fflush(stdin);
			scanf("%c", &confirm);
			if(validateChar(confirm, 's', 'n'))
			{
				printf("Opcion incorrecta...Reintentelo nuevamente: ");
				fflush(stdin);
				scanf("%c", &confirm);
			}

			if(confirm == 's')
			{

				switch (modifyMenu()) {
					case 1:

						getString(auxChar, len, "Ingrese el nuevo nombre: ", "\nDato invalido...Reintentelo nuevamente.\n", 51);
						validateLetters(auxChar);
						strcpy(list[index].name, auxChar);

						printf("\n\nLista de empleados actualizada: ");
					    printEmployees(list, len);



						break;

					case 2:

						getString(auxChar, len, "Ingrese el nuevo apellido: ", "Dato invalido...Reintentelo nuevamente: ", 51);
						validateLetters(auxChar);
						strcpy(list[index].lastName, auxChar);

						printf("\n\nLista de empleados actualizada: ");
					    printEmployees(list, len);
						break;

					case 3:
						getFloat(&auxFloat, "Ingrese el nuevo monto (entre $1 - $500000): $ ", "Dato invalido...Reintentelo nuevamente.\n", 1, 500000);
						list[index].salary = auxFloat;

						printf("\n\nLista de empleados actualizada: ");
					    printEmployees(list, len);
						break;

					case 4:
						getInteger(&auxInt, "Ingrese el nuevo sector (entre 1 - 20): ", "Dato invalido...Reintentelo nuevamente.\n", 1, 20);
						list[index].sector = auxInt;

						printf("\n\nLista de empleados actualizada: ");
					    printEmployees(list, len);
						break;

					default:
						printf("Error al elegir opcion...Reintentelo nuevamente.\n");
						break;
				}

				error = 0;

			}
		}



	}



	return error;
}


int removeEmployee(eEmployee* list, int len, int id){
	int error = -1;
	int index;
	char confirm;

	if(list != NULL && len > 0){

		printf("--------------------------------------------------------------\n");
		printf("                        BAJA EMPLEADOS                       \n");
		printf("--------------------------------------------------------------\n\n");

		printEmployees(list, len);


		printf("Ingrese el ID del empleado que desea dar de baja: \n");
		scanf("%d", &id);

		index = findEmployeeById(list, len, id);

		if(index == -1){
			printf("No se encontro empleado con ID: %d... Reintentelo nuevamente.\n", id);
		}
		else
		{
			printf("¿Desea confirmar la baja de empleado? (s/n)");
			fflush(stdin);
			scanf("%c", &confirm);
			if(validateChar(confirm, 's', 'n'))
			{
				printf("Opcion incorrecta...Reintentelo nuevamente: ");
				fflush(stdin);
				scanf("%c", &confirm);
			}

			if(confirm == 's'){
				list[index].isEmpty = 1;
				error = 0;
			}
			else
			{
				printf("\nSe ha cancela la baja de empleado...\n");
			}
		}

	}

	return error;
}




int sortEmployees(eEmployee* list, int len, int order){
	//ORDENAR EMPLEADOS POR ALFABETICAMENTE POR APELLIDO Y SECTOR
	//Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
	int error = -1;
	eEmployee auxEmployee;


	if(list != NULL && len > 0)
	{

		for(int i = 0; i < len - 1; i++)
		{
			for(int j = i + 1; j < len; j++)
			{
				 //1 -ascendente - 0 descendente
				if(order == 1)
				{
					if(strcmp(list[i].lastName, list[j].lastName) > 0 || (strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector > list[j].sector) )
					{
						auxEmployee = list[i];
						list[i] = list[j];
						list[j] = auxEmployee;
					}
				}
				else
				{
					if(order == 0)
					{
						if(strcmp(list[i].lastName, list[j].lastName) < 0 || (strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector < list[j].sector))
						{
							auxEmployee = list[i];
							list[i] = list[j];
							list[j] = auxEmployee;
						}
					}
				}

			}
		}


		error = 0;
	}



	return error;
}

int sortEmployeesTwo(eEmployee* list, int len){
	int error = -1;
	float total = 0;
	int amount = 0;
	float average;
	int amountTotal = 0;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 0)
			{
				total += list[i].salary;
				amount++;
			}
		}


		if(amount != 0)
		{
			average = total / amount;
		}

		for(int i = 0; i < len; i++)
		{
			if(list[i].salary > average && list[i].isEmpty == 0){
				amountTotal++;
			}
		}

		printf("\n------------------------------------------------\n");
		printf("- Total de los salarios: $ %.2f \n", total);
		printf("- Promedio de los salarios: %.2f\n", average);
		printf("- Empleados que superan el salario promedio: %d \n", amountTotal);
		printf("-------------------------------------------------\n\n");


		error  = 0;
  }
	return error;
}


int inform(eEmployee* list, int len){
	int error = -1;
	int orden;

	if(list != NULL && len > 0)
	{
		switch(menuSortEmployees()){
		case 1:
			printf("\nQuiere ordenar de forma ascendente(1) o descendente(0)?: ");
			scanf("%d", &orden);
			while(orden != 0 && orden != 1)
			{
				printf("Error al ingresar forma de ordenamiento....Reintentelo nuevamente: ");
				scanf("%d", &orden);
			}
			sortEmployees(list, len, orden);
			printEmployees(list, len);
			break;

		case 2:
			sortEmployeesTwo(list, len);
			break;

		case 3:
			printf(" ");
			break;

		default:
			printf("Opcion invalida... Reintentelo nuevamente. ");
			break;
		}//cierre switch

		error = 0;
	}

	return error;
}
