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
#endif //UNTITLED2_LOGIC_H
