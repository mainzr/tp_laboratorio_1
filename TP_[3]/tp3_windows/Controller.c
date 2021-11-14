#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "inputs.h"

/**
 * @fn int menu()
 * @brief muestra menu principal de opciones
 *
 * @return retorna la opcionelejida por usuario
 */
int menu()
{
	int option;

	printf("\n\n**************************************************\n");
	printf("                 AMB EMPLOYEES      \n");
	printf("**************************************************\n\n");

    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n\n");

	printf("Ingrese opcion deseada: ");
	scanf("%d", &option);


	return option;
}

/**
 * @fn int editEmployeeMenu()
 * @brief menu de modificaciones segun nombre, horas trabajadas y salario
 *
 * @return retorna opcion elejida por usuario
 */
int editEmployeeMenu()
{

	int option;

	printf("---------------------------------------------------------------------\n");
	printf("                         MENU DE MODIFICACIONES                      \n");
	printf("---------------------------------------------------------------------\n\n");

	printf(" 1. Nombre.\n");
	printf(" 2. Cantidad de horas trabajadas\n");
	printf(" 3. Salario\n");

	printf("Ingrese la opcion que desee modificar: ");
	scanf("%d", &option);

	return option;
}

/**
 * @fn int menuSortEmployees()
 * @brief muestra menu de  ordenamiento
 *
 * @return retorna opcion elejida por usuario
 */
int menuSortEmployees()
{
	int option;

	printf("---------------------------------------------------------------\n");
	printf("                       MENU DE ORDENAMIENTO                \n");
	printf("-----------------------------------------------------------------\n");

	printf("1. Ordenar empleados por nombre\n");
	printf("2. Ordenar empleados por ID\n");
	printf("3. Ordenar empleados por horas trabajadas\n");
	printf("4. Ordenar empleados por sueldo\n");
	printf("5. Salir\n\n");

	printf("Elija opcion de que desea informar: ");
	scanf("%d", &option);


	return option;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*  nombre del archivo que se cargara
 * \param pArrayListEmployee LinkedList* lista de empeado de tipo estructura linkedList
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int error = 1;
	FILE* pFile;

	if(path != NULL && pArrayListEmployee != NULL)
	{



		pFile = fopen(path, "r");

		if(pFile == NULL)
		{
			printf("No se pudo abrir el archivo\n");
			error = 1;
			exit(1);
		}
		else
		{
			parser_EmployeeFromText(pFile, pArrayListEmployee);
			error = 0;
		}
		fclose(pFile);
	}

    return error;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* nombre del archivo que se cargara
 * \param pArrayListEmployee LinkedList* lista de tipo estructura linkedlist
 * \return int retorna 1 si hubo error y 0 si no hubo
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int error = 1;
	FILE* pFile;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "rb");

		if(pFile != NULL)
		{
			parser_EmployeeFromBinary(pFile, pArrayListEmployee);
			error = 0;
		}
		else
		{
			printf("No se puede abrir el archivo\n");
			error = 1;
			exit(1);
		}
		fclose(pFile);
	}

    return error;
}



/**
 * @fn int controller_IdSig()
 * @brief calcula el que sera el siguiente id
 *
 * @return retorna el siguiente ud que tendra el empleado
 */
int controller_IdSig()
{
	FILE* pFile = fopen("idMax.txt", "r");
	int* idEnUso = (int*) malloc(sizeof(int));
    int nextId;

    if(pFile == NULL)
    {
        nextId = 1001;
    }
    else
    {
        fscanf(pFile, "%d", idEnUso);
        nextId = *idEnUso + 1;
    }
    fclose(pFile);

    return nextId;
}


/**
 * @fn void controller_guardarIdSig(int)
 * @brief se guardara el ultimo id, de ahi en adelante se utilizara cada vez que el programa cargue
 *
 * @param id devuelve el id que tendra el empleado
 */
