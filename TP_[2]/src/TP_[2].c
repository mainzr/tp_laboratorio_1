/*
 ============================================================================
 Name        : TP_[2].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "ArrayEmployees.h"
#include "inputs.h"

#define LEN 1000
#define NAME_LEN 51


int main(void) {
	setbuf(stdout, NULL);

	eEmployee list[LEN];
	eEmployee oneEmployeeAux;
	char restart = 's';
	int id = 1;
	int firstFlag = 0;


	if(initEmployees(list, LEN) == -1)
	{
		printf("Ocurrio un problema....Reintentelo nuevamente.\n");
	}


	do{
		switch(menu()){
		    case 1:
		    	if(addEmployees(list, LEN, id, oneEmployeeAux.name, oneEmployeeAux.lastName, oneEmployeeAux.salary, oneEmployeeAux.sector)== 0)
		    	{
		    		printf("\nSu alta se realizo exitosamente.\n");
		    		id++;
		    		firstFlag = 1;
		    	}
		    	else
		    	{
		    		printf("Ocurrio un problema al realizar el alta...Reintentelo nuevamente.\n");
		    	}


				break;

		    case 2:
		    	if(firstFlag == 0)
		    	{
		    		printf("\nSe debe dar de alta un empleado.\n");
		    	}
		    	else
		    	{
		    		modifyEmployee(list, LEN);
		    	}

				break;

			case 3:
				if(firstFlag == 0)
				{
					printf("\nSe debe dar de alta un empleado\n");

				}
				else
				{
					if(removeEmployee(list, LEN, id) == 0)
					{
						printf("\nLa baja se ha realizado con exito!\n");

					}
					else
					{
						printf("\nOcurrio un problema al realizar la baja....Reintentelo nuevamente.\n");
					}
				}
				resetFlag(list, LEN, &firstFlag);
				break;

			case 4:
				if(firstFlag == 0)
				{
					printf("\nSe debe dar de alta un empleado.\n");
				}
				else
				{
					inform(list, LEN);
				}

				break;

			case 5:
				printf("\n¿Seguro desea salir majestad? (s/n): ");
				fflush(stdin);
				scanf("%c", &restart);
				restart = 'n';
			     break;

		    default:
		    	printf("Opcion invalida....Reintentelo nuevamente.\n\n");
		    	break;
			}

		//system("pause");


	} while(restart == 's');





	return EXIT_SUCCESS;
}
