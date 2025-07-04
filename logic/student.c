//
// Created by Administrator on 7/2/2025.
//


#include "../repository/repository.h"
#include<stdlib.h>
#include <string.h>
#include <stdio.h>

void signup_student(struct student new_student) {
    int size = 0;
    struct student *student_array = load_student(&size);
    if (student_array == NULL) {
        student_array = malloc(sizeof(struct student));}
    else{
    struct student *temp = realloc(student_array, (size + 1) * sizeof(struct student));
    student_array = temp;}
    student_array[size] = new_student;
    size++;
    saveStudents(student_array, size);
    free(student_array);

}


int login_student(char *userName, char *password, int *j) {
    int size = 0;
    struct student *studentArray = load_student(&size);
    for (int i = 0; i < size; i++) {
        if (strcmp(studentArray[i].userName, userName) == 0 &&
            (strcmp(studentArray[i].password, password) == 0)) {
            (*j) = i;
            if (studentArray[i].status == 0) {
                return -1;
            } else {
                return 0;
            }

        }
    }
    free(studentArray);
}


char *check_pass(char *pass, int *password) {

    //check pass hardness
    unsigned int p = strlen(pass);
    int has_upper = 0, has_lower = 0, has_number = 0, has_underline = 0;
    for (int j = 0; j < p; j++) {
        if ((pass[j] >= 'a' && pass[j] <= 'z')) { has_lower++; }
        if (pass[j] >= 'A' && pass[j] <= 'Z') { has_upper++; }
        if (pass[j] >= '0' && pass[j] <= '9') { has_number++; }
        if (pass[j] == ('_')) { has_underline++; }

    }
    if (!(has_lower && has_upper && has_number && has_underline)) {
        (*password) = 0;
        return "Password must include uppercase, lowercase, digit, and underscore.\n";
    }

    //if pass hasn't enough number
    if (strlen(pass) < 10) {
        (*password) = 0;
        return "your password is less than 10 digit\n try again\n";

    }
    (*password) = 1;
    return "password saved";
}

char * delete_student( int student_number) {
    int size_student = 0;
    int index=0;
    struct student *arr= load_student(&size_student);


    for (int i = 0; i < size_student; i++) {
        if (arr[i].studentNum == student_number) {
            index = i;
            break;
        }
    }
    if (index != 0) {//means it found {
        for (int i = index; i < size_student - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size_student--;
        saveStudents(arr,size_student);
        return "delete successfully";
    }

    return"failed";
}


char* deActive(int student_num){
    int size=0;
    struct student * array= load_student(&size);
    for (int i =0;i<=size;i++){
        if( array[i].studentNum==student_num){
            array[i].status=0;
            saveStudents(array,size);
            free(array);
            return "%s deactive successfully";

        }
    }
    return "failed";
}


char * change_password_by_student(int student_num,char *current_pass,char *new_password){
    int size;
    struct student*student_array= load_student(&size);
    for (int i = 0; i < size; i++) {
        if (student_array[i].studentNum == student_num){
            if (strcmp(student_array[i].password, (const char *)current_pass) == 0) {
                strcpy(student_array[i].password,new_password);
                saveStudents(student_array,size);
                return "change successfully";
            }
        }
    }
    return "failed";
}


char* change_password(int student_number,char* new_pass){
    int size=0;
    struct student *student_array = load_student(&size);
    for (int i = 0; i < size; i++) {
        if (student_array[i].studentNum == student_number){
            strcpy(student_array[i].password, new_pass);
            saveStudents(student_array,size);
            return "change successfully";
        }
    }
    return "failed";

}


char* check_student_status(int *flag) {
    int size = 0;
    struct student *student_array = load_student(&size);
    for (int i = 0; i < size; i++) {
        if (student_array[i].status == 0){
            char *result = malloc(256);
            snprintf(result, 256,
                     "name=%s\n"
                     "lastname=%s\n"
                     "studentnum=%s\n",
                     student_array[i].name,
                     student_array[i].lastname,
                     student_array[i].studentNum);
            *flag=1;
            return result;

        }
    }  *flag=0;
    return NULL;
}


char* active_student (int student_number){
    int size=0;
    struct student *student_array = load_student(&size);
    for (int i = 0; i < size; i++) {
        if (student_array[i].studentNum == student_number){
            student_array[i].status=1;
            saveStudents(student_array,size);
            char *result = malloc(256);
            snprintf(result, 256,
                     "name=%s\n"
                     "lastname=%s\n"
                     "studentnum=%s\n",
                     student_array[i].name,
                     student_array[i].lastname,
                     student_array[i].studentNum);
            return result;
        }
    }return "wrong studentnum";


}

int   search_student(int j,int *gender){
    int size=0;
    struct student *student_array = load_student(&size);
    *gender=student_array[j].gender;
    int student_num=student_array[j].studentNum;
    return student_num ;
}


char* charge_own_account(int index,float charg){
    int size=0;
    struct student *student_array = load_student(&size);
    student_array[index].cash=charg;
    return "charged";
}