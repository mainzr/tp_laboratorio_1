#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    char seguir = 's';
    char respuesta;
    int filesBinary = 0;
    int filesText = 0;
    int flagCsv = 0;
    int flagBin = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();


    do{
        switch(menu())
        {
            case 1:
            	if(flagCsv == 1)
            	{
            		printf("No se puede cargar dos veces el mismo archivo\n\n");
            	}
            	else
            	{
                	if(controller_loadFromText("data.csv", listaEmpleados) == 0)
                	{
                		flagCsv = 1;
                		printf("ARCHIVOS DE TEXTO CARGADOS CON EXITO....\n");

                	}
                	else
                	{
                		printf("Ocurrio un error....");

                	}
            	}
                break;
            case 2:
              	if(flagBin == 1)
                	{
                		printf("No se puede cargar dos veces el mismo archivo\n\n");
                	}
                	else
                	{
                    	if(controller_loadFromBinary("data.bin", listaEmpleados) == 0)
                    	{
                    		flagBin = 1;
                    		printf("ARCHIVOS BINARIOS CARGADOS CON EXITO....\n");

                    	}
                    	else
                    	{
                    		printf("Ocurrio un error....");

                    	}
                	}
            	break;
            case 3:
					controller_addEmployee(listaEmpleados);

            	break;
            case 4:
            	if(listaEmpleados->size)
            	{
                	controller_editEmployee(listaEmpleados);

            	}
            	else
            	{
            		printf("Se debe ingresar datos de empleados.\n");
            	}
            	break;
            case 5:
            	if(listaEmpleados->size)
            	{
                	controller_removeEmployee(listaEmpleados);

            	}
            	else
            	{
            		printf("Se debe ingresar datos de empleados.\n");
            	}
            	break;
            case 6:
            	if(listaEmpleados->size)
            	{
                	controller_ListEmployee(listaEmpleados);

            	}
            	else
            	{
            		printf("Se debe ingresar datos de empleados.\n");
            	}
            	break;
            case 7:
            	if(listaEmpleados->size)
            	{
                	controller_sortEmployee(listaEmpleados);

            	}
            	else
            	{
            		printf("Se debe ingresar datos de empleados.\n");
            	}
            	break;
            case 8:
            	if(listaEmpleados->size)
            	{
                	controller_saveAsText("data.csv", listaEmpleados);
                	filesText = 1;
            	}
            	else
            	{
            		printf("Se debe ingresar datos de empleados.\n");
            	}
            	break;
            case 9:
            	if(listaEmpleados->size)
            	{
                	controller_saveAsBinary("data.bin", listaEmpleados);
                	printf("ARCHIVOS BINARIOS GUARDADOS CON EXITO...");
                	filesBinary = 1;

            	}
            	else
            	{
            		printf("Se debe ingresar datos de empleados.\n");
            	}
            	controller_saveAsBinary("data.bin", listaEmpleados);
            	break;
            case 10:
            	if(filesBinary == 1 || filesText == 1)
            	{
    				printf("¿Seguro desea salir majestad? (s/n): ");
    				fflush(stdin);
    				scanf("%c", &respuesta);
    				respuesta = 'n';
            	}
            	else
            	{
            		printf("Error...Se debe guardar los archivos de texto o binarios antes de salir....\n");
            	}

            	break;
            default:
            	printf("Opcion invalida..\n");
            	break;
        }
     system("pause");

    } while(seguir == 's');

    return 0;
}