void controller_guardarIdSig(int idActual)
{
    FILE* pFile = fopen("idMax.txt", "r+");

    if(pFile == NULL)
    {
    	pFile = fopen("idMax.txt", "w");
    }

    fprintf(pFile,"%d", idActual);

    fclose(pFile);
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList* lista de empleados de tipo estructura de tipo LinkedList
 * \return int retorna 1 si hubo error y 0 si no hubo error
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int error = 1;
	Employee* employeeNew;
	//int aux;
	char nombre[128];
	int sueldo;
	int horasTrabajadas;
	int id;


	if(pArrayListEmployee != NULL)
	{

		employeeNew = employee_new();

		if(employeeNew == NULL)
		{
			printf("Error al agregar empleado...\n");
		}
		else
		{
			//system("cls");

			 printf("--------------------------------------------------------------\n");
			 printf("                        ALTA EMPLEADOS                       \n");
			 printf("--------------------------------------------------------------\n\n");


			 //id = controller_nextId();
			 id = controller_IdSig();

			 //controller_saveNextId(id);
			 employee_setId(employeeNew, id);

			 pedirCadena(nombre, "Ingrese nombre del empleado: ", "Error....Reingrese nombre: ", 128);
			 firstLetterMayus(nombre);
			 validateLetters(nombre);
			 employee_setNombre(employeeNew, nombre);

			 getInteger(&sueldo, "Ingrese monto de sueldo (entre: 1000 - 600000): ", "Error al ingresar sueldo....Reintentelo: ", 1, 600000);
			 employee_setSueldo(employeeNew, sueldo);

			 getInteger(&horasTrabajadas, "Ingrese cantidad de horas trabajadas: (entre: 50 - 400) ", "Error....Reingrese cantidad de horas trabajadas: ", 49,400);
			 employee_setHorasTrabajadas(employeeNew, horasTrabajadas);

			 ll_add(pArrayListEmployee, employeeNew);

			 controller_guardarIdSig(id);

			 printf("Lista de empleados actualizada: ");
			 controller_ListEmployee(pArrayListEmployee);

		}

	}


    return error;
}



