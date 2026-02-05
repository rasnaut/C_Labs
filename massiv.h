#ifndef MASSIV_PROG
#define MASSIV_PROG

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int init_arr(int **mas, size_t *len, size_t* capacity);

int insert_element(int **mas, size_t *len, size_t position, size_t* capacity, int value);
int push_back(int **mas, size_t *len, size_t *capacity, int value);

int del_element(int **mas, size_t *len, size_t *capacity, size_t position_del);

int dev_9(int **mas, int **mas_9, size_t *len, size_t *capacity, size_t *len_9, size_t *capacity_9);

int check(int *num);

int free_arr(int **mas, size_t *len, size_t *capacity);

#endif
