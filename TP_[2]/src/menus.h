/*
 * menus.h
 *
 *  Created on: 16 oct. 2021
 *      Author: MAIA
 */

#ifndef MENUS_H_
#define MENUS_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "validaciones.h"


#endif /* MENUS_H_ */
/**
 * @fn int menu()
 * @brief menu de opciones para alta, baja, modificar, informar y salir
 *
 * @return retorna la opcion elegida por el usuario
 */
int menu();
/**
 * @fn int modifyMenu()
 * @brief menu de opciones para modificar un empleado
 *
 * @return retorna la opcion de que se modificara en dicho empleado
 */
int modifyMenu();
/**
 * @fn int menuSortEmployees()
 * @brief menu de que indica de que forma se informara de los empleados
 *
 * @return returna la opcion 1 o 2 de como se informara los empleados
 */
int menuSortEmployees();
