#include <stdio.h>
#include <stdbool.h>
#include "dialog.h"
#include "massiv.h"

int check(int *num) {
    int val;
    int chk;
    bool state = false;
    while(state == false) {
        chk = scanf("%d", &val);
        if (chk == EOF) {
            return -1;
        }
        if (chk != 1) {
            printf("Incorrect value!\n");
            printf("Try again: ");
            int c;
            while((c = getchar()) != '\n' && c != EOF);
        }
        else {
            state = true;
            break;
        }
    }
    *num = val;
    return 0;
}

/*array create func*/
int make_ar(int **mas, size_t *len, size_t *capacity) {
    size_t ln;
    printf("Input array length:\n");
    check((int*)&ln);
    *len = ln;
    *capacity = ln;
    init_arr(mas, len, capacity);
    printf("Input array elements:\n");

    for (size_t i = 0; i < ln; i++) {
        printf("Input %ld element: ", i + 1); /*usless*/
        int input_value;
        check(&input_value);
        push_back(mas, len, capacity, input_value);
        printf("Value mas[%ld]: %d", i + 1, (*mas)[i]);
        printf("\n");
    }
    printf("Done\n");
    return 0;
}