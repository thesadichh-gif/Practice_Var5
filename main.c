#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#include "sort.h"
#include "file_io.h"
#include "menu.h"

int main() {
    setlocale(LC_ALL, "Russian");
    srand((unsigned int)time(NULL));

    int* arr = NULL;
    int size = 0;
    int choice = -1;

    char filename[100];

    while (choice != 0) {
        print_menu_text();
        
        if (scanf("%d", &choice) != 1) {
            printf("Некорректный ввод. Попробуйте еще раз.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                int n, min_v, max_v;
                printf("Количество элементов: ");
                scanf("%d", &n);
                
                if (n <= 0) {
                    printf("Количество должно быть больше нуля!\n");
                    break;
                }

                printf("Минимальное значение: ");
                scanf("%d", &min_v);
                printf("Максимальное значение: ");
                scanf("%d", &max_v);

                if (min_v > max_v) {
                    printf("Ошибка: минимум больше максимума.\n");
                    break;
                }

                if (arr != NULL) free(arr);
                
                arr = generate_random_array(n, min_v, max_v);
                size = n;
                printf("Массив успешно сгенерирован.\n");
                
                printf("Введите имя файла для сохранения исходного массива (например, input.csv): ");
                scanf("%s", filename);
                
                save_to_csv(filename, arr, size);
                break;
            }
            case 2: {
                printf("Введите имя файла для загрузки (например, input.csv): ");
                scanf("%s", filename);
                
                int new_size = 0;
                int* new_arr = load_from_csv(filename, &new_size);
                
                if (new_arr != NULL) {
                    if (arr != NULL) free(arr);
                    arr = new_arr;
                    size = new_size;
                    printf("Успешно загружено %d элементов.\n", size);
                }
                break;
            }
            case 3: {
                if (arr == NULL || size == 0) {
                    printf("Сначала создайте или загрузите массив!\n");
                } else {
                    clock_t start_time = clock();
                    
                    shell_sort(arr, size);
                    
                    clock_t end_time = clock();
                    
                    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
                    
                    printf("Массив отсортирован алгоритмом Шелла.\n");
                    printf("Затраченное время: %.6f секунд.\n", time_spent);
                    
                    printf("Введите имя файла для сохранения результата (например, output.csv): ");
                    scanf("%s", filename);
                    
                    save_to_csv(filename, arr, size);
                }
                break;
            }
            case 4: {
                print_array(arr, size);
                break;
            }
            case 0:
                printf("До свидания!\n");
                break;
            default:
                printf("Неверный пункт меню. Попробуйте еще раз.\n");
        }
    }

    if (arr != NULL) {
        free(arr);
    }

    return 0;
}
