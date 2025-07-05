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

enum day{
    shanbeh=0,
    yekshanbeh=1,
    doshanbeh=2,
    seshanbeh=3,
    charshanbeh=4
};


struct food {
    char name[30];
    float price;
    int id;
};

struct dailyself {
    int id;
    char name[30];
    int gender;//1=male,2=female
    char location[100];
    int capacity;
    struct food lunch_shanbeh[10];
    int lunch_shanbeh_count;
    struct food lunch_yekshanbeh[10];
    int lunch_yekshanbeh_count;
    struct food lunch_doshanbeh[10];
    int lunch_doshanbeh_count;
    struct food lunch_seshanbeh[10];
    int lunch_seshanbe_count;
    struct food lunch_charshanbeh[10];
    int lunch_charshanbeh_count;
    struct food dinner_shanbeh[10];
    int dinner_shanbeh_count;
    struct food dinner_yekshanbeh[10];
    int dinner_yekshanbeh_count;
    struct food dinner_doshanbeh[10];
    int dinner_doshanbeh_count;
    struct food dinner_seshanbeh[10];
    int dinner_seshanbeh_count;
    struct food dinner_charshanbeh[10];
    int dinner_charshanbe_count;
};
struct reserve {
    int student_id;
    char self_name[30];
    char food[30];
    enum day day;
    char meal[20];

};

#endif //UNTITLED2_ENTITY_H
