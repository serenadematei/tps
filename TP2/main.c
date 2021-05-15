#include <stdio.h>
#include <stdlib.h>
#include "get.h"
#include <string.h>
#include "ArrayEmployees.h"
#define LEN 10
#define LEN_NAME 50
#define LEN_LNAME 50
#define LENSEC 5



int main()
{

    Employee list[LEN];

    char name[LEN_NAME];
    char lastName[LEN_LNAME];
    float salary;
    int sector;
    int id=2000;
    char exit='n';
    int order;
    int option;


    initEmployees(list,LEN);
    hardcodearEmployees(list,LEN,10,&id);




    do{

        switch(Menu())
        {
        case 1:
               if(addEmployee(list,LEN,id,name,lastName,salary,sector))
               {
                   printf("\n Employee added successfully\n\n");
                   (id++);
                    system("pause");
               }
                else
               {
                    printf("Problem adding employee\n");
               }

            break;
        case 2:
            modifyEmployee(list,LEN);
            break;
        case 3:
            removeEmployee(list,LEN,id);
            break;
        case 4:
            system("cls");
            printf("Choose: \n");
            printf("1-Inform employee's list\n");
            printf("2-Inform total and average salary\n");
            utn_getNumero(&option,"Enter option: ","Error.",1,2,10);
            if(option==1)
            {
                sortEmployees(list,LEN);
            }
            else
            {
                if(option==2)
                {
                    system("cls");
                    totalSalaries(list, LEN);
                }
            }

            break;

        default:
            printf("Invalid option\n");
            break;
        }


    }while(exit=='n');

}