/** \brief Modificar datos de empleado
 * \param pArrayListEmployee LinkedList* lista de empleados de tipo estructura LinkedList
 * \return int retorna 1 si hubo error y 0 si no hubo error
 *
 */

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int error = -1;
	int id;
	int index;
	char confirm;
	char nombre[60];
	int sueldo;
	int horasNuevasTrab;
	Employee* employeeEdit;


	if(pArrayListEmployee != NULL)
	{

		system("cls");

		printf("--------------------------------------------------------------\n");
		printf("                        MODIFICAR EMPLEADOS                       \n");
		printf("--------------------------------------------------------------\n");

		//len = ll_len(pArrayListEmployee);

		//printEmployees(pArrayListEmployee, len);
		controller_ListEmployee(pArrayListEmployee);
		printf("Ingrese ID del empleado que desea modificar: ");
		scanf("%d", &id);

		index = findEmployeeById(pArrayListEmployee, id);


		if(index == -1)
		{
			printf("\nNo existe un empleado con ese ID...\n");
		}
		else
		{
			employeeEdit = ll_get(pArrayListEmployee, index);

			printEmployee(employeeEdit);


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

				switch (editEmployeeMenu()) {
					case 1:
						 pedirCadena(nombre, "Ingrese nombre del empleado: ", "Error....Reingrese nombre: ", 128);
						 firstLetterMayus(nombre);

						 validateLetters(nombre);
						 employee_setNombre(employeeEdit, nombre);

						printf("\n\nLista de empleados actualizada: ");
					    controller_ListEmployee(pArrayListEmployee);

						break;

					case 2:

						 getInteger(&horasNuevasTrab, "Ingrese cantidad de horas trabajadas: (entre: 50 - 400) ", "Error....Reingrese cantidad de horas trabajadas: ", 50,400);
						 employee_setHorasTrabajadas(employeeEdit, horasNuevasTrab);

						printf("\n\nLista de empleados actualizada: ");
						controller_ListEmployee(pArrayListEmployee);

						break;

					case 3:
						 getInteger(&sueldo, "Ingrese monto de sueldo (entre: 1000 - 600000): ", "Error al ingresar sueldo....Reintentelo: ", 1000, 600000);
						 employee_setSueldo(employeeEdit, sueldo);

						printf("\n\nLista de empleados actualizada: ");
					    controller_ListEmployee(pArrayListEmployee);

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



/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* lista de empleados donde se encontrararan registrados, de tipo estructura LinkedList
 * \return int retorna 0 si no hubo error y 1 si hubo error
 *
 */

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int error = -1;
	int index;
	char confirm;
	int len;
	int id;
	Employee* employeeRemoved;

	if(pArrayListEmployee != NULL)
	{
		len =ll_len(pArrayListEmployee);

		if(len > 0)
		{
			printf("--------------------------------------------------------------\n");
			printf("                        BAJA EMPLEADOS                       \n");
			printf("--------------------------------------------------------------\n\n");

			//printEmployees(pArrayListEmployee, len);
			controller_ListEmployee(pArrayListEmployee);

			printf("Ingrese ID del empleado que desea dar de baja: ");
			scanf("%d", &id);

			index = findEmployeeById(pArrayListEmployee, id);


			if(index == -1)
			{
				printf("\nNo existe un empleado con ese ID...\n");
			}
			else
			{
				employeeRemoved = ll_get(pArrayListEmployee, index);
				printEmployee(employeeRemoved);

				printf("\n¿Desea confirmar la baja de empleado? (s/n)");
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
					ll_remove(pArrayListEmployee, index);
					employee_delete(employeeRemoved);

					printf("Lista de empleados actualizada: \n\n");
					controller_ListEmployee(pArrayListEmployee);
					error = 0;
				}
				else
				{
					printf("\nSe ha cancela la baja de empleado...\n");
				}
			}
		}

	}

	return error;
}


/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* lista de empleados de tipo estructura de LinkedList
 * \return int retorna 0 si no hubo  errores y 1 si hubo error
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int error = 1;
	int flag = 1;
	int len;
	Employee* employeeAux;

	if(pArrayListEmployee != NULL)
	{

		 printf("\n                                  LISTA DE EMPLEADOS                             \n");
		 printf(" -------------------------------------------------------------------------------\n");
		 printf("     ID          NOMBRE             HORAS TRABAJADAS           SUELDO          \n");
		 printf(" --------------------------------------------------------------------------------\n\n");



		// employeeAux = employee_new();

		 len = ll_len(pArrayListEmployee);



		 if(len > 0)
		 {
				for(int i = 0; i < len; i++)
				{

					employeeAux = ll_get(pArrayListEmployee, i);

					printEmployee(employeeAux);
					flag = 0;
					printf("\n");
				}
				//printf("\n\n");

				if(flag == 1)
				{
					printf("No existen empleados para mostrar.\n");
					error = 1;
				}

				error = 0;
		 }

	}

    return error;
}



