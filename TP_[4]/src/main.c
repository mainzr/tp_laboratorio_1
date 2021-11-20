/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

//***********************************
// ANZOR, MAIA MARIA LUZ -  DIV A
//***********************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "../inc/LinkedList.h"
#include "../inc/Controller.h"
#include "../inc/Employee.h"
#include "../inc/inputs.h"


int main(void)
{
	setbuf(stdout, NULL);

	/*startTesting(1);  // ll_newLinkedList //---- LINEA 55 - MAIN
    startTesting(2);  // ll_len -----> Usada en la funcion controller_removeEmployee //--- linea 412
	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add ----> USADO EN FUNCION : LinkedList* ll_subList(LinkedList* this,int from,int to); //------ LINEA 267
	startTesting(6);  // ll_get-----> USADO EN FUNCION: controller_removeEmployee //----- LINEA 435
	startTesting(7);  // ll_set ----> USADO EN FUNCION: ll_sort //--- LINEA 578
	startTesting(8);  // ll_remove ---> USADO EN LA FUNCION:  controller_removeEmployee //------ LINEA 450
	startTesting(9);  // ll_clear ---> USADO EN FUNCION: controller_eliminarCompletamente //---- LINEA 937
	startTesting(10); // ll_deleteLinkedList USADO EN CASE 9 //----- LINEA 203
	startTesting(11); // ll_indexOf ----> 	USADO EN FUNCION controller_mayorSueldoHoras //------- LINEA 790
	startTesting(12); // ll_isEmpty---> USADO EN SWITCH- CASE 6 //-----LINEA 157
	startTesting(13); // ll_push ---> USADO EN FUNCION controller_listNuevosEmployees //--- LINEA 839
	startTesting(14); // ll_pop ----> USADO EN FUNCION controller_mayorSueldoHoras //-------------- LINEA 795
	startTesting(15); // ll_contains ---> controller_removeEmployee //--- LINEA 441
	startTesting(16); // ll_containsAll ---> USADO EN FUNCION controller_listNuevosEmployees //---- LINEA 867
	startTesting(17); // ll_subList ---> USADO EN FUNCION controller_listNuevosEmployees //--- LINEA 796
	startTesting(18); // ll_clone ---> USADO EN FUNCION: controller_sortEmployee //--------- LINEA 542
	startTesting(19); // ll_sort---> USADO EN FUNCION controller_sortEmployee //------ LINEA 561 */

    LinkedList* listaEmpleados = ll_newLinkedList();
    char seguir = 's';
    char respuesta;
    int filesText = 0;
    int flagCsv = 0;



    do{
        switch(menu())
        {
            case 1:
            	if(flagCsv == 1)
            	{
            		printf("\nNo se puede cargar dos veces el mismo archivo\n\n");
            	}
            	else
            	{
                	if(controller_loadFromText("data.csv", listaEmpleados) == 0)
                	{
                		flagCsv = 1;
                		printf("\nARCHIVOS DE TEXTO CARGADOS CON EXITO....\n");

                	}
                	else
                	{
                		printf("\nOcurrio un error....");

                	}
            	}
                break;
            case 2:
            	 controller_addEmployee(listaEmpleados);
            	break;
            case 3:
			  if(ll_isEmpty(listaEmpleados) == 0)
			  {
				  controller_mayorSueldoHoras(listaEmpleados);
			  }
			  else
			  {
				  printf("\nSe deben ingresar empleados...\n");

			  }
            	break;
            case 4:

            	if(ll_isEmpty(listaEmpleados) == 0)
            	{
                	controller_editEmployee(listaEmpleados);

            	}
            	else
            	{
            		printf("\nSe debe ingresar datos de empleados...\n");
            	}


            	break;
            case 5:
            	if(listaEmpleados->size)
            	{
                	controller_removeEmployee(listaEmpleados);

            	}
            	else
            	{
            		printf("\nSe debe ingresar datos de empleados...\n");
            	}
            	break;
            case 6:
            	if(ll_isEmpty(listaEmpleados) == 0)
            	{
            		controller_ListEmployee(listaEmpleados);

            	}
            	else
            	{
            		printf("\nSe debe ingresar datos de empleados...\n\n");
            	}
            	break;
            case 7:
            	if(listaEmpleados->size)
            	{

                	controller_sortEmployee(listaEmpleados);

            	}
            	else
            	{
            		printf("\nSe debe ingresar datos de empleados...\n");
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
            		printf("\nSe debe ingresar datos de empleados...\n");
            	}
            	break;
            case 9:
            	if(ll_isEmpty(listaEmpleados) == 0)
            	{
            		controller_eliminarCompletamente(listaEmpleados);
            	}
            	else
            	{
            		printf("No existen empleados para mostrar...\n");
            	}

            	break;
            case 10:
            	if(ll_isEmpty(listaEmpleados) == 0)
            	{
                	controller_listNuevosEmployees(listaEmpleados);
            	}
            	else
            	{
            		printf("No existen empleados....\n");
            	}
            	break;

            case 11:
            	if(filesText == 1)
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
































