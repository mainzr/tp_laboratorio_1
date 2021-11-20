/*
 * inputs.c
 *
 *  Created on: 12 nov. 2021
 *      Author: MAIA
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../inc/inputs.h"

/**
 * @fn int firstLetterMayus(char[])
 * @brief cambia el primer caracter de un string a mayuscula
 *
 * @param name variable que verificara
 * @return
 */
int firstLetterMayus(char name[]){

	int i = 0;
	int error = -1;

	if(name != NULL)
	{
		strlwr(name);
		name[0] = toupper(name[0]);

		while(name[i] != '\0')
		{
		         if(name [i] == ' '){
		        	 name [i + 1] = toupper(name[i+1]);
		         }

		        i++;
		 }
		    //puts(name);

	  error = 0;
	}
    return error;
}

/**
 * @fn int pedirCadena(char*, char*, char*, int)
 * @brief pide una cadena, valida y muestra mensaje en caso de error
 *
 * @param cadena valor que se ingresara de tipo cadena de caracteres
 * @param mensaje mensaje que se mostrara para al pedir el string
 * @param mensajeError mensaje de error que se mostrara en caso de que no se cumpla alguna condicion
 * @param max maxima cantidad de caracteres que se pueden ingresar
 * @return retorna 1 en caso de herror y 0 si no hubo error
 */
int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max)
{
	int error = 1;
	char buffer[256];
	int tam;

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && max > 0)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);
		tam = strlen(buffer);

		while(tam > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%[^\n]", buffer);
			tam = strlen(buffer);
		}

		strcpy(cadena, buffer);
		error = 0;
	}

	return error;
}

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
int getInteger(int* number, char* message, char* errorMessage, int minNumber, int maxNumber)
{
	int error = -1;
	int auxInt;

	if(message != NULL && errorMessage != NULL )
	{
		printf("%s", message);
		scanf("%d", &auxInt);

		while(auxInt <= minNumber || auxInt >= maxNumber)
		{
			printf("%s", errorMessage);
			scanf("%d", &auxInt);
		}

		*number = auxInt;

		error = 0;
	}

    return error;
}

/**
 * @fn int validateChar(char, char, char)
 * @brief valida el ingreso de una variable que  sea solo de dos tipos
 *
 * @param character caracter ingresado
 * @param firstOption primer opcion que podra ser el caracter
 * @param secondOption segunda opcion que podra ser el caracter
 * @return retorna 0 en caso de que no haya error y -1 en caso de error
 */
int validateChar(char character, char firstOption, char secondOption)
{
    int error = -1;

    if(character == firstOption || character == secondOption)
    {
    	error = 0;
    }

    return error;
}

/**
 * @fn int validateLetters(char[])
 * @brief Funcion valida que solo se ingresen letras, y que no se puedan ingresar numeros
 *
 * @param string variable que va a ser verificada
 * @return retorna 0 si no hubo error y -1 si hubo error
 */
int validateLetters(char string[])
{
    int i = 0;
    int error = 0;

    if(string != NULL)
    {
        while(string[i] != '\0')
        {
            if(string[i] != ' ' && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z'))
            {
                error= -1;

                while(error < 0)
                {
                    printf("Ocurrio un error...Se debe ingresar letras unicamente: ");
                    fflush(stdin);
                    gets(string);
                    error = 0;
                    i = 0;
                }
            }
            i++;
        }
    }

    return error;
}
