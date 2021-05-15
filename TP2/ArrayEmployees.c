#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "get.h"



static char names[10][20]={
    "Bob",
    "Edna",
    "Alice",
    "Stephanie",
    "Jim",
    "Mick",
    "Muddy",
    "Axel",
    "James",
    "David"

};

static char lastNames[10][20]={
    "Dylan",
    "Smith",
    "Johnson",
    "O'Neill",
    "Morrison",
    "Jagger",
    "Waters",
    "Rose",
    "Brown",
    "Bowie"

};


static float salaries[10]={10000,12000,11000,12000,13700,11800,10300,13100,14700,12400};
static int sectors[10]={500,503,503,501,500,504,502,502,504,500};


int initEmployees(Employee* list, int len)
{
    int itsOk=0;

    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty=1; //TRUE(1) empty, FALSE(0) full
        }

    }

    return itsOk;
}






int findEmployeeById(Employee* list, int len,int id)
{

    int index=-1;

     if(list!=NULL && len>0)
     {
          for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty==0 && list[i].id == id)
            {
                index=i;
                break;
            }


        }
     }


     return index;
}









int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector)
{
    int itsOk=0;
    int index;
    Employee newEmployee; //variable auxiliar para guardar datos
    float auxSalary;


    if(list !=NULL && len>0)
    {

        system("cls");
        printf("     Adding an employee\n");
        printf("Id: %d\n", id);


        index=lookForEmpty(list,len);


        if(index==-1)
        {
            printf("No place in the system\n");
        }
        else
        {
            newEmployee.id=id;

        utn_getNombre(&newEmployee.name,"Name: ","Error.\n",50,10);
        utn_getNombre(&newEmployee.lastname,"Last name: ","Error.\n",50,10);
        utn_getNumero(&newEmployee.sector,"Sector: ","Error.\n",500,504,10);

        printf("Salary: ");
        scanf("%f",&auxSalary);

        while(auxSalary<=0)
        {
            printf("Error. Salary:");
            scanf("%f",&auxSalary);
        }

            newEmployee.salary=auxSalary;
            newEmployee.isEmpty=0;




            list[index]=newEmployee;
            //(id)++;



            itsOk=1;

        }

    }


    return itsOk;

}



int hardcodearEmployees(Employee list[], int len, int amount, int* pId)
{
    int itsOk=0;
    if(list!=NULL && len>0 && amount>=0 && amount<=len && pId!=NULL)
    {
        for(int i=0; i<amount; i++)
        {
            list[i].id=*pId;
            (*pId)++;


            strcpy(list[i].name, names[i]);
            strcpy(list[i].lastname,lastNames[i]);
            list[i].salary=salaries[i];
            list[i].sector=sectors[i];
            list[i].isEmpty=0;


          itsOk=1;
        }
    }
    return itsOk;
}




int lookForEmpty(Employee list[],int len)
{
    int index=-1;


    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty==1)
            {
                index=i;
                break;
            }

        }
    }



    return index;
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/



int printEmployees(Employee* list, int len)
{
    int itsOk=0;
    int flag=1;

    if(list!=NULL && len>0)
    {
        system("cls");
     printf("               ***   EMPLOYEES LIST   ***     \n\n");
     printf("ID                   LAST NAME               NAME          SALARY          SECTOR\n");

     for(int i=0; i<len ; i++)
     {
         if(!list[i].isEmpty)
         {
             printAnEmployee(list[i]);
             flag=0;
         }

         if(flag)
         {

             fflush(stdin);
             printf("There isn't employees on the list \n");

         }

     }

      itsOk=1;
    }



 return itsOk;
}

void printAnEmployee(Employee oneEmployee)
{

    printf("%4d            %10s             %10s          %.1f           %d\n"
           ,oneEmployee.id
           ,oneEmployee.lastname
           ,oneEmployee.name
           ,oneEmployee.salary
           ,oneEmployee.sector
           );
}


int removeEmployee(Employee* list, int len, int id)
{
    int itsOk=0;
    int index;
//    int id;
    char answer;

    system("cls");

    if(list!=NULL && len>0)
    {
        printEmployees(list,len);
        printf("Enter ID: ");
        scanf("%d",&id);


        index= findEmployeeById(list,len,id);

        if(index==-1)
        {
            printf("There isn't an employee with ID: %d\n",id);
        }
        else
        {
            system("cls");
            printAnEmployee(list[index]);
            utn_getCaracter(&answer,"¿Are you sure you want to remove employee?  y/n:","Error.\n",'y','n',10);

        }


        if(answer=='y')
        {

            list[index].isEmpty=1;
            printf("Employee removed succesfully\n");
            system("pause");
            itsOk=1;

        }
        else
        {
            printf("Removing cancelled\n");
            system("pause");
        }

        itsOk=1;
    }

  return itsOk;
}



