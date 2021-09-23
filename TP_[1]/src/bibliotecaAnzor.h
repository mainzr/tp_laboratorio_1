/*
 * bibliotecaAnzor.h
 *
 *  Created on: 18 sep. 2021
 *      Author: MAIA
 */

#ifndef BIBLIOTECAANZOR_H_
#define BIBLIOTECAANZOR_H_

//-------------PROTOTIPOS------------------------
/**
 * @fn int menu(int, int, int, int)
 * @brief muestra las opciones que podra elegir el usuario
 *
 * @param banderaPrimerIngreso indica si se ingreso el primer operando
 * @param x primer numero ingresado
 * @param banderaSegundoIngreso indica si se ingreso el segundo operando
 * @param y segundo numero ingresado
 * @return retorna la opcion elegida por usuario
 */
int menu(int banderaPrimerIngreso, int x, int banderaSegundoIngreso, int y);

/**
 * @fn int sumar(int, int)
 * @brief calcula la suma de dos numeros
 *
 * @param x primer numero ingresado
 * @param y segundo numero ingresado
 * @return retorna la suma de x e y
 */
int sumar(int x, int y);

/**
 * @fn int restar(int, int)
 * @brief calcula la resta entre dos numeros
 *
 * @param x primer numero ingresado
 * @param y segundo numero ingresado
 * @return retorna la resta entre x e y
 */
int restar(int x, int y);

/**
 * @fn int dividir(int, int, float*)
 * @brief realiza la division entre dos numeros
 *
 * @param x primer numero ingresado
 * @param y segundo numero ingresado
 * @param division
 * @return retorna si hubo o no un errror al realizar la operacion
 */
int dividir(int x, int y, float* division);

/**
 * @fn int multiplicar(int, int)
 * @brief realiza la multiplicacion entre dos numeros
 *
 * @param x primer numero ingresado
 * @param y segundo numero ingresado
 * @return retorna la multiplicacion de x e y
 */
int multiplicar(int x, int y);

/**
 * @fn int factorial(int, int*)
 * @brief calcula el factorial de dos numeros
 *
 * @param x numero del que se calculara el factorial
 * @param rtaFactorial varible en donde se almacenara el resultado
 * @return retorna si hubo o no un error al realizar la operacion
 */
int factorial(int x, int* rtaFactorial);

/**
 * @fn int hacerOperaciones(int, int, int*, int*, int*, int*, int*, int*, int*, int*, float*)
 * @brief realiza todas las operaciones aritmeticas
 *
 * @param x primer numero ingresado por usuario
 * @param y segundo numero ingresado por usuario
 * @param respuestaSuma puntero que llamara a la funcion sumar
 * @param respuestaResta puntero que llamara a la funcion restar
 * @param respuestaMultiplicacion puntero que llamara a la funcion multiplicar
 * @param errorA puntero que llamara a la funcion para ver si hubo o no un error al calcular el factorial del primer operando
 * @param errorB puntero que llamara a la funcion para ver si hubo o no un error al calcular el factorial del segundo operando
 * @param errorDiv puntero que llamara a la funcion dividir, retornara si hubo o no un error al hacer la operacion
 * @param respuestaFactorialA direccin de memoria donde se almacenara el resultado del factorial A
 * @param respuestaFactorialB direccion de memoria donde se almacenara el resultado del factorial B
 * @param respuestaDivision direccion de memoria donde se almacenara el resultado del la division
 * @return retorna si hubo o no hubo un error al realizar las operaciones
 */
int hacerOperaciones(int x, int y, int* respuestaSuma, int* respuestaResta, int* respuestaMultiplicacion, int* errorA, int* errorB, int* errorDiv, int* respuestaFactorialA, int* respuestaFactorialB, float* respuestaDivision);

/**
 * @fn void informarResultados(int, int, int, int, int, int, int, int, int, int, float)
 * @brief informa el resultado que dara cada operacion
 *
 * @param x primer numero ingresado
 * @param y segundo numero ingresado
 * @param suma direccion de memoria donde se almaceno el resultado de la operacion suma
 * @param resta direccion de memoria en donde se almaceno el resultado de la resta anteriormente
 * @param multiplicacion direccion de memoria en donde se  almaceno el resultado de la multiplicacion anteriormente
 * @param errorFactA direccion de memoria en donde se almaceno anteriormente si hubo o no error al realizar el factorial de A
 * @param errorFactB direccion de memoria donde se almaccceno anteriormente si hubo o no hubo error al calcular el factorial de B
 * @param errorDiv direccion de memoria en donde se almaceno anteriormente si hubo o no hubo error al calcular la division
 * @param respuestaFactorialA resultado de la operacion factorial del primer operador
 * @param respuestaFactorialB resultado de la operacion factoria del segundo operador
 * @param respuestaDivision resultado de la operacion dividir
 */
void informarResultados(int x, int y, int suma, int resta, int multiplicacion, int errorFactA, int errorFactB, int errorDiv, int respuestaFactorialA, int respuestaFactorialB, float respuestaDivision);



#endif /* BIBLIOTECAANZOR_H_ */
