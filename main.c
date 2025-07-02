//
// Created by Administrator on 7/2/2025.
//

#include <stdio.h>
#include "repository/repository.h"
#include "logic/logic.h"

void studentMenuHandler(int j);
void responsibleMenuHandler(int j);
enum role {
    student = 1,
    responsible = 2,
};

enum action {
    signUp = 1,
    login = 2,
    out = 3,
};

enum responsible_menu {
    student_set = 1,
    food_setting = 2,
    publish_announcement = 3,
    sign_out = 4,
};


void welcomePage() {
    printf("\n\t\t\t\t\tWELCOME TO food reservation site\n");
    printf("\t\t\t\t\t********************************\n\n");
}

int showAndGetRoleMenu() {
    printf("enter your role please\n"
           "1:student\n"
           "2:responsible\n");
    int chosenRole;
    scanf("%d", &chosenRole);
    return chosenRole;
}

int showAndGetActionMenu() {

    printf("1:sign_up\n"
           "2:log_in\n"
           "3-exit\n");
    int chosenAction;
    scanf("%d", &chosenAction);
}

void signUpStudentHandler() {
    struct student new_student;
    printf("enter your name\n");
    scanf("%s", new_student.name);
    printf("enter your last name\n");
    scanf("%s", new_student.lastname);
    printf("enter your username\n");
    scanf("%s", new_student.userName);
    printf("enter your gender 1-male  2_female\n");
    scanf("%d", &new_student.gender);
    int pass = 0;
    while (pass == 0) {
        printf("enter your password\n ");
        scanf("%s", new_student.password);
        char *msg = check_pass(new_student.password, &pass);
        if (msg != NULL) {
            printf("%s\n", msg);
        }
    }
    printf("enter your student-number\n");
    scanf("%d", &new_student.studentNum);
    new_student.status = 0;
    signup_student(new_student);

        printf( "\t\t\tsign up successfully\n\t\t\t"
                       "wait for responsible accept\n\t\t\t"
                       "thank you");

    }

void loginStudentHandler() {
    char userName[20];
    char password[20];
    printf("enter your username\n");
    scanf("%s", userName);
    printf("enter your password \n");
    scanf("%s", password);
    int j;
    int result = login_student(userName, password, &j);
    if(result==0){
    printf( "login successfully \n");
        studentMenuHandler(j);
    }
    else{  printf( "you are not active yet \n wait for accept\n thank you\n");}
}

void signUpResponsibleHandler() {
    struct responsible new_responsible;
    printf("enter your name\n");
    scanf("%s", new_responsible.name);
    printf("enter your last name\n");
    scanf("%s", new_responsible.lastname);
    printf("enter your personal id\n ");
    scanf("%d", &new_responsible.personal_id);
    printf("enter your username\n");
    scanf("%s", new_responsible.username);
    int pass = 0;
    while (pass==0) {
        printf("enter your password \n");
        scanf("%s", new_responsible.password);
        char *tmp = check_pass(new_responsible.password, &pass);
        if (tmp != NULL) {
            printf("%s", tmp);
        }
    }
    signup_responsible(new_responsible);
    printf("you sign in successfully\n"
           "log_in to see the menu");
}

void loginResponsibleHandler() {
    char userName[20];
    char password[20];
    int j;
    printf("enter your username\n");
    scanf("%s", userName);
    printf("enter your password ");
    scanf("%s", password);
    char *tmp = login_responsible(userName, password, &j);
    printf("%s", tmp);
    responsibleMenuHandler(j);
}

int authenticationHandler(int chosenRole, int chosenAction) {
    if (chosenRole == student && chosenAction == signUp) {
        signUpStudentHandler();
    }
    if (chosenRole == student && chosenAction == login) {
         loginStudentHandler();

    }
    if (chosenRole == responsible && chosenAction == signUp) {
        signUpResponsibleHandler();
    }
    if (chosenRole == responsible && chosenAction == login) {
        loginResponsibleHandler();
    }
}

void responsibleMenuHandler(j) {
    // while (true) {
    printf("\t\t\t**home menu"
           "\n1-student setting"
           "\n2-food setting"
           "\n3--publish announcement"
           "\n4-sign-out");
    int responsible_choose, student_setting, food_setting_choise;
    scanf("%d", &responsible_choose);
    if (responsible_choose == student_set) {
        //while ((true)) {
        printf("\t\t\tstudent setting menu\t\t\t\n\n"
               "1-confirm new students\n"
               "2-change student password\n"
               "3-delete student\n"
               "4-deActive student\n"
               "5-sign up student\n"
               "6-charge_student_account\n"
               "7_exit\n");

    }
}

void studentMenuHandler(int j) {
    // while (true) {
    printf("\t\t\t\t*home student menu"
           "\n1-chang_password"
           "\n2-see food menu and reserve"
           "\n3- announcement"
           "\n4-reservations"
           "\n5_charge_account(or send charge)"
           "\n6_sign_out\n");
}

void startTerminalUI() {
    while (true) {
        welcomePage();
        int chosenRole, chosenAction;
        chosenRole = showAndGetRoleMenu();
        chosenAction = showAndGetActionMenu();

        authenticationHandler(chosenRole, chosenAction);

        if (chosenAction == out) {
            break;
        }
    }
}

int main() {
    startTerminalUI();
}