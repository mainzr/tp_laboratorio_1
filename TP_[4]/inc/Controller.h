#include "../inc/LinkedList.h"

int menu();
int editEmployeeMenu();


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

int controller_IdSig();
void controller_guardarIdSig(int id);

int controller_addEmployee(LinkedList* pArrayListEmployee);

int controller_editEmployee(LinkedList* pArrayListEmployee);

int controller_removeEmployee(LinkedList* pArrayListEmployee);

int controller_ListEmployee(LinkedList* pArrayListEmployee);

int controller_sortEmployee(LinkedList* pArrayListEmployee);


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

int controller_mayorSueldoHoras(LinkedList* pArrayListEmployee);
int controller_listNuevosEmployees(LinkedList* pArrayEmployee);

int controller_eliminarCompletamente(LinkedList* pArrayEmployee);
