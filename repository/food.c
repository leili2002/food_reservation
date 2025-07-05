//
// Created by Administrator on 7/5/2025.
//

#include<stdlib.h>
#include "repository.h"
#include <stdio.h>



void save_self(struct dailyself self[],size_t  size) {
    FILE *sp = fopen("../data/self_text.txt", "wb");

    fwrite(&size, sizeof(int), 1, sp);
    fwrite(self, sizeof(struct dailyself), size, sp);
    fclose(sp);
}



struct dailyself * load_selfs(size_t * count) {
    FILE* sp = fopen("../data/self_text.txt", "rb");
    if (sp == NULL) {
        printf("Error opening file.\n");
        *count = 0;
        return NULL;
    }

    fread(count, sizeof(size_t), 1, sp);
    struct dailyself *temp = malloc(*count * sizeof(struct dailyself));
    if (temp == NULL) {
        printf(" failed.\n");
        *count = 0;
        fclose(sp);
        return NULL;
    }

    fread(temp, sizeof(struct dailyself), *count, sp);
    fclose(sp);
    return temp;
}


void save_reservation(struct reserve reserves[],size_t  size) {
    FILE *bp = fopen("../data/reserve_text.txt", "wb");

    fwrite(&size, sizeof(int), 1, bp);
    fwrite(reserves, sizeof(struct reserve), size, bp);
    fclose(bp);
}



struct reserve* load_reserves (size_t * count) {
    FILE* bp = fopen("../data/reserve_text.txt", "rb");
    if (bp == NULL) {
        printf("Error opening file.\n");
        *count = 0;
        return NULL;
    }

    fread(count, sizeof(size_t), 1, bp);
    struct reserves *temp = malloc(*count * sizeof(struct reserve));
    if (temp == NULL) {
        printf(" failed.\n");
        *count = 0;
        fclose(bp);
        return NULL;
    }

    fread(temp, sizeof(struct reserve), *count, bp);
    fclose(bp);
    return (struct reserve *) temp;
}