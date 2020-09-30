//
// Created by ENG MS on 9/18/2020.
//
#include "system.h"
int adminAction;
int userAction;
void system_init(void)
{
    set_admin_password();
    printf("welcome to the student record system");
}
void system_run()
{
    int selectMode;
    printf("Enter the mode you need:\n");
    printf("1-Admin mode\n");
    printf("2-User mode\n");
    scanf("%d", &selectMode);
    while (1)
        if (selectMode ==2||selectMode==1)
        {

            switch (selectMode)
            {
            case ADMIN_MODE:
                printf("welcome to admin mode\n");
                admin_mode();
                break;

            case USER_MODE:
                printf("welcome to user mode\n");
                user_mode();
                break;

            default :
                break;

            }
        }
        else
        {
            printf("wrong entry please try again\n");
            scanf("%d",&selectMode);
        }
}
void admin_mode()
{
    char adminPassword[MAX_LENGTH];
    printf("enter admin password \n");
    fflush(stdin);
    gets(adminPassword);
    admin_login(adminPassword);
    admin_menu();
    admin_action();

}

void admin_login(char *adminPassword)
{
    while (!check_admin_password(adminPassword))
    {
        printf("you entered a wrong password\n");
        printf("enter it again\n");
        fflush(stdin);
        gets(adminPassword);
    }
}
void admin_menu()
{
    printf("Enter the number of operation you need:\n");
    printf("1-Change admin password.\n");
    printf("2-Add new student.\n");
    printf("3-Edit student name.\n");
    printf("4-Edit student password.\n");
    printf("5-Edit student degree.\n");
    printf("6-View student info.\n");
    printf("7-Remove student.\n");
    printf("8-Return to main menu\n");
}

void admin_action()
{
    char adminPassword[MAX_LENGTH];
    char studentPassword[MAX_LENGTH];
    char studentName[MAX_LENGTH];
    int studentDegree;
    int studentID;
    scanf("%d",&adminAction);
    while (!(adminAction>=1 &&adminAction<=8))
    {
        printf("wrong choice please try again\n");
        scanf("%d", &adminAction);
    }
    switch (adminAction)
    {
    case 1:
        printf("enter the new password\n");
        fflush(stdin);
        gets(adminPassword);
        modify_admin_password(adminPassword);
        printf("password has changed successfully\n \n");
        break;
    case 2:
        printf("enter student ID\n");
        scanf("%d",&studentID);
        printf("enter student name\n");
        fflush(stdin);
        gets(studentName);

        printf("enter student password\n");
        fflush(stdin);
        gets(studentPassword);

        printf("enter student degree\n");
        scanf("%d",&studentDegree);
        if(add_new_record(studentName, studentPassword, studentID, studentDegree))
        {
            printf("student has successfully added\n");
        }
        else
        {
            printf("there is no space for new student");
        }

        break;
    case 3:
        printf("enter student ID\n");
        scanf("%d", &studentID);
        printf("enter student name\n");
        scanf("%s",studentName);
        if (modify_student_name(studentID,studentName))
        {
            printf("name has successfully changed");
        }
        else
        {
            printf("you entered wrong ID\n");
        }
        break;
    case 4:
        printf("enter student ID\n");
        scanf("%d", &studentID);
        printf("enter student password\n");
        fflush(stdin);
        gets(studentPassword);
        if (modify_student_password(studentID,studentPassword))
        {
            printf("password has successfully changed");
        }
        else
        {
            printf("you entered wrong ID\n");
        }
        break;
    case 5:
        printf("enter student ID\n");
        scanf("%d", &studentID);
        printf("enter student degree\n");
        scanf("%d",&studentDegree);
        if (modify_degree(studentID,studentDegree))
        {
            printf("degree has successfully changed\n");
        }
        else
        {
            printf("you entered wrong ID\n");
        }
        break;
    case 6:
        printf("enter student ID\n");
        scanf("%d", &studentID);
        if (!view_record(studentID))
        {
            printf("you entered wrong ID\n");
        }
        break;
    case 7:
        printf("enter student ID\n");
        scanf("%d",&studentID);
        if(remove_record(studentID))
        {
            printf("student removed successfully\n");
        }
        else
        {
            printf("you entered wrong ID\n");
        }
        break;
    case 8:
        system_run();
        break;
    default:
        break;
    }
    admin_menu();
    admin_action();

}

void user_mode()
{
    int UserId;
    char userPassword[MAX_LENGTH];
    printf("enter your ID \n");
    scanf("%d",& UserId);
    printf("enter user password \n");
    fflush(stdin);
    gets(userPassword);
    user_login(UserId,userPassword);
    user_menu();
    user_action(UserId);
}

void user_login(int ID,char *userPassword)
{
    while (!check_user_ID_password(ID,userPassword))
    {


        printf("wrong ID or password try again\n");
        scanf("%d",&ID);
        fflush(stdin);
        gets(userPassword);
    }
}

void user_menu()
{
    printf("Enter the number of operation you need:\n");
    printf("1-View your info.\n");
    printf("2-Change your password.\n");
    printf("3-Return to main menu.\n");
}


void user_action(int ID)
{
    char studentPassword[MAX_LENGTH];
    scanf("%d",&userAction);
    while (!(userAction>=1 &&userAction<=3))
    {
        printf("wrong choice please try again\n");
        scanf("%d", &userAction);
    }
    switch (userAction)
    {
    case 1:
        if(!view_record(ID))
        {
            printf(" you entered wrong ID\n");
        }
        break;
    case 2:
        printf("enter new password\n");
        fflush(stdin);
        gets(studentPassword);
        modify_student_password(ID,studentPassword);
        printf("password has successfully changed\n");
        break;
    case 3:
        system_run();
        break;
    default:
        break;
    }
    user_menu();
    user_action(ID);
}

//SYSTEM_H
