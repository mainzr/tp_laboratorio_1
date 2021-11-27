#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"



int menu()
{
	int option;

	printf("\n\n**************************************************\n");
	printf("                 AMB EMPLOYEES      \n");
	printf("**************************************************\n\n");

	printf(" 1. ALTAS EMPLEADOS\n");
	printf(" 2. MODIFICAR EMPLEADOS\n");
	printf(" 3. BAJA EMPLEADOS\n");
	printf(" 4. INFORMAR\n");
	printf(" 5. Salir\n\n");

	printf("Ingrese opcion deseada: ");
	scanf("%d", &option);


	return option;
}


int modifyMenu(){

	int option;

	printf("---------------------------------------------------------------------\n");
	printf("                         MENU DE MODIFICACIONES                      \n");
	printf("---------------------------------------------------------------------\n\n");

	printf(" 1. Nombre.\n");
	printf(" 2. Apellido\n");
	printf(" 3. Salario\n");
	printf(" 4. Sector\n\n");

	printf("Ingrese la opcion que desee modificar: ");
	scanf("%d", &option);

	return option;
}


int menuSortEmployees()
{
	int option;

	printf("---------------------------------------------------------------\n");
	printf("                       MENU DE INFORMES                    \n");
	printf("-----------------------------------------------------------------\n");

	printf("1. Informar empleados alfabeticamente por apelliodo y sector. \n");
	printf("2. Informar sueldo total, promedio y cantidad de empleados que superan promedio total.\n");
	printf("3. Volver al menu principal\n\n");

	printf("Elija opcion de que desea informar: ");
	scanf("%d", &option);


	return option;
}


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

	  error = 0;
	}
    return error;
}


int soloLetras(char name[])
{
    int i = 0;
    int todoOk;

    if(name != NULL)
    {
        while(name[i] != '\0')
        {
            if(!isalpha(name[i]) && name[i] != ' ')
            {
				todoOk = 0;

				while(todoOk == 0)
				{
					printf("\nError....Reingrese el dato, utilizando unicamente letras: ");
					fflush(stdin);
					gets(name);
					i = 0;
					todoOk = 1;
				}
            }
            i++;
        }
    }
    return todoOk;
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
		soloLetras(aux);
		validateLetters(aux);
		firstLetterMayus(aux);
		len = strlen(aux);

		while(len > maxChar)
		{
			printf("%s", errorMessage);
			fflush(stdin);
			gets(aux);
			soloLetras(aux);
			validateLetters(aux);
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



int enterFloat(float number, float firtstLimit, float secondLimit)
{
    int error = -1;


    if(number >= firtstLimit && number <= secondLimit)
    {
    	error = 0;
    }


    return error;
}

//-----

int esNumero(char *cadena)
{
    int error = 1;

    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[0] == '-')
        {
            i = 1;
        }
        if (cadena[i] > '9' || cadena[i] < '0')
        {
            error = 0;
            break;
        }
    }
    return error;
}


int find(char *cadena, int tam)
{
	char buffer[4096];

	fflush(stdin);
	scanf("%s", buffer);
	strncpy(cadena, buffer, tam);

	return -1;
}


int getInts(int *pNumResul)
{
    int error = 0;
    char buffer[4026];

    if (find(buffer, sizeof(buffer)) && esNumero(buffer))
    {
        error = 1;
        *pNumResul = atoi(buffer);
    }

    return error;
}




int getInteger(int* numero, char* mensaje, char* mensajeError)
{
    int error = -1;
    int buffer;
    //int error;

    if(numero != NULL && mensaje!= NULL && mensajeError!= NULL)
    {
        do
        {
            printf("%s ", mensaje);
            error = getInts(&buffer);

            if(error == 1)
            {
                *numero = buffer;
                error = 0;
                break;
            }
            else
            {
                printf("\n%s ", mensajeError);
            }

        } while(1);
    }
    return error;
}

//----------

int esNumericoFlotante(char cadena[])
{
    int i = 0;
    int cantidadPuntos = 0;

    while (cadena[i] != '\0')
    {
        if (i == 0 && cadena[i] == '-')
        {
            i++;
            continue;
        }
        if (cadena[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;
        }
        if (cadena[i] < '0' || cadena[i] > '9')
        {
            return 0;
        }
        i++;
    }
    return 1;

}



int getFloat(float *pResultado)
{
    int retorno = -1;
    char buffer[4096];
    if (find(buffer, sizeof(buffer)) && esNumericoFlotante(buffer))
    {
        retorno = 0;
        *pResultado = atof(buffer);
    }
    return retorno;
}


int soloNumeros(char* num)
{
	int error = 0;

	if(strlen(num) > 0)
    {
        for(int i = 0; i < strlen(num); i++)
        {
            if(!isdigit(num[i]))
            {
                if(!i && num[0] == '-')
                {
                    error=0;
                }
                else
                {
                    error=1;
                }
            }
        }
    }
    else
    {
        error=1;
    }

	return error;
}


int soloFloat(float* number, char mensaje[], char mensajeError[], float min, float max)
{
    int error=-1;
    char numeroAux[20];

	if(number!=NULL && mensaje!= NULL && mensajeError!=NULL && min<max)
	{
		printf("%s", mensaje);
		gets(numeroAux);
		fflush(stdin);

		while(soloNumeros(numeroAux) || atoi(numeroAux) < min || atoi(numeroAux) > max)
		{
			printf("%s", mensajeError);
			gets(numeroAux);
			fflush(stdin);
		}

        *number = atoi(numeroAux);
		error = 0;
	}

	return error;
}
