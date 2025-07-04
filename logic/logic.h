//
// Created by Administrator on 7/2/2025.
//

#ifndef UNTITLED2_LOGIC_H
#define UNTITLED2_LOGIC_H
#include "../entity/entity.h"

int login_student(char *userName, char *password, int *j);

void signup_student(struct student new_student);

void signup_responsible (struct responsible new_responsible);

char *login_responsible (char *userName, char *password, int *j);

char *check_pass(char *pass, int *password);

char * delete_student( int student_number);

char* deActive(int student_num);

char* change_password(int student_number,char* new_pass);

char* check_student_status(int *flag);

char* active_student (int student_number);

char* charge_Account(int studentnum,float charg);

#endif //UNTITLED2_LOGIC_H
