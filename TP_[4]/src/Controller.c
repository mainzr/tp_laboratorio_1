#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "../inc/Controller.h"
#include "../inc/Employee.h"
#include "../inc/parser.h"
#include "../inc/inputs.h"

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
    printf("2. Alta de empleado\n");
    printf("3. Buscar empleado con: mayor sueldo y horas trabajadas.\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Menu de ELIMINACIONES.\n");
    printf("10. Crear nueva lista de empleados\n");
    printf("11. Salir\n\n");



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
		//index = ll_indexOf(pArrayListEmployee, &id);

		if(index == -1)
		{
			printf("\nNo existe un empleado con ese ID...\n");
		}
		else
		{
			employeeEdit = ll_get(pArrayListEmployee, index);

			printEmployees(employeeEdit);


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

				if(ll_contains(pArrayListEmployee, employeeRemoved) == 1)
				{
					printf("\nEL EMPLEADO SE ENCUENTRA ACTUALMENTE ACTIVO....\n");
					printEmployees(employeeRemoved);
					printf("\n\nConfirme si...");
				}
				else
				{
					printf("NO SE ENCUENTRA UN EMPLEADO EN NUESTRO SISTEMA ACTUALMENTE ACTIVO....\n");
				}


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

					printEmployees(employeeAux);
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



int controller_mayorSueldoHoras(LinkedList* pArrayListEmployee)
{
	int error = -1;
	int flag = 0;
	int mayorHoras;
	Employee* auxEmp;
	int sueldoMax;
	int indiceEncontrado;


	if(pArrayListEmployee != NULL)
	{

		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
	        auxEmp =  ll_get(pArrayListEmployee, i);

			if(flag == 0 || (mayorHoras < auxEmp->horasTrabajadas && sueldoMax < auxEmp->sueldo))
			{
				mayorHoras = auxEmp->horasTrabajadas;
				sueldoMax = auxEmp->sueldo;

				flag = 1;
			}
		}//cierre for

		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			auxEmp = ll_get(pArrayListEmployee, i);

			if(mayorHoras == auxEmp->horasTrabajadas && sueldoMax == auxEmp->sueldo)
			{
				indiceEncontrado = ll_indexOf(pArrayListEmployee, auxEmp);
				break;
			}
		}
	      auxEmp = ll_pop(pArrayListEmployee, indiceEncontrado); //se borra empleado

	      printEmployees(auxEmp);

	      printf("\n\nEmpleado con mayor sueldo y horas trabajadas encontrado exitosamente...\n");

	      employee_delete(auxEmp);
	}

	return error;
}



