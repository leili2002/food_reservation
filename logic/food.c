//
// Created by Administrator on 7/5/2025.
//


#include "../repository/repository.h"
#include<stdlib.h>
#include <string.h>


int *search_id(int id) {
    size_t count;

    struct dailyself *array_of_selfs = load_selfs(&count);
    for (int i = 0; i < count; i++) {
        if (array_of_selfs[i].id == id) {
            return 0;
        }
    }
}


void put_in_array(struct dailyself new_self) {   //make new array of structs +new structs and +size
    size_t size = 0;
    struct dailyself *self_array = load_selfs(&size);
    struct dailyself *temp = realloc(self_array, (size + 1) * sizeof(struct dailyself));
    self_array = temp;
    self_array[size + 1] = new_self;
    size++;
    save_self(self_array, size);
    free(self_array);

}

void update_self(struct dailyself update_self, int index) { //update self after change any structs in there
    size_t size = 0;
    struct dailyself *self_array = load_selfs(&size);
    self_array[index] = update_self;
    save_self(self_array, size);
}

int check_self(int gender, const char *self_name) {          //check capacity and gender
    size_t size = 0;
    int flag = 0;
    struct dailyself *self_array = load_selfs(&size);
    for (int i = 0; i < size; i++) {
        if (strcmp(self_array[i].name, self_name) == 0) {
            if ((self_array[i].gender == gender) && (self_array[i].capacity > 0)) {
                flag = 1;
                self_array[i].capacity--;
                update_self(self_array[i], i);
                return flag;
            }

        }
    }
    return flag;
}

void add_Reserve(struct reserve new_reserve) {        //add the reservation of student to array  of reservation
    size_t size = 0;
    struct reserve *reserve_array = load_reserves(&size);
    struct reserve *temp = realloc(reserve_array, (size + 1) * sizeof(struct reserve));
    reserve_array = temp;
    reserve_array[size + 1] = new_reserve;
    size++;
    save_reservation(reserve_array, size);
    free(reserve_array);
}

struct reserve *reserve_student_list(int j) {              // student reservation list shown to student
    int count = 0;
    int k = 0;
    int student_id = 0;
    static struct reserve array[11];
    struct student *student_array = load_student(&count);
    student_array[j].studentNum = student_id;
    size_t size = 0;
    struct reserve *reserve_array = load_reserves(&size);
    for (int i = 0; i < size; i++) {
        if (reserve_array[i].student_id == student_id) {
            if (k < 11) {
                array[k] = reserve_array[i];
                k++;
            }
        }
    }
    return array;
}


struct reserve *food_report(size_t *count) {
    size_t size = 0;
    struct reserve *reserve_array = load_reserves(&size);
    *count = size;
    return reserve_array;
}


struct reserve *food_reports_by_self(const char *name, int *out_count) {
    size_t size = 0;
    int match_count = 0;
    struct reserve *reserve_array = load_reserves(&size);
    struct reserve *matches = malloc(size * sizeof(struct reserve));
    for (int i = 0; i < size; i++) {
        if (strcmp(reserve_array[i].self_name, name) == 0) {
            matches[match_count++] = reserve_array[i];
        }
    }
    struct reserve *result = realloc(matches, match_count * sizeof(struct reserve));
    if (result == NULL && match_count > 0) {
        result = matches;
    }

    *out_count = match_count;
    return result;
}

struct reserve* student_report(int student_num) {
    int size = 0;
    struct student *student_array = load_student(&size);
    for (int i = 0; i < size; i++) {
        if (student_array[i].studentNum == student_num) {

            reserve_student_list(i);
        }
    }
}
