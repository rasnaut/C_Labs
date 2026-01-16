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
int make_array(int **mas, size_t *len, size_t *capacity) {
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

int insert_element_to_array(int **mas, size_t *len, size_t *capacity)
{
    int value;
    int position;
    printf("Enter value of insert: ");
    check(&value);
    printf("Enter index of insert: ");
    check(&position);
    return insert_element(mas, len, position, capacity, value);
}

int delete_element_from_array(int **mas, size_t *len, size_t *capacity)
{
    size_t index_del;
    printf("Enter index to delete: ");
    check((int*)&index_del);
    return del_element(mas, len, capacity, index_del);
}

int current_state_output(int **mas, size_t *len, int **mas_9, size_t *len_9)
{
    int num1;
    bool flag = false;
    while(flag == false) {
        flag = true;
        printf("1) -> standart_array\n");
        printf("2) -> ind_task_array\n");
        printf("Choose array: ");
        check(&num1);
        switch(num1) {
            case 1: arr_out(mas, len);     break;
            case 2: arr_out(mas_9, len_9); break;
            default:
                flag = false;
                printf("Incorrect value!\n");
        }
    };
    
    return 0;
}

int special_operation_dev_9(int **mas, int **mas_9, size_t *len, size_t *capacity, size_t *len_9, size_t *capacity_9) {
    dev_9(mas, mas_9, len, capacity, len_9, capacity_9);
    printf("Array (9) elements:\n");
    return arr_out(mas_9, len_9);
}
