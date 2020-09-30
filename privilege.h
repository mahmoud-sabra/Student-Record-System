//
// Created by ENG MS on 9/18/2020.
//

#ifndef PRIVILEGE_H
#define PRIVILEGE_H
#include "student_struct.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX_RECORDS 10


int check_user_ID_password(int ID, char *password);
/*
 *  description: check if the entered ID and password are correct.
 *  return: 1 if correct, 0 if wrong.
 */

void set_admin_password();
/*
 *  description: set the first password for admin.
 *  return: void.
 */

int check_admin_password(char *adminPassword);
/*
 *  description: check if the entered password is correct or not.
 *  return: 1 if correct, 0 if wrong.
 */


void modify_admin_password(char *newAdminPassword);
/*
 *  description: modify the admin password.
 *  return: void.
 */

int add_new_record(char *name, char *password, int ID ,int degree);
/*
 *  description: add new record.
 *  return: 1 if adding record succeeded, 0 if not.
 */

int modify_student_name(int ID, char *name);
/*
 *  description: modify the name.
 *  return: 1 if modifying the name succeeded, 0 if not.
 */

int modify_student_password(int ID, char *password);
/*
 *  description: modify the password.
 *  return: 1 if modifying the password succeeded, 0 if not.
 */

int modify_degree(int ID,int degree);
/*
 *  description: modify the degree.
 *  return: 1 if modifying the degree succeeded, 0 if not.
 */

int view_record(int ID);
/*
 *  description: view info about record.
 *  return: 1 if traversing the record succeeded, 0 if not.
 */

int remove_record(int ID);
/*
 *  description: remove the record.
 *  return: 1 if removing the record succeeded, 0 if not.
 */


#endif //PRIVILEGE_H
