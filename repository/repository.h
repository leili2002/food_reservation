//
// Created by Administrator on 7/2/2025.
//

#ifndef UNTITLED2_REPOSITORY_H
#include <stdlib.h>
#define UNTITLED2_REPOSITORY_H
#include "../entity./entity.h"


void saveStudents(struct student student[], int size);
void save_responsible(struct responsible responsible[], int size);
struct student *load_student(int *size);
struct responsible *load_responsible(int *size) ;


#endif //UNTITLED2_REPOSITORY_H
