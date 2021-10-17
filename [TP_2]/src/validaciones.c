/*
 * validaciones.c
 *
 *  Created on: 16 oct. 2021
 *      Author: MAIA
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "validaciones.h"
#include "menus.h"

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



int getFloat(float* number, char* message, char* errorMessage,float minNumber, float maxNumber)
{
	int error = -1;
	float auxFloat;

	if(message != NULL && errorMessage != NULL )
	{
		printf("%s", message);
		scanf("%f", &auxFloat);

		while(auxFloat <= minNumber || auxFloat >= maxNumber)
		{
			printf("%s", errorMessage);
			scanf("%f", &auxFloat);
		}

		*number = auxFloat;

		error = 0;
	}

	return error;
}


int getString(char* string, int len, char* message, char* errorMessage, int maxChar)
{
	int error = -1;
	char aux[200];

	//MOSTRAR MENSAJE
	//PEDIR VARIABLE
	//GUARDAR VALOR VARIABLE
	//VALIDAR STRING
	if(string != NULL && len > 0 && maxChar > 0)
	{
		printf("%s", message);
		fflush(stdin);
		gets(aux);
		firstLetterMayus(aux);
		len = strlen(aux);

		while(len > maxChar)
		{
			printf("%s", errorMessage);
			fflush(stdin);
			gets(aux);
			firstLetterMayus(aux);
			len = strlen(aux);
		}

		strcpy(string, aux);

		error = 0;
	}


	return error;
}


int validateChar(char character, char firstOption, char secondOption)
{
    int error = -1;

    if(character == firstOption || character == secondOption)
    {
    	error = 0;
    }

    return error;
}

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


int enterFloat(float number, float firtstLimit, float secondLimit)
{
    int error = -1;


    if(number >= firtstLimit && number <= secondLimit)
    {
    	error = 0;
    }


    return error;
}
