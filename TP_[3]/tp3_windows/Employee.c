#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "LinkedList.h"


//-------employees' sets and gets-----//
/**
 * @fn int employee_setId(Employee*, int)
 * @brief asigna el valor del id
 *
 * @param this variable de tipo puntero a estructura empeados
 * @param id valor que tendra el id del empleado
 * @return retorna 0 si no hubo error y 1 si hubo error
 */

int employee_setId(Employee* this,int id)
{
	int error = 1;

	if(this != NULL)
	{
		this->id = id;
		error = 0;
	}

	return error;
}

/**
 * @fn int employee_getId(Employee*, int*)
 * @brief toma el valor desde la estructura de empleados
 *
 * @param this variable de tipo puntero a estructura empeados
 * @param id valor que tendra el id de variable de tipo puntero
 * @return retorna 0 si no hubo error y 1 si hubo error
 */
int employee_getId(Employee* this,int* id)
{
	int error = 1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		error = 0;
	}


	return error;
}


/**
 * @fn int employee_setNombre(Employee*, char*)
 * @brief asigna el valor del nombre
 *
 * @param this variable de tipo puntero a estructura empeados
 * @param nombre de tipo puntero a char que se obtendra de la estructura de empleados
 * @return retorna 0 si no hubo error y 1 si hubo error
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int error = 1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);

		error = 0;
	}


	return error;
}

/**
 * @fn int employee_getNombre(Employee*, char*)
 * @brief toma el valor del nombre desde el puntero a estructura
 *
 * @param this variable de tipo puntero a estructura empleados
 * @param nombre nombre que se obtendra de la estructura
 * @return retorna 0 si no hubo error y 1 si hubo error
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int error = 1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);

		error = 0;
	}

	return error;
}


/**
 * @fn int employee_setHorasTrabajadas(Employee*, int)
 * @brief puntero que apunta a la estructura
 *
 * @param this variable que apunta a la estructura de tipo empleado
 * @param horasTrabajadas valor que se le asignara a la estructura
 * @return retorna 0 si no hubo error y 1 si hubo error
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int error = 1;

	if(this != NULL && horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;

		error = 0;
	}

	return error;
}


/**
 * @fn int employee_getHorasTrabajadas(Employee*, int*)
 * @brief obtiene el valor de las horas trabajadas de la estructura empleados
 *
 * @param this variable de tipo puntero a estructura
 * @param horasTrabajadas variable que obtendra el valor de las horas trabajdas desde la estructura
 * @return devuelve 0 si no hubo error y 1 si hubo error
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int error = 1;

	if(this != NULL && horasTrabajadas != NULL)

	{
		*horasTrabajadas = this->horasTrabajadas;

		error = 0;
	}

	return error;
}

/**
 * @fn int employee_setSueldo(Employee*, int)
 * @brief guarda el valor del sueldo en la estructura empleados
 *
 * @param this variable de tipo puntero a estructura
 * @param sueldo valor del sueldo que se guardara en la estructura
 * @return retorna 0 si no hubo error y 1 si hubo error
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int error = 1;

	if(this != NULL && sueldo > 0)
	{
		this->sueldo = sueldo;

		error = 0;
	}

	return error;
}

/**
 * @fn int employee_getSueldo(Employee*, int*)
 * @brief se obtiene el valor del sueldo desde la estructura emleado
 *
 * @param this variable de tipo puntero a estructura
 * @param sueldo valor del sueldo que se obtendra desde la estructura
 * @return retorna 0 si no hubo error y 1 si hubo error
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int error = 1;

	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;

		error = 0;
	}

	return error;
}

/**
 * @fn Employee employee_new*()
 * @brief agrega un nuevo empleado
 *
 * @return retorna el nuevo empleado con sus valores inicializados
 */
Employee* employee_new()
{
    Employee* newEmployee;

    newEmployee = (Employee*) malloc(sizeof(Employee));

    if(newEmployee != NULL)
    {
    	newEmployee->id = 0;
        strcpy(newEmployee->nombre, " ");
        newEmployee->horasTrabajadas = 0;
        newEmployee->sueldo = 0;
    }

    return newEmployee;
}

/**
 * @fn Employee employee_newParametros*(char*, char*, char*, char*)
 * @brief guarda un nuevo empleado pasandole los datos por parametro
 *
 * @param idStr id que tendra el nuevo empleado
 * @param nombreStr nombre que tendra el nuevo empleado de tipo puntero a cadena
 * @param horasTrabajadasStr valor de las horas trabajadas de tipo puntero a cadena
 * @param sueldoStr valor que tendra el sueldo de tipo puntero a char
 * @return retorna el nuevo empleado cargado con sus valores
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* newEmployee;

    newEmployee = employee_new();

    if(newEmployee != NULL)
    {
        if((employee_setId(newEmployee, atoi(idStr))
           || employee_setNombre(newEmployee, nombreStr)
		   || employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr))
           || employee_setSueldo(newEmployee, atoi(sueldoStr))))
           {
                free(newEmployee);
                newEmployee = NULL;
           }
    }
    return newEmployee;
}


/**
 * @fn void employee_delete(Employee*)
 * @brief elimina un empleado a seleccionar
 *
 * @param this varible de tipo puntero a estructura empleados
 */
