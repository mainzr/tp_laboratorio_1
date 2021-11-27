/*
 * ArrayEmployees.h
 *
 *  Created on: 26 nov. 2021
 *      Author: MAIA
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
/**
 * @struct  estructura que contiene todos los campos de cada empleado
 * @brief tipos de dato que tendra cada empleado ingresado
 *
 */
typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}eEmployee;


#endif /* ARRAYEMPLOYEES_H_ */

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(eEmployee* list, int len);
/**
 * @fn int searchFree(eEmployee[], int)
 * @brief busca si hay un lugar libre en vector list
 *
 * @param list vector que sera recorrido y donde se almacenaran los daton ingresados
 * @param len tamaño maximo que tendra el vector list
 * @return retorna 0 en caso de no haber error y -1 en caso de error
 */
int searchFree(eEmployee list[], int len);
/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee* lugar donde se almacenaran empleados inrgesados
* \param len int tamaño que tendra list
* \param id int id dde cada empleado
* \param name[] char mnombre de cada empleado
* \param lastName[] char apellido de cada empleado
* \param salary float salario de cada empelado
* \param sector int sector de cada empleado
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addEmployees(eEmployee* list, int len, int id, char name[], char lastName[], float salary, int sector);
/**
 * @fn int findEmployeeById(eEmployee*, int, int)
 * @brief busca un empleado segun su id deseado
 *
 * @param list vector que sera recorrido para poder encontrar id deseado
 * @param len tamaño del vector
 * @param id id del empleado que se desea encontrar
 * @return retorna 0 en caso de no haber error y -1 en caso de error
 */
int findEmployeeById(eEmployee* list, int len, int id);
/**
 * @fn void printEmployee(eEmployee)
 * @brief imprime en forma de lista a un empleado
 *
 * @param oneEmployee informacion de un empleado que sera mostrado con sus respectivos campos
 */
void printEmployee(eEmployee oneEmployee);
/**
 * @fn int printEmployees(eEmployee*, int)
 * @brief imprimira una lista en forma de columnas de empleados
 *
 * @param list vector que tendra todos los empleados ingresados
 * @param length tamaño que tendra el vector list
 * @return retorna 0 en caso de que no haya error y -1 en caso de error
 */
int printEmployees(eEmployee* list, int length);
/**
 * @fn int removeEmployee(eEmployee*, int, int)
 * @brief da de baja un empleado segun su id
 *
 * @param list vector donde sera almacenado todos los empleados ingresados
 * @param len tamaño que tendra el vector list
 * @param id variable que indicara cada empleado segun su id
 * @return retorna 0 en caso de que no haya error y -1 en caso de error
 */
int removeEmployee(eEmployee* list, int len, int id);
/**
 * @fn int modifyEmployee(eEmployee*, int)
 * @brief permite modificar nombre, apellido, salario y sector de empleado deseado
 *
 * @param list vector donde se encontraran almacenado todos los empleados
 * @param len tamaño que tendra el vector list
 * @return retorna 0 en caso de que no haya error y -1 en caso de error
 */
int modifyEmployee(eEmployee* list, int len);
/**
 * @fn int inform(eEmployee*, int)
 * @brief informa los empleados dependiendo de como se desee
 *
 * @param list vector donde se encontraran empleados almacenados
 * @param len tamaño que tendra la variable list
 * @return retorna 0 en caso de que no haya error y -1 en caso de que haya error
 */
int inform(eEmployee* list, int len);
/**
 * @fn int sortEmployees(eEmployee*, int, int)
 * @brief realiza un burbujeo de los empleados dependiendo de como se desee
 *
 * @param list puntero donde se encontraran todos los empleados almacenados
 * @param len tamaño que tendra vector list
 * @param order citerio de orden que se debera cumplir para mostrar empleados de forma especifica
 * @return retorna 0 en caso de que no hay error y -1 en caso de que haya error
 */
int sortEmployees(eEmployee* list, int len, int order);
/**
 * @fn int sortEmployeesTwo(eEmployee*, int)
 * @brief segunda opcion de ordenamiento
 *
 * @param list puntero donde se encontraran almacenados todos los empleados
 * @param len tamaño que tendra el vector list
 * @return retorna 0 en caso de no haber error y -1 en caso de haber error
 */
int sortEmployeesTwo(eEmployee* list, int len);


