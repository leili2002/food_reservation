//
// Created by Administrator on 7/2/2025.
//
#ifndef UNTITLED2_ENTITY_H
#define UNTITLED2_ENTITY_H
#include <stdbool.h>

struct student {
    char name[20];
    char lastname[30];
    char userName[20];
    char password[100];
    int gender;//1-male,2-female
    int status;//0=inactive,1=active
    int studentNum;
    float cash;
};

struct responsible {
    char name[20];
    char lastname[40];
    char username[20];
    char password[20];
    int personal_id;
};



#endif //UNTITLED2_ENTITY_H
