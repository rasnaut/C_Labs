#include <stdio.h>
#include <assert.h>
#include "massiv.h"  // 
#include "dialog.h"  // 

int main() {
    int *mas = NULL, *mas_9 = NULL;
    size_t len = 0, capacity = 0;
    size_t len_9 = 0, capacity_9 = 0;
    
    // Тест 1: Инициализация
    assert(init_arr(&mas, &len, &capacity) == 0);
    assert(len == 0);
    assert(capacity >= 1);
    printf("✅ Тест 1: init_arr OK\n");
    
    // Тест 2: push_back
    assert(push_back(&mas, &len, &capacity, 10) == 0);
    assert(len == 1);
    assert(mas[0] == 10);
    printf("✅ Тест 2: push_back OK\n");
    
    // Тест 3: insert_element в середину
    assert(insert_element(&mas, &len, 1, &capacity, 20) == 0);  // в начало
    assert(len == 2);
    assert(mas[0] == 20 && mas[1] == 10);
    printf("✅ Тест 3: insert_element OK\n");
    
    // Тест 4: вставка за конец (position = len+1)
    assert(insert_element(&mas, &len, 3, &capacity, 27) == 0);
    assert(len == 3);
    assert(mas[2] == 27);
    printf("✅ Тест 4: insert за конец OK\n");
    
    // Тест 5: del_element
    arr_out(&mas, &len);  // [20,10,27]
    assert(del_element(&mas, &len, &capacity, 2) == 0);  // удаляем 10
    assert(len == 2);
    assert(mas[0] == 20 && mas[1] == 27);
    printf("✅ Тест 5: del_element OK\n");
    
    // Тест 6: dev_9 (30 % 9 == 0)
    assert(insert_element(&mas, &len, 1, &capacity, 18) == 0);  // [18,20,27]
    printf("До dev_9:\n");
    arr_out(&mas, &len);
    
    assert(dev_9(&mas, &mas_9, &len, &capacity, &len_9, &capacity_9) == 0);
    
    printf("После dev_9 (оригинал):\n");
    arr_out(&mas, &len);     // должно быть [20, 27]
    printf("Делимые на 9:\n");
    arr_out(&mas_9, &len_9); // должно быть [18]
    
    printf("len = %ld, mas[0] = %d\n", len, mas[0]); // Debug print
    assert(len == 1 && mas[0] == 20 );
    assert(len_9 == 2 && mas_9[0] == 18 && mas_9[1] == 27);
    printf("✅ Тест 6: dev_9 OK\n");
    
    // Тест 7: free
    assert(free_arr(&mas, &len, &capacity) == 0);
    assert(free_arr(&mas_9, &len_9, &capacity_9) == 0);
    assert(mas == NULL && len == 0 && capacity == 0);
    printf("✅ Тест 7: free_arr OK\n");
    
    printf("🎉 Все тесты пройдены!\n");
    return 0;
}
