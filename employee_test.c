#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lists.h"

typedef struct
{
    int id;
    char name[10];
    int salary;
}employee;

employee Employee()
{
    employee emp;
    puts("please enter employee 's name");
    scanf("%s",emp.name);
    // printf("please enter %s's id\n",emp.name);
    // scanf("%d",&emp.id);
    static int id = 1;
    emp.id = id++;
    printf("please enter %s's salary\n",emp.name);
    scanf("%d",&emp.salary);
    return emp;
}

void disp_employee(employee* emp)
{
    if (emp)
        printf("%d. emplyee : %s has a salary of %d \n",emp->id,emp->name,emp->salary);
    else
        puts("sorry no on match");
}

int id_comparator(employee * emp , int * id)
{
    return !(emp ->id - *id) ;
}

int name_comparator(employee * emp , char* name)
{
    return !strcmp(emp->name , name);
}


void menu()
{
    list l = List();
    int i ,n,cont = 1;
    employee * emp;
    char saearched_name[30];
    char user_io[6][36] = {
        "1. add new employee",
        "2. add new employee in position",
        "3. search for an employee by ID",
        "4. search for an employee by Name",
        "5. Display all employees",
        "6. exit"
    };
    while(cont)
    {
        system("cls");
        for (i=0 ; i < 6 ; i++)
            puts(user_io[i]);
        scanf("%d",&n);
        system("cls");
        switch (n)
        {
        case 1:
            emp = malloc(sizeof(employee));
            *emp = Employee();
            add(&l,Node(emp));
            break;
        case 2:
            emp = malloc(sizeof(employee));
            *emp = Employee();
            printf("please specify the position you want to insert %s in \n",emp->name);
            scanf("%d",&n);
            add_in_location(&l,Node(emp),n);
            break;
        case 3:
            puts("please specify the ID you want to search for");
            scanf("%d",&n);
            disp_employee(search(&l,(int (*)(void *, void *))&id_comparator,&n) );
            getch();
            break;
        case 4:
            puts("please specify the name you want to search for");
            scanf("%s",saearched_name);
            disp_employee(search(&l,(int (*)(void *, void *))&name_comparator,saearched_name) );
            getch();
            break;
        case 5:
            disp_all(&l ,(void*) &disp_employee);
            getch();
            break;
        case 6:
            cont = 0;
            break;
        default:
            break;
        }
    }
}
int main()
{
    menu();
    return 0;
}