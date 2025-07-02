
#include<stdlib.h>
#include "repository.h"
#include <stdio.h>


// save_responsible saves an array of responsible and its size
void save_responsible(struct responsible responsible[], int size) {
    FILE *fr = fopen("../data/responsible_text.txt", "wb");
    fwrite(&size, sizeof(int), 1, fr);
    fwrite(responsible, sizeof(struct responsible), size, fr);
    fclose(fr);
}


struct responsible *load_responsible(int *size) {
    FILE *fr = fopen("../data/responsible_text.txt", "rb");
    if (!fr) {
        printf("Error opening file.\n");
        *size = 0;
        return NULL;
    }

    fread(size, sizeof(int), 1, fr);

    struct responsible *array = malloc(*size * sizeof(struct responsible));
    if (!array) {
        printf("responsibleArray allocation failed.\n");
        *size = 0;
        fclose(fr);
        return NULL;
    }

    fread(array, sizeof(struct responsible), *size, fr);
    fclose(fr);
    return array;
}
