#include "massiv.h"

int init_arr(int **mas, size_t *len, size_t* capacity) {
    if(len == NULL || mas == NULL || capacity == NULL || len == NULL) {
        return -1;
    }
    if(*capacity == 0) { *capacity = 1; }
    if(*len      != 0) { *len      = 0; }
    
    *mas = calloc(*capacity, sizeof(int));
    if(*mas == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    return 0;
}

int push_back(int **mas, size_t *len, size_t *capacity, int value) {
    return insert_element(mas, len, (*len)+1, capacity, value);
}

/*array output*/
int arr_out(int **mas, size_t *len) {
    if(mas == NULL || *mas == NULL || len == NULL || *len == 0) {
        printf("Array is empty!\n");
        return -1;
    }
    printf("Array elements:\n");
    printf("Array length: %ld\n", *len);
    for (size_t i = 0; i < *len; i++) {
        printf("Array element #%ld: %d", i + 1, (*mas)[i]);
        printf("\n");
    }
    printf("Done\n");
    return 0;
}

/*add element func*/
int insert_element(int **mas, size_t *len, size_t position, size_t* capacity, int value) {
    if (position <= 0) {
        printf("Position is not found in array\n");
        return -1; /*index is not found in array*/
    }
    size_t indx = position - 1; /*for user*/
    if(*len >= *capacity) {
        size_t new_capacity = (*capacity == 0) ? 1 : (*capacity * 2);
        int *new_mas = realloc(*mas, new_capacity * sizeof(int));
        if(new_mas == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        *mas = new_mas;
        *capacity = new_capacity;
    }
    
    if (indx > *len) {
        indx = *len;
    }
    int i = *len - 1;
    printf("i = %d, indx = %ld\n", i, indx); // Debug print
    while (i >= (int)indx) {
        (*mas)[i + 1] = (*mas)[i];
        i--;
    }
    printf("Inserting at index: %ld\n", indx); // Debug print
    (*mas)[indx] = value;
    (*len)++;
    return 0;
}

/*delete element*/
int del_element(int **mas, size_t *len, size_t *capacity, size_t position_del) {
    size_t inx = position_del - 1; /*for user*/
    if (inx >= *len) {
        printf("Index is out of range\n");
        return -1;
    }
    size_t i = inx;
    while (i < (*len - 1)) { /* <= --> < */
        (*mas)[i] = (*mas)[i + 1];
        i++;
    }
    if(*len*2 < *capacity) {
        size_t new_capacity = *capacity / 2;
        int *new_mas = realloc(*mas, new_capacity * sizeof(int));
        if(new_mas == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        *mas = new_mas;
        *capacity = new_capacity;
    }

    (*len)--;
    return 0;
}

int free_arr(int **mas, size_t *len, size_t *capacity) {
    if(mas == NULL || *mas == NULL) {
        return -1;
    }
    free(*mas);
    *mas = NULL;
    *len = 0;
    *capacity = 0;
    return 0;
}

/*elements devided by 9 func*/
int dev_9(int **mas, int **mas_9, size_t *len, size_t *capacity, size_t *len_9, size_t *capacity_9) {
    if(mas == NULL || *mas == NULL || len == NULL || *len <= 0 || len_9 == NULL) {
        printf("Invalid input\n");
        return -1;
    }
    *len_9 = 0;
    *capacity_9 = *len/2;
    init_arr(mas_9, len_9, capacity_9);
    for (size_t i = 0; i < *len;) {
        if (((*mas)[i] % 9 == 0) && ((*mas)[i] != 0)) {
            push_back(mas_9, len_9, capacity_9, (*mas)[i]);
            del_element(mas, len, capacity, (i + 1)); /*for user*/
            continue; /*stay on the same index after deletion*/
        }
        i++;
    }
    return 0;
}
