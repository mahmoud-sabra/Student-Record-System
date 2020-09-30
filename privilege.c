#include "privilege.h"
static student_t records[MAX_RECORDS];
int avalibleFlag[MAX_RECORDS];
int nextAvalibaleIndex;
static char *adminCurrentPassword;
int get_avalible_index();


void safer_free(void **pp);
#define safe_free(p) (safer_free((void**)(&p)))
int get_id_index(int);


void safer_free(void **pp)
{
    if (pp != NULL && *pp != NULL)
    {
        free(*pp);
        *pp = NULL;
    }
}

int get_avalible_index()
{
    int i;
    for (i = 0; i < MAX_RECORDS; i++)
    {
        if (avalibleFlag[i] == 0)

            return i;
    }
    return -1;
}

int get_id_index(int ID)
{
    int i;
    for (i = 0; i < MAX_RECORDS; i++)
        if (records[i].ID == ID)
        {
            return i;
        }
    return -1;
}


int check_user_ID_password(int ID, char *password)
{
    int returnFlag;
    int i=get_id_index(ID);
    if ((i!=-1) && (strcmp(records[i].password,password)==0))
    {
        returnFlag = 1;
    }
    else
    {
        returnFlag = 0;
    }

    return returnFlag;


}

void set_admin_password()
{
    adminCurrentPassword=(char*)(malloc(strlen("0000")+1));
    strcpy(adminCurrentPassword, "0000");
}



int check_admin_password(char *adminPassword)
{
    int returnFlag;
    if (strcmp(adminCurrentPassword,adminPassword)==0)
    {
        returnFlag=1;
    }
    else
    {
        returnFlag=0;
    }
    return returnFlag;
}



void modify_admin_password(char *newAdminPassword)
{
    adminCurrentPassword = realloc(adminCurrentPassword,strlen(newAdminPassword)+1);
    strcpy(adminCurrentPassword,newAdminPassword);
}



int add_new_record(char *name, char *password,int ID, int degree)
{
    int addingFlag;
    int  i;
    if (nextAvalibaleIndex<(MAX_RECORDS-1))
    {
        i=nextAvalibaleIndex;
        nextAvalibaleIndex++;

    }
    else
    {
        i=  get_avalible_index();
    }
    if (i!=-1)
    {

        records[i].ID=ID;
        records[i].name = (char*)malloc(strlen(name) + 1);
        strcpy(records[i].name,name);
        records[i].password = (char*)malloc(strlen(password) + 1);

        strcpy(records[i].password,password);

        records[i].degree=degree;
        avalibleFlag[i]=1;
        addingFlag=1;
    }
    else
    {
        addingFlag=0;
    }
    return addingFlag;
}




int modify_student_name(int ID, char *name)
{
    int returnFlag, i=get_id_index(ID);
    if (i!=-1)
    {
        strcpy(records[i].name,name);
        returnFlag=1;
    }
    else
    {
        returnFlag=0;
    }
    return returnFlag;
}



int modify_student_password(int ID, char *password)
{
    int returnFlag, i=get_id_index(ID);
    if (i!=-1)
    {
        strcpy(records[i].password,password);
        returnFlag=1;
    }
    else
    {
        returnFlag=0;
    }
    return returnFlag;
}


int modify_degree(int ID,int degree)

{
    int returnFlag, i=get_id_index(ID);
    if (i!=-1)
    {
        records[i].degree=degree;
        returnFlag=1;
    }
    else
    {
        returnFlag=0;
    }
    return returnFlag;
}

int    view_record(int ID)
{
    int returnFlag, i = get_id_index(ID);
    if (i != -1)
    {
        printf("name :%s \n ID :%d \n degree: %d \n password: %s \n", records[i].name, records[i].ID,
               records[i].degree, records[i].password);

        returnFlag = 1;
    }
    else
    {
        returnFlag = 0;
    }
    return returnFlag;
}
int remove_record(int ID)
{
    int returnFlag, i=get_id_index(ID);
    if (i!=-1)
    {

        records[i].degree=0;
        records[i].ID=0;
        safe_free(records[i].name);
        safe_free(records[i].password);
        avalibleFlag[i]=0;
        returnFlag=1;
    }
    else
    {
        returnFlag=0;
    }
    return returnFlag;
}