void employee_delete(Employee* this)
{
	free(this);
}

/**
 * @fn void printEmployee(Employee*)
 * @brief imprimi por consola un empleado
 *
 * @param oneEmployee variable de tipo puntero a estructura
 */
void printEmployee(Employee* oneEmployee)
{
	if(oneEmployee != NULL)
	{
		char nombre[50];
		int id;
		int sueldo;
		int horasTrabajadas;


		employee_getId(oneEmployee, &id);
		employee_getNombre(oneEmployee, nombre);
		employee_getHorasTrabajadas(oneEmployee, &horasTrabajadas);
		employee_getSueldo(oneEmployee, &sueldo);


		printf("    %-10d     %-20s    %-11d     $ %-12d",
				id, nombre, horasTrabajadas,  sueldo );
	}


}

/**
 * @fn int findEmployeeById(LinkedList*, int)
 * @brief encuentra un empleado por su id
 *
 * @param list variable de tipo puntero a estructura
 * @param id id que tendra el empleado
 * @return retorna el id que tenga el empleado encontrado
 */
int findEmployeeById(LinkedList* list,  int id)
{

	int idFound = -1;
	Employee* indice;
	int idRetornado;


	if(list != NULL)
	{
		for(int i = 0; i < ll_len(list); i++)
		{

			indice = ll_get(list, i);

			if(indice != NULL)
			{
				employee_getId(indice, &idRetornado);

				if(idRetornado == id)
				{
					idFound = i; //retorna indice, si falla retorna -1
				}
			}

		}
	}

	return idFound;
}

// Sorts
/**
 * @fn int sortBySueldo(void*, void*)
 * @brief ordena la lista de empleados  sueldo
 *
 * @param firstElement variable de tipo puntero a void del primer elemento a comparar
 * @param secondElement variable de tipo puntero a void del segundo elemento a comparar
 * @return retorna 1 si hubo error y 0 si no hubo error
 */
int sortBySueldo(void* firstElement, void* secondElement)
{
	Employee* first;
	Employee* second;
	int error = 0;
	int firstSueldo;
	int secondSueldo;

	first = (Employee*) firstElement;
	second = (Employee*) secondElement;

	if(first != NULL && second != NULL)
	{
		if(employee_getSueldo(first, &firstSueldo) == 0  && employee_getSueldo(second, &secondSueldo) == 0)
		{
			if(firstSueldo > secondSueldo)
			{
				error = 1;
			}
			else
			{
				if(firstSueldo < secondSueldo)
				{
					error = -1;
				}
			}
		}
	}




	return error;
}

/**
 * @fn int sortByHorasTrab(void*, void*)
 * @brief ordena la lista de empleados por horas trabajadas
 *
 * @param firstElement primer elemento que se comparara
 * @param secondElement segundo elemento que se comparara
 * @return retorna 1 si hubo error y 0 si no hubo error
 */
int sortByHorasTrab(void* firstElement, void* secondElement)
{
	Employee* first;
	Employee* second;
	int error = 0;
	int firstHoras;
	int secondHoras;

	first = (Employee*) firstElement;
	second = (Employee*) secondElement;

	if(first != NULL && second != NULL)
	{

		if(employee_getHorasTrabajadas(first, &firstHoras) == 0  && employee_getHorasTrabajadas(second, &secondHoras) == 0)
		{
			if(firstHoras > secondHoras)
			{
				error = 1;
			}
			else
			{
				if(firstHoras < secondHoras)
				{
					error = -1;

				}
			}

		}

	}



	return error;
}

/**
 * @fn int sortById(void*, void*)
 * @brief ordena los empleados comparando por sus Ids
 *
 * @param firstElement primero elemento que se comparara
 * @param secondElement segundo elemento que se comparara
 * @return retorna 1 si hubo error y 0 si no hubo error
 */
int sortById(void* firstElement, void* secondElement)
{
	Employee* first;
	Employee* second;
	int error = 0;
	int firstId;
	int secondId;

	first = (Employee*) firstElement;
	second = (Employee*) secondElement;

	if(first != NULL && second != NULL)
	{

		if(employee_getId(first, &firstId) == 0  && employee_getId(second, &secondId) == 0)
		{
			if(firstId > secondId)
			{
				error = 1;
			}
			else
			{
				if(firstId < secondId)
				{
					error = -1;

				}
			}
		}

	}

	return error;
}

/**
 * @fn int sortByName(void*, void*)
 * @brief ordena los empleados de maneara alfabeticamente
 *
 * @param firstElement primer elemento que se comparara
 * @param secondElement segundo element a comparar
 * @return retorna 1 si hubo error y 0 si no hubo error
 */
int sortByName(void* firstElement, void* secondElement)
{
	Employee* first;
	Employee* second;
	int error = 0;
	char firstName[128];
	char secondName[128];

	first = (Employee*) firstElement;
	second = (Employee*) secondElement;

	if(first != NULL && second != NULL)
	{

		if(employee_getNombre(first, firstName) == 0  && employee_getNombre(second, secondName) == 0)
		{
			if(strcmp(firstName, secondName) > 0)
			{
				error = 1;
			}
			else
			{
				if(strcmp(firstName, secondName) < 0)
				{
					error = -1;

				}
			}
		}
	}
	return error;
}



