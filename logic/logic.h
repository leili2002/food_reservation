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

int check_self(int gender,const char* self_name);

struct reserve *reserve_student_list(int j);

void update_self (struct dailyself update_self,int index);

struct reserve * food_report(size_t *count);

struct reserve *food_reports_by_self(const char *name,int* out_count);

struct reserve* student_report(int student_num);

int *search_id(int id);

void put_in_array(struct dailyself new_self);

#endif //UNTITLED2_LOGIC_H
