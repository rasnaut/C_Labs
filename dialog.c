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
            *num = 0;
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
    int ln = 0;
    printf("Input array length:\n");
    check(&ln);
    *len = 0;
    if (ln <= 0) {
        printf("Array length is zero or negative, nothing to initialize.\n");
        return -1;
    }
    *capacity = (size_t)ln;
    int success = init_arr(mas, len, capacity);
    if (success != 0) {
        printf("Failed to initialize array\n");
        return -1;
    }
    
    for (size_t i = 0; i < *capacity; i++) {
        printf("Input %ld element: ", i + 1); /*usless*/
        int input_value;
        check(&input_value);
        success = push_back(mas, len, capacity, input_value);
        if (success != 0) {
            printf("Failed to push back element with index %ld and value %d\n", i + 1, input_value);
            return -1;
        }
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
    printf("Enter position of new element from 1 to %ld: ", *len + 1);
    check(&position);
    if(position <= 0 || position > (int)(*len + 1)) {
        printf("Position must be between 1 and %ld!\n", *len + 1);
        return -1;
    }
    printf("Enter value of insert: ");
    check(&value);
    
    int status = insert_element(mas, len, position, capacity, value);
    if (status != 0) {
        printf("Failed to insert element at position %d with value %d\n", position, value);
    }
    return status;
}

int delete_element_from_array(int **mas, size_t *len, size_t *capacity)
{
    int index_del;
    printf("Enter position delete element from 1 to %ld: ", *len);
    check(&index_del);
    if(index_del <= 0 || index_del > (int)(*len)) {
        printf("Position must be between 1 and %ld!\n", *len);
        return -1;
    }
    int status = del_element(mas, len, capacity, (size_t)index_del);
    if (status != 0) {
        printf("Failed to delete element at index %d\n", index_del);       
    }
    return status;
}

int current_state_output(int **mas, size_t *len, int **mas_9, size_t *len_9)
{
    int num1;
    bool flag = false;
    int status = 0;
    while(flag == false) {
        flag = true;
        printf("1) -> standart_array\n");
        printf("2) -> ind_task_array\n");
        printf("Choose array: ");
        check(&num1);
        switch(num1) {
            case 1: 
                status = arr_out(mas, len);     
                if (status != 0) {
                    printf("Failed to output standard array\n");
                }
            break;
            case 2: 
                status = arr_out(mas_9, len_9);
                if (status != 0) {
                    printf("Failed to output special array\n");
                }
                break;
            default:
                flag = false;
                printf("Incorrect value!\n");
        }
    };
    
    return 0;
}

int special_operation_dev_9(int **mas, int **mas_9, size_t *len, size_t *capacity, size_t *len_9, size_t *capacity_9) {
    int status = dev_9(mas, mas_9, len, capacity, len_9, capacity_9);
    if (status != 0) {
        printf("Failed to compute special array\n");
        return -1;
    }
    printf("Array (9) elements:\n");
    return arr_out(mas_9, len_9);
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
