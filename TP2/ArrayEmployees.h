#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED



typedef struct{

  int id;
  char name[51];
  char lastname[51];
  float salary;
  int  sector;
  int isEmpty;


}Employee;


#endif // ARRAYEMPLOYEES_H_INCLUDED



/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len);


/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector);

//int addEmployee(Employee* list, int len,int* id);
//int addEmployee(Employee* list, int len, int id, char name[],char
//lastName[],float salary,int sector);

int lookForEmpty(Employee list[],int len);
//int hardcodearEmpleados(Employee list[], int len, int amount, int* pId);


int loadDataEmployee(char* name,char* lastName,float* salary,int* sector);





int printEmployees(Employee* list, int len);


void printAnEmployee(Employee oneEmployee);


int findEmployeeById(Employee* list, int len,int id);

int subMenu();
int subMenuModifications();

int modifyEmployee(Employee* list,int len);

int totalSalaries(Employee* list, int len);
