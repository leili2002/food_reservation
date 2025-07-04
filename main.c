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

enum student_setting_menu {
    confirm = 1,
    change_pass = 2,
    delete = 3,
    de_active = 4,
    sign_up = 5,
    charge_account = 6,
    exittt = 7,
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

    printf("\t\t\tsign up successfully\n\t\t\t"
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
    if (result == 0) {
        printf("login successfully \n");
        studentMenuHandler(j);
    } else { printf("you are not active yet \n wait for accept\n thank you\n"); }
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
    while (pass == 0) {
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
        while ((true)) {
            printf("\t\t\tstudent setting menu\t\t\t\n\n"
                   "1-confirm new students\n"
                   "2-change student password\n"
                   "3-delete student\n"
                   "4-deActive student\n"
                   "5-sign up student\n"
                   "6-charge_student_account\n"
                   "7_exit\n");
            scanf("%d", &student_setting);

            if (student_setting == confirm) {
                int flag = 0;
                char *student_info = check_student_status(&flag);
                if (flag == 1) {
                    //means find student with status di active
                    printf("Student info:\n%s", student_info);
                    printf("do you want to confirm this student?\n1-yes?2-no\n");
                    int confirm;
                    scanf("%d", &confirm);
                    if (confirm == 1) {
                        int studentnum;
                        printf("give student number again");
                        scanf("%d", &studentnum);

                        char *tmp = active_student(studentnum);
                        printf("%s be active", tmp);
                    }
                }
                if (flag == 0) {
                    printf("No student with status diactive found.\n");
                }
            }

            if (student_setting == change_pass) {

                printf("enter student number\n");
                int student_num;
                scanf("%d", &student_num);
                printf("enter new password ");
                char new_pass;
                scanf("%s", &new_pass);
                char *tmp = change_password(student_num, &new_pass);
                printf("\n%s\n", tmp);

            }

            if (student_setting == delete) {
                int student_number;
                printf("\nenter student number");
                scanf("%d", &student_number);
                char *tmp = delete_student(student_number);
                (printf("\n%s", tmp));


            }

            if (student_setting == de_active) {
                int student_num;
                printf("\nenter student number");
                scanf("%d", &student_num);
                char *tmp = deActive(student_num);
                printf("%s", tmp);

            }

            if (student_setting == sign_up) {
                struct student new_student;
                printf("enter student name\n");
                scanf("%s", new_student.name);
                printf("enter student last name\n");
                scanf("%s", new_student.lastname);
                printf("enter student username\n");
                scanf("%s", new_student.userName);
                int pass = 0;
                while (!pass) {
                    printf("enter student password\n ");
                    scanf("%s", new_student.password);
                    char *msg = check_pass(new_student.password, &pass);
                    if (msg != NULL) {
                        printf("%s", msg);
                    }
                }
                printf("enter student student-number\n");
                scanf("%d", &new_student.studentNum);
                printf("enter status of student (1-active 2-de active");
                scanf("%d", &new_student.studentNum);
                signup_student(new_student);
                printf("\nsignup %s %s successfully\n", new_student.name, new_student.lastname);
            }

            if (student_setting == charge_account) {
                printf(("enter student_num\n enter number of charge\n"));
                int student_num;
                float charge;
                scanf("%d %f", &student_num, &charge);
                char *tmp = charge_Account(student_num, charge);
                printf("%s\n", tmp);
            }

            if (student_setting == exittt) {
                break;
            }
        }
    }
}

void studentMenuHandler(j) {
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