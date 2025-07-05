//
// Created by Administrator on 7/2/2025.
//

#include <stdio.h>
#include <string.h>
#include "repository/repository.h"
#include "logic/logic.h"

void studentMenuHandler(int j);

void responsibleMenuHandler(int j);

enum role {
    student = 1,
    responsible = 2,
};

enum food_setting_choise {
    define_new_self = 1,
    define_foods = 2,
    reports = 3,
    exitt = 4,

};

enum report_choose {
    food_reports = 1,
    person_report = 2,
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


const char *get_day_string(enum day d) {
    switch (d) {
        case shanbeh:
            return "shanbeh";
        case yekshanbeh:
            return "yekshanbeh";
        case doshanbeh:
            return "doshanbeh";
        case seshanbeh:
            return "seshanbeh";
        case charshanbeh:
            return "charshanbeh";
        default:
            return "unknown";
    }
}

void printFoodArray(struct food foods[], int count) {
    for (int i = 0; i < count; i++) {
        printf("    Food: %s, price: %f :\n", foods[i].name, foods[i].price);
    }
}

void get_food(struct food *food, int count) {

    for (int j = 0; j < count; j++) {
        printf("enter[%d]food name\n", j);
        getchar();
        fgets(food[j].name, 100, stdin);
        printf("enter %s price\n ", food[j].name);
        scanf("%d", &food[j].price);
    }
}





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
    while (true) {
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
        if (responsible_choose == food_setting) {
            printf("1_define_self\n"
                   "2_define_foods for self(if you dont define self please define it first\n"
                   "3_reports"
                   "4-sign_out");

            scanf("%d", &food_setting_choise);
            if (food_setting_choise == define_new_self) {

                struct dailyself self;
                int awnser;

                printf("enter  self name");
                fgets(self.name, 100, stdin);
                self.name[strcspn(self.name, "\n")] = '\0';
                printf("enter capacity and gender (1-male 2-female for self %s", self.name);
                scanf("%d %d", &self.capacity, &self.gender);
                printf("enter  self %s location", self.name);
                getchar();
                fgets(self.location, 100, stdin);
                while (true) {
                    printf("enter a uniq id for %s self\n ", self.name);
                    scanf("%d", &self.id);
                    int *tmp = search_id(self.id);
                    if (tmp != 0) { break; }
                }
                put_in_array(self);
                printf("self%s saved\n if you want add food plan to it go to define food part \n"
                       "do you want go to former menu?(1-yes 2-no)", self.name);
                scanf("%d", &awnser);
                if (awnser == 1) {
                    break;
                }
                continue;
            }
            if (food_setting_choise == define_foods) {
                size_t count = 0;
                int input_id;
                struct dailyself *array_of_selfs = load_selfs(&count);
                printf("enter self id \n");
                scanf("%d", &input_id);
                for (int i = 0; i < count; i++) {
                    if (array_of_selfs[i].id == input_id) {

                        printf("how many food for lunch and dinner in shanbeh do you want add\n?");
                        int lunch_shanbe_count, dinner_shanbe_count;
                        scanf("%d %d", &lunch_shanbe_count, &dinner_shanbe_count);
                        array_of_selfs[i].lunch_shanbeh_count = lunch_shanbe_count;
                        array_of_selfs[i].dinner_shanbeh_count = dinner_shanbe_count;
                        get_food(array_of_selfs[i].lunch_shanbeh, lunch_shanbe_count);
                        get_food(array_of_selfs[i].dinner_shanbeh, dinner_shanbe_count);


                        printf("how many food for lunch and dinner in yekshanbeh do you want add\n?");
                        int lunch_yekshanbe_count, dinner_yekshanbe_count;
                        scanf("%d %d", &lunch_yekshanbe_count, &dinner_yekshanbe_count);
                        array_of_selfs[i].lunch_yekshanbeh_count = lunch_yekshanbe_count;
                        array_of_selfs[i].dinner_yekshanbeh_count = lunch_yekshanbe_count;
                        get_food(array_of_selfs[i].lunch_yekshanbeh, lunch_yekshanbe_count);
                        get_food(array_of_selfs[i].dinner_yekshanbeh, dinner_yekshanbe_count);


                        printf("how many food for lunch and dinner in doshanbeh do you want add\n?");
                        int lunch_doshanbe_count, dinner_doshanbe_count;
                        scanf("%d %d", &lunch_doshanbe_count, &dinner_doshanbe_count);
                        array_of_selfs[i].lunch_doshanbeh_count = lunch_doshanbe_count;
                        array_of_selfs[i].dinner_doshanbeh_count = dinner_doshanbe_count;
                        get_food(array_of_selfs[i].lunch_doshanbeh, lunch_doshanbe_count);
                        get_food(array_of_selfs[i].dinner_doshanbeh, dinner_doshanbe_count);


                        printf("how many food for lunch and dinner in seshanbeh do you want add\n?");
                        int lunch_seshanbe_count, dinner_seshanbe_count;
                        scanf("%d %d", &lunch_seshanbe_count, &dinner_seshanbe_count);
                        array_of_selfs[i].lunch_seshanbe_count = lunch_seshanbe_count;
                        array_of_selfs[i].dinner_seshanbeh_count = dinner_seshanbe_count;
                        get_food(array_of_selfs[i].lunch_seshanbeh, lunch_seshanbe_count);
                        get_food(array_of_selfs[i].dinner_seshanbeh, dinner_seshanbe_count);


                        printf("how many food for lunch and dinner in charshanbeh  do you want add\n?");
                        int lunch_charshanbe_count, dinner_charshanbe_count;
                        scanf("%d %d", &lunch_charshanbe_count, &dinner_charshanbe_count);
                        array_of_selfs[i].lunch_charshanbeh_count = lunch_charshanbe_count;
                        array_of_selfs[i].dinner_charshanbe_count = dinner_charshanbe_count;
                        get_food(array_of_selfs[i].lunch_charshanbeh, lunch_charshanbe_count);
                        get_food(array_of_selfs[i].dinner_charshanbeh, dinner_charshanbe_count);

                        printf("food plan for a week saves\n");
                        update_self(array_of_selfs[i], i);
                        printf("self %s saved with your food plane\n", array_of_selfs[i].name);
                    }


                }

            }
            if (food_setting_choise == reports) {
                int report_choose, food_reports_by;
                printf(" chose your wanted report\n"
                       "1-reports of reserves of food \n"
                       "2_ reports of person performance \n");
                scanf("%d ", &report_choose);
                if (report_choose == food_reports) {
                    printf("1_total food report\n 2_reports by self\n");
                    scanf("%d", &food_reports_by);
                    if (food_reports_by == 1) {
                        size_t size = 0;
                        struct reserve *reserves = food_report(&size);
                        for (int i = 0; i < size; i++) {
                            printf("self name:%s | day:%s | meal:%s | food name:%s",
                                   reserves[i].self_name, get_day_string(reserves[i].day),
                                   reserves[i].meal, reserves[i].food);

                        }
                    }
                    if (food_reports_by == 2) {
                        char self_name;
                        int self_food_count;
                        printf("enter self name\n");
                        getchar();
                        fgets(&self_name, 100, stdin);
                        struct reserve *self_food = food_reports_by_self(&self_name, &self_food_count);
                        printf("number of food reservation in %s self is %d\n ", self_name, self_food_count);
                        for (int i = 0; i < self_food_count; i++) {
                            printf("day:%s | meal:%s | food_name:%s", get_day_string(self_food[i].day),
                                   self_food[i].meal, self_food[i].food);
                        }

                    }

                }
                if (report_choose == person_report) {
                    int student_num;
                    printf("enter student_number \n");
                    scanf("%d", &student_num);
                    struct reserve *student_reports = student_report(student_num);
                    for (int i = 0; i < 13; i++) {
                        printf("self name:%s | day:%s | meal:%s | food name:%s",
                               student_reports[i].self_name, get_day_string(student_reports[i].day),
                               student_reports[i].meal, student_reports[i].food);
                    }

                }

            }
            if (food_setting_choise == exitt){
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