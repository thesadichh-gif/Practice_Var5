#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>


void print_array(int* arr, int n) {
    if (n == 0) {
        printf("Массив пуст.\n");
        return;
    }
    
    printf("Элементы массива:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int* generate_random_array(int n, int min_val, int max_val) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = min_val + rand() % (max_val - min_val + 1);
    }
    return arr;
}


void print_menu_text() {
    printf("\n--- Меню (Вариант 5) ---\n");
    printf("1. Сгенерировать случайный массив и сразу сохранить в файл\n");
    printf("2. Загрузить исходный массив из файла (CSV)\n");
    printf("3. Отсортировать массив (с замером времени) и сохранить в файл\n");
    printf("4. Вывести текущий массив на экран\n");
    printf("0. Выйти из программы\n");
    printf("Выберите действие: ");
}