/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* listado de empleados de tipo estructura LinkedList
 * \return int retorna 0 si no hubo error y 1 si hubo error
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int error = 1;
	int orden;
	LinkedList* listCopy;

	if(pArrayListEmployee != NULL)
	{
		listCopy = ll_clone(pArrayListEmployee);

		if(listCopy != NULL)
		{
			if(ll_len(listCopy) > 0)
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

					//LLAMO A LL_SORT CON SU CRITERIO DE ORDENAMIETNO , LO GUARDO EN VARIABLE, SEGUN ESA VARIABLE HAGO QUE SE ORDENE DE UNA FORMA U OTRA
					printf("\nESPERE UNOS MINUTOS...EL ORDENAMIENTO ESTA SIENDO PROCESADO....\n");
					ll_sort(listCopy, sortByName, orden);
					controller_ListEmployee(listCopy);
					break;

				case 2:
					printf("\nQuiere ordenar de forma ascendente(1) o descendente(0)?: ");
					scanf("%d", &orden);
					while(orden != 0 && orden != 1)
					{
						printf("Error al ingresar forma de ordenamiento....Reintentelo nuevamente: ");
						scanf("%d", &orden);
					}

					printf("\nESPERE UNOS MINUTOS...EL ORDENAMIENTO ESTA SIENDO PROCESADO....\n");

					ll_sort(listCopy, sortById, orden);
					controller_ListEmployee(listCopy);
					break;

				case 3:
					printf("\nQuiere ordenar de forma ascendente(1) o descendente(0)?: ");
					scanf("%d", &orden);
					while(orden != 0 && orden != 1)
					{
						printf("Error al ingresar forma de ordenamiento....Reintentelo nuevamente: ");
						scanf("%d", &orden);
					}

					printf("\nESPERE UNOS MINUTOS...EL ORDENAMIENTO ESTA SIENDO PROCESADO....\n");

					ll_sort(listCopy, sortByHorasTrab, orden);
					controller_ListEmployee(listCopy);
					break;
				case 4:
					printf("\nQuiere ordenar de forma ascendente(1) o descendente(0)?: ");
					scanf("%d", &orden);
					while(orden != 0 && orden != 1)
					{
						printf("Error al ingresar forma de ordenamiento....Reintentelo nuevamente: ");
						scanf("%d", &orden);
					}

					printf("\nESPERE UNOS MINUTOS...EL ORDENAMIENTO ESTA SIENDO PROCESADO....\n");

					ll_sort(listCopy, sortBySueldo, orden);
					controller_ListEmployee(listCopy);
					break;

				case 5:
					printf(" ");
					break;

				default:
					printf("Opcion invalida... Reintentelo nuevamente. ");
					break;
				}//cierre switch

				error = 0;
			}
		}


	}

    return error;
}





/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* direccion del archivo del documento
 * \param pArrayListEmployee LinkedList* lista de empleados de tipo puntero a estructura
 * \return int retorna 0 si no hubo error y 1 si hubo error
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int error = 1;
	FILE* pFile;
	Employee* employee;
	char name[128];
	int id;
	int sueldo;
	int horasTrab;


	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "w");

		if(pFile == NULL)
		{
			printf("Error al abrir el archivo de texto...\n");
			error = 1;
			exit(1);
		}
		else
		{

			employee = employee_new();

			fprintf(pFile,"id, nombre, horasTrabajadas, sueldo\n");

			for(int i = 0; i < ll_len(pArrayListEmployee); i++)
			{

				employee = (Employee*)ll_get(pArrayListEmployee, i);


				if(employee != NULL)
				{

					employee_getNombre(employee, name);
					employee_getId(employee, &id);
					employee_getSueldo(employee, &sueldo);
					employee_getHorasTrabajadas(employee, &horasTrab);


					fprintf(pFile, "%d, %s, %d, %d\n", id, name, horasTrab, sueldo);
					error = 0;
				}
				else
				{

					error = 1;
					break;
				}
			}
			printf("ARCHIVOS DE TEXTO GUARDADOS CON EXITO...\n");
			fclose(pFile);
		}

	}

    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* direccion del archivo
 * \param pArrayListEmployee LinkedList* lista de empleados de tipo puntero a estructura
 * \return int retorna 0 si no hubo error y 1 si hubo error
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int error = 1;
	FILE* pFile;
	Employee* employee;

	if(path != NULL && pArrayListEmployee != NULL)
	{

		pFile = fopen(path, "wb");

		if(pFile == NULL)
		{
			printf("Error al abrir archivo...\n");
			error = 1;
			exit(1);

		}
		else
		{
			employee = employee_new();

			if(employee != NULL)
			{

				for(int i = 0; i < ll_len(pArrayListEmployee); i++)
				{
					employee = ll_get(pArrayListEmployee, i);

					fwrite(employee, sizeof(Employee), 1, pFile);
				}


				error = 0;
			}
			fclose(pFile);
		}



	}
    return error;
}

