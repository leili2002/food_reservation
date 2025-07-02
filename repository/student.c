//
// Created by Administrator on 7/2/2025.
//

#include<stdlib.h>
#include "repository.h"
#include <stdio.h>

void saveStudents(struct student student[], int size) {
    FILE *fp = fopen("../data/student_text.txt", "wb");

    fwrite(&size, sizeof(int), 1, fp);
    fwrite(student, sizeof(struct student), size, fp);
    fclose(fp);
}

struct student *load_student(int *size) {
    FILE *fp = fopen("../data/student_text.txt", "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        *size = 0;
        return NULL;
    }

    fread(size, sizeof(int), 1, fp);

    struct student *temp = malloc(*size * sizeof(struct student));
    if (temp == NULL) {
        printf("responsibleArray allocation failed.\n");
        *size = 0;
        fclose(fp);
        return NULL;
    }

    fread(temp, sizeof(struct student), *size, fp);
    fclose(fp);
    return temp;
}
