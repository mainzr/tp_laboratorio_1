
#ifndef INPUTS_H_
#define INPUTS_H_



#endif /* INPUTS_H_ */
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
/**
 * @fn int validateLetters(char[])
 * @brief Funcion valida que solo se ingresen letras, y que no se puedan ingresar numeros
 *
 * @param string variable que va a ser verificada
 * @return retorna 0 si no hubo error y -1 si hubo error
 */
int validateLetters(char string[]);

/**
 * @fn int firstLetterMayus(char[])
 * @brief cambia el primer caracter de un string a mayuscula
 *
 * @param name variable que verificara
 * @return
 */
int firstLetterMayus(char name[]);
/**
 * @fn int getString(char*, int, char*, char*, int)
 * @brief
 *
 * @param string cadena de
 * @param len tamaño del vector
 * @param message mensaje que se mostrara para al pedir el string
 * @param errorMessage mensaje de error que se mostrara en caso de que no se cumpla alguna condicion
 * @param maxChar maxima cantidad de caracteres que se pueden ingresar
 * @return retorna -1 si hubo error y 0 si  no hubo error
 */
int getString(char* string, int len, char* message, char* errorMessage, int maxChar);
/**
 * @fn int getFloat(float*, char*, char*, float, float)
 * @brief ingreso y validacion de un numero de tipo flotante
 *
 * @param number numero que sera ingresado
 * @param message menaje que se mostrara al ingresar el numero
 * @param errorMessage menaje de error en caso de que no se cumpla alguna condicion
 * @param minNumber rango minino que debera cumplir el numero
 * @param maxNumber maximo numero que podra tener dicho numero
 * @return retorna 0 en caso de que no  haya error y -1 en caso de error
 */
//int getFloat(float* number, char* message, char* errorMessage,float minNumber, float maxNumber);
/**
 * @fn int getInteger(int*, char*, char*, int, int)
 * @brief valida el ingreso de un entero
 *
 * @param number numero entero que se ingresara
 * @param message mensaje que se mostrara antes de ingresar dicho numero
 * @param errorMessage mensaje de error que se mostrara  en caso de que no se cumpla alguna condicion
 * @param minNumber tamaño minimo que debera cumplir nuemro ingresado
 * @param maxNumber  tamaño maximo que debera cumpir numero ingresado
 * @return retorna 0 en caso de que no haya error y -1 en caso de error
 */
//int getInteger(int* number, char* message, char* errorMessage, int minNumber, int maxNumber);

/**
 * @fn int resetFlag(eEmployee*, int, int*)
 * @brief resetea la flag cada vez que no haya ningun empleado ingresado
 *
 * @param list lugar donde se almacenara todos los empleados ingresados
 * @param len tamaño que tendra el vector list
 * @param flag flag que se usa para decir si hay o no un empleado ingresado
 * @return retorna 0 en caso de no error y -1 en caso de error
 */
int resetFlag(eEmployee* list, int len, int* flag);
/**
 * @fn int enterFloat(float, float, float)
 * @brief verifica el limite que podra tener un numero flotante
 *
 * @param number numero ingresado que se verificara
 * @param firtstLimit minimo tamaño que se podra ingresar
 * @param secondLimit tamaño maximo que se podra ingresar
 * @return retorna 0 en caso de no error y -1 en caso de error
 */
int enterFloat(float number, float firtstLimit, float secondLimit);

int soloLetras(char name[]);

int validateChar(char character, char firstOption, char secondOption);

int esNumero(char *cadena);

int find(char buffer[], int tam);

int getInts(int *pNumResul);

int getInteger(int* numero, char* mensaje, char* mensajeError);

int esNumericoFlotante(char cadena[]);

int soloNumeros(char* num);

int soloFloat(float* number, char mensaje[], char mensajeError[], float min, float max);
