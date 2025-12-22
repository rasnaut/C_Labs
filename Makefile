# Makefile для проекта динамического массива
# Компилятор и флаги
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic -O2
# CFLAGS_DEBUG = -std=c99 -Wall -Wextra -g -fsanitize=address -fsanitize=undefined
LDLIBS = 

# Цели по умолчанию
.PHONY: all clean test debug valgrind valgrind_test

# Основная программа
all: main

# Тесты
test: main_test
	@./main_test && echo "✅ Все тесты пройдены!" || echo "❌ Тесты провалены!"

# Компиляция основной программы
main: main.c dialog.c massiv.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

# Компиляция тестов
main_test: main_test.c dialog.c massiv.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

# Отдельная компиляция модулей (для отладки)
massiv.o: massiv.c massiv.h
	$(CC) $(CFLAGS) -c -o $@ $<

dialog.o: dialog.c dialog.h
	$(CC) $(CFLAGS) -c -o $@ $<

# Debug сборка с AddressSanitizer
debug: CFLAGS += -g -fsanitize=address -fsanitize=undefined
debug: main main_test

# Valgrind для поиска утечек памяти
valgrind: main
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main

valgrind_test: main_test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main_test

# Очистка
clean:
	rm -f main main_test *.o core vgcore.*

# Быстрый запуск тестов + valgrind
check: test valgrind_test

# Пересборка всего
rebuild: clean all test