int controller_listNuevosEmployees(LinkedList* pArrayEmployee)
{
	int error = 1;
	int idInicial;
	int idFinal;
	int indiceInicial;
	int indiceFinal;
	LinkedList* newList;
	char confirm;
	char confirmDos;
	int newId;
	int index;
	Employee* auxEmp;


	if(pArrayEmployee != NULL)
	{
		controller_ListEmployee(pArrayEmployee);

		printf("\nDesde que ID desea que se cree la nueva lista?: ");
		scanf("%d", &idInicial);

		printf("Hasta que ID desea que se cree la nueva lista?: ");
		scanf("%d", &idFinal);

		indiceInicial = findEmployeeById(pArrayEmployee, idInicial);
		indiceFinal = findEmployeeById(pArrayEmployee, idFinal);

		if(indiceFinal != -1 && indiceInicial != -1)
		{
			newList = ll_subList(pArrayEmployee, indiceInicial, idFinal);
		}
		else
		{
			printf("\nOcurrio un error...\n");
		}

		if(newList != NULL)
		{
			printf("\nSU NUEVA LISTA DE EMPLEADOS HA SIDO CREADA....\n");
			controller_ListEmployee(newList);

			printf("\nLe gustaria agregar un empleado mas a su nueva lista? (s/n): ");
			fflush(stdin);
			scanf("%c", &confirm);
			if(validateChar(confirm, 's', 'n'))
			{
				printf("Opcion incorrecta...Reintentelo nuevamente: ");
				fflush(stdin);
				scanf("%c", &confirm);
			}

			if(confirm == 'n')
			{
				printf("No se añadiran mas empleados a su lista....\n");
				error = 0;

			}
			else
			{
				controller_ListEmployee(pArrayEmployee);
				printf("Ingrese el ID del empleado que desea agregar a su nueva lista: ");
				scanf("%d", &newId);

				index = findEmployeeById(pArrayEmployee, newId);

				if(index == -1)
				{
					printf("Ocurrio un error.....\n");
				}
				else
				{
					auxEmp = ll_get(pArrayEmployee, index);
					if(ll_push(newList, ll_len(newList), auxEmp) == -1)
					{
						printf("Ocurrio un problema al agregar el nuevo empleado....\n");
					}
					else
					{
						printf("\nEl empleado fue agregado con exito...\n");
						printf("\nLISTA ACTUALIZADA CON EXITO...\n");
						controller_ListEmployee(newList);


						printf("\n----------------------------------------------------------------------\n");
						printf("Desea verificar si ambas listas contienen los mismos empleados? (s/n): ");
						fflush(stdin);
						scanf("%c", &confirmDos);
						if(validateChar(confirmDos, 's', 'n'))
						{
							printf("Opcion incorrecta...Reintentelo nuevamente: ");
							fflush(stdin);
							scanf("%c", &confirmDos);
						}

						if(confirm == 'n')
						{
							printf("Se cancelo con exito la verificacion...\n");
						}
						else
						{
							if(ll_containsAll(pArrayEmployee ,newList) == 1)
							{

								printf("\n-----------------------------------------------------------------------\n");
								printf("    SE LE INFORMA QUE AMBAS LISTAS CONTIENEN EMPLEADOS DISTINTOS...\n");
								printf("-----------------------------------------------------------------------\n\n");

							}
							else
							{
								if(ll_containsAll(pArrayEmployee ,newList) == 0)
								{
									printf("\n-----------------------------------------------------------------------\n");
									printf("     LE CONFIRMAMOS QUE AMBAS LISTAS CONTIENEN LOS MISMOS EMPLEADOS...\n");
									printf("-----------------------------------------------------------------------\n\n");
								}
								else
								{
									printf("\nOCURRIO UN ERROR....\n\n");
								}
							}

						}
					}
				}

			}

		}

		error = 0;
	}

	return error;
}


int controller_eliminarCompletamente(LinkedList* pArrayEmployee)
{
	int error = 1;
	char confirm;
	int opcion;

	printf("\n----------------------------------------------------------------\n");
	printf("    PELIGRO: USTED ESTA EN EL SECTOR DE ELIMINACION DE DATOS\n");
	printf("----------------------------------------------------------------\n\n");


	printf("1. Eliminar empleados de la lista\n");
	printf("2. Eliminar empleados de la lista y la lista.\n\n");

	printf("Elija la opcion de eliminacion que desee: ");
	scanf("%d", &opcion);

	switch(opcion)
	{
	   case 1:
			printf("\n¿Esta seguro que desea ELIMINAR TODOS LOS EMPLEADOS DE LA LISTA?(s/n): ");
			fflush(stdin);
			scanf("%c", &confirm);
			if(validateChar(confirm, 's', 'n'))
			{
				printf("Opcion incorrecta...Reintentelo nuevamente: ");
				fflush(stdin);
				scanf("%c", &confirm);
			}

			if(confirm == 'n')
			{
				printf("SE HA CANCELADO LA ELIMINACION COMPLETA DE DATOS....\n");
			}
			else
			{
			   if(ll_clear(pArrayEmployee) == -1)
			   {
				   printf("Ocurrio un error en la eliminacion...\n");
			   }
			   else
			   {
				   printf("\nELIMINACION EXITOSA.\n");
				   error = 0;
			   }
			}


		   break;
	   case 2:
			printf("\n¿Esta seguro que desea ELIMINAR TODOS LOS EMPLEADOS DE LA LISTA y LA LISTA?(s/n): ");
			fflush(stdin);
			scanf("%c", &confirm);
			if(validateChar(confirm, 's', 'n'))
			{
				printf("Opcion incorrecta...Reintentelo nuevamente: ");
				fflush(stdin);
				scanf("%c", &confirm);
			}

			if(confirm == 'n')
			{
				printf("SE HA CANCELADO LA ELIMINACION COMPLETA DE DATOS....\n");
			}
			else
			{
			   if(ll_deleteLinkedList(pArrayEmployee) == -1)
			   {
				   printf("\nOcurrio un error...\n");
			   }
			   else
			   {
				   printf("\nELIMINACION EIXTOSA!\n");
				   error = 0;
			   }
			}
		   break;

	}

	return error;
}





