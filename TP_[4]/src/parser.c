#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../inc/LinkedList.h"
#include "../inc/Employee.h"
#include "../inc/parser.h"
#include "../inc/Controller.h"

/**
 * @fn int parser_EmployeeFromText(FILE*, LinkedList*)
 * @brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * @param pFile puntero que apunta al archivo
 * @param pArrayListEmployee lista de empleados de tipo puntero a estructura
 * @return retorna 1 si no hubo error y 0 si hubo error
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int error = 1;
	char buffer[3][20];
	char nombre[60];
	Employee* employee;
	int cant;
	char* nextId = "1";

	if(pFile == NULL)
	{
		printf("No se pudo abrir el archivo.\n");
		exit(1);
	}

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		//pFile = fopen("data.csv", "r");

			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],nombre, buffer[1], buffer[2]);

			while(!feof(pFile))
			{
				cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], nombre, buffer[1], buffer[2]);

				if(cant == 4)
				{

					nextId = buffer[0];
					employee = employee_newParametros(buffer[0], nombre, buffer[1], buffer[2]);

					if(employee != NULL)
					{
						cant = ll_add(pArrayListEmployee, employee);

						if(cant != 0)
						{
							employee_delete(employee);
							error = 1;
							break;
						}
						else
						{
							error = 0;
						}
					}
				}
				else
				{
					break;
				}
			}

			controller_IdSig(atoi(nextId));


	}


    return error;
}
