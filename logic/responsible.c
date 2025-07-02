//
// Created by Administrator on 7/2/2025.
//

#include "../repository/repository.h"
#include<stdlib.h>
#include <string.h>

void signup_responsible(struct responsible new_responsible) {
    int size = 0;
    struct responsible *responsible_array = load_responsible(&size);
    if (responsible_array == NULL) {
        responsible_array = malloc(sizeof(struct responsible));}
    else{
    struct responsible *temp = realloc(responsible_array, (size + 1) * sizeof(struct responsible));
    responsible_array = temp;}
    responsible_array[size] = new_responsible;
    size++;
    save_responsible(responsible_array, size);
    free(responsible_array);

}


char *login_responsible(char *userName, char *password, int *j) {
    int size = 0;
    struct responsible *responsible_array = load_responsible(&size);
    for (int i = 0; i < size; i++) {
        if (strcmp(responsible_array[i].username, userName) == 0 &&
            (strcmp(responsible_array[i].password, password) == 0)) {
            (*j) = i;
            return ("login successfully \n");
        }
    } return ("login failed");
}

