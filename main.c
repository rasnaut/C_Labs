#include "massiv.h"
#include "dialog.h"

int main() {
    size_t len = 0, len_9 = 0;
    size_t capacity = 0, capacity_9 = 0;
    int *mas = NULL, *mas_9 = NULL;
    int num;
    do {
        printf("-----MENU-----\n");
        printf("(1) -> Array initialization\n");
        printf("(2) -> New element\n");
        printf("(3) -> Delete element\n");
        printf("(4) -> Data processing\n");
        printf("(5) -> Current state output\n");
        printf("Input number from 1 to 5 (Ctrl + D for Exit): ");
        check(&num);  
        switch(num) {
            case 0: printf("Exit...");                                                     break;
            case 1: make_array(&mas, &len, &capacity);                arr_out(&mas, &len); break;
            case 2: insert_element_to_array(&mas, &len, &capacity);   arr_out(&mas, &len); break;
            case 3: delete_element_from_array(&mas, &len, &capacity); arr_out(&mas, &len); break;
            case 4: special_operation_dev_9(&mas, &mas_9, &len, &capacity, &len_9, &capacity_9); break;
            case 5: current_state_output(&mas, &len, &mas_9, &len_9);                      break;
            default:
                printf("Incorrect choice number = %d!\n", num);
                break;
        }
    } while(num);
    free_arr(&mas, &len, &capacity);
    free_arr(&mas_9, &len_9, &capacity_9);
    return 0;
}
