#define _CRT_SECURE_NO_WARNINGS
#include "file_io.h"
#include <stdio.h>
#include <stdlib.h>


int* load_from_csv(const char* filename, int* size) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка: Не удалось открыть файл %s\n", filename);
        return NULL;
    }

   
    int count = 0;
    int temp;
    while (fscanf(file, "%d,", &temp) == 1) {
        count++;
    }

    
    if (count == 0) {
        printf("Файл пуст или содержит неверные данные.\n");
        fclose(file);
        return NULL;
    }

    
    rewind(file);

    
    int* arr = (int*)malloc(count * sizeof(int));
    *size = count;

    
    for (int i = 0; i < count; i++) {
        fscanf(file, "%d,", &arr[i]);
    }

    fclose(file);
    return arr;
}


void save_to_csv(const char* filename, int* arr, int n) {
    if (n == 0) {
        printf("Массив пуст, нечего сохранять.\n");
        return;
    }

    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Ошибка: Не удалось создать файл %s\n", filename);
        return;
    }

    
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d", arr[i]);
        if (i < n - 1) {
            fprintf(file, ",");
        }
    }

    fclose(file);
    printf("Данные успешно сохранены в файл: %s\n", filename);
}
