//
// Created by Administrator on 7/2/2025.
//


#include "../repository/repository.h"
#include<stdlib.h>
#include <string.h>

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