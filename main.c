#include "massiv.h"
#include "dialog.h"

int main() {
    size_t len = 0, len_9 = 0;
    size_t capacity = 0, capacity_9 = 0;
    int *mas = NULL, *mas_9 = NULL;
    mas = NULL;
    int num;
    size_t index, index_del;
    int value;
    int num1;
    bool flag = false;

    do {
        printf("-----MENU-----\n");
        printf("(0) -> Exit\n");
        printf("(1) -> Array initialization\n");
        printf("(2) -> New element\n");
        printf("(3) -> Delete element\n");
        printf("(4) -> Data processing\n");
        printf("(5) -> Current state output\n");
        printf("Input number from 0 to 5: ");
        check(&num);  /*��������� ��� ������� check*/
        switch(num) {
            case 0:
                printf("Exit...");
                break;
            case 1:
                make_ar(&mas, &len, &capacity);
                printf("Array elements:\n");
                arr_out(&mas, &len);
                break;
            case 2:
                printf("Enter value of insert: ");
                check(&value);
                printf("Enter index of insert: ");
                check((int*)&index);
                insert_element(&mas, &len, index, &capacity, value);
                arr_out(&mas, &len);
                break;
            case 3:
                printf("Enter index to delete: ");
                check((int*)&index_del);
                del_element(&mas, &len, &capacity, index_del);
                arr_out(&mas, &len);
                break;
            case 4:
                dev_9(&mas, &mas_9, &len, &capacity, &len_9, &capacity_9);
                printf("Array (9) elements:\n");
                arr_out(&mas_9, &len_9);
                break;
            case 5:
                    do {
                        printf("1) -> standart_array\n");
                        printf("2) -> ind_task_array\n");
                        printf("Choose array: ");
                        check(&num1);
                        switch(num1) {
                            case 1:
                                if(mas == NULL) {
                                    printf("Array is empty!\n");
                                    flag = true;
                                }
                                else{
                                    arr_out(&mas, &len);
                                    flag = true;
                                }
                                break;
                            case 2:
                                if(mas_9 == NULL) {
                                    printf("Array is empty!\n");
                                    flag = true;
                                }
                                else {
                                    arr_out(&mas_9, &len_9);
                                    flag = true;
                                }
                                break;
                            default:
                                printf("Incorrect value!\n");
                                break;
                        }
                    }while(flag == false);
                    flag = false;
                    break;
            default:
                printf("Incorrect value!\n");
                break;
        }
    } while(num);
    free_arr(&mas, &len, &capacity);
    free_arr(&mas_9, &len_9, &capacity_9);
    return 0;
}