int sortEmployees(Employee* list, int len, int order)
{
    int itsOk=0;
    order=subMenuOrden();

    Employee auxEmployee;

    if(list!=NULL && len>0)
    {
        itsOk=1;
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(!order && ((stricmp(list[i].lastname, list[j].lastname)<0) || (stricmp(list[i].lastname, list[j].lastname)==0 && list[i].sector<list[j].sector)))
                {
                    auxEmployee=list[i];
                    list[i]=list[j];
                    list[j]=auxEmployee;
                }
                else if(order && ((stricmp(list[i].lastname, list[j].lastname)>0) || (stricmp(list[i].lastname, list[j].lastname)==0 && list[i].sector>list[j].sector)))
                {
                    auxEmployee=list[i];
                    list[i]=list[j];
                    list[j]=auxEmployee;
                }
            }
        }
       printEmployees(list,len);
    }



    system("pause");
    return  itsOk;
}







int subMenuOrden()
{
    int order;
    system("cls");


    printf("      Choose the way to order employees:\n");
    printf("0) Descending order.\n");
    printf("1) Ascending order\n");


    utn_getNumero(&order, "Enter option: ","ERROR .",0,1,10);



        return order;
}




int modifyEmployee(Employee* list,int len)
{



    Employee oneEmployee;
    int itsOk=0;
    float auxSalary;

    int option;
    int index;
    int id;
    int flagName=1;
    int flagLName=1;
    int flagSalary=1;
    int flagSector=1;


    system("cls");



    printEmployees(list,len);

    printf("\n\n");
    printf("\nEnter employee ID: ");
    scanf("%d",&id);


   index= findEmployeeById(list,len,id);

    if(index==-1)
    {
        printf("There isn't an employee with id %d\n",id);
    }
    else
    {



        system("cls");
        printf("Employee:\n \n");
        printAnEmployee(list[index]);
        printf("\n\n");



        do
        {

            option=subMenuModifications();

            switch(option)
            {
            case 1:
                system("cls");
                flagName= utn_getNombre(&oneEmployee.name,"Enter new name:","Error. ",50,10);
                break;
            case 2:
                system("cls");
                flagLName= utn_getNombre(&oneEmployee.lastname,"Enter new last name:","Error. ",50,10);
                break;
            case 3:
                system("cls");
                printf("Enter new salary: ");
                scanf("%f",&auxSalary);

                while(auxSalary<=0)
                {
                    printf("Error. Salary:");
                    scanf("%f",&auxSalary);
                }

                oneEmployee.salary=auxSalary;
                flagSalary=0;

                break;
            case 4:
                system("cls");
                printf("****SECTORS****\n");
                printf("500 -- Sales\n");
                printf("501 -- System\n");
                printf("502 -- Enviroment\n");
                printf("503 -- Administration\n");
                printf("504 -- Marketing\n");

                flagSector=utn_getNumero(&oneEmployee.sector,"Enter new sector: ","Error.",500,504,10);
                break;

            case 5:
                system("cls");
                if(!flagName)
                {
                    strcpy(list[index].name,oneEmployee.name);
                }
                if(!flagLName)
                {
                    strcpy(list[index].lastname,oneEmployee.lastname);
                }
                if(!flagSalary)
                {
                    list[index].salary=oneEmployee.salary;
                }
                if(!flagSector)
                {
                    list[index].sector=oneEmployee.sector;
                }

                printf("Employee has been modified\n");
                printAnEmployee(list[index]);
                printf("\n\n");
                printf("\nChanges saved, returning to the main menu..\n\n");
                system("pause");



                itsOk=1;
                break;

            case 6:
                system("cls");
                printf("\n\n");
                printf("Changes canceled, returning to the main menu...\n\n");
                system("pause");
                break;


            }

        }
        while(option!=5 && option!=6);

    }
    return itsOk;
}







int subMenuModifications()
{
    int option;

    printf("\n\n\n");
    printf("1-Modify name\n");
    printf("2-Modify last name\n");
    printf("3-Modify salary\n");
    printf("4-Modify sector\n");
    printf("5-Save changes and exit.\n");
    printf("6-Cancel changes and exit.\n");

    utn_getNumero(&option,"Enter option: ","Error.:",1,6,10);

    return option;
}






int totalSalaries(Employee* list, int len)
{


    int itsOk=0;
    float total=0;
    float amountEmployees=0;
    int moreThanAverage=0;
    float average;


    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            total=total+list[i].salary;
            amountEmployees++;
        }


        average=total/amountEmployees;

        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty==0 && (list[i].salary>average))
            {
                moreThanAverage++;
            }
        }

        printf("Total amount of salaries: %f\n",total);
        printf("Average salary: %f\n",average);
        printf("Amount of employees whose salaries are higher than average salary: %d\n",moreThanAverage);
        system("pause");

        itsOk=1;


    }




    return itsOk;


}


int Menu()
{
    int option;

    system("cls");
    printf("      *** EMPLOYEE ADMINISTRATION ***\n\n");
    printf("1) Register an employee\n");
    printf("2) Modified an employee\n");
    printf("3) Remove an employee.\n");
    printf("4) List employees .\n");

    printf("\n");

    utn_getNumero(&option,"Enter option: ","Error. ",1,4,3);

    return option;
}

