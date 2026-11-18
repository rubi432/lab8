#include <stdio.h>
#include "myarrfunc.h"

#define MAX_SIZE 100

int main(void) {
    double arr[MAX_SIZE];
    size_t n = 0;
    char choice;

    while (1) {
        printf("\n--- МЕНЮ ---\n");
        printf("a. Задать размер массива\n");
        printf("b. Заполнить массив\n");
        printf("c. Представление массива (значения, адреса)\n");
        printf("d. Поиск индекса последнего отрицательного\n");
        printf("e. Количество элементов, кратных k\n");
        printf("f. Сумма элементов выше среднего\n");
        printf("g. Выход\n");
        printf("Выберите пункт: ");

        scanf(" %c", &choice);

        if (choice == 'a') {
            size_t new_size;
            printf("Введите размер массива (до %d): ", MAX_SIZE);
            scanf("%zu", &new_size);
            if (new_size > 0 && new_size <= MAX_SIZE) {
                n = new_size;
                printf("Размер установлен: %zu\n", n);
            } else {
                printf("Ошибка! Некорректный размер.\n");
            }
        } 
        else if (choice == 'b') {
            if (n == 0) { printf("Сначала задайте размер (пункт a)!\n"); continue; }
            printf("Введите %zu чисел через пробел:\n", n);
            for (size_t i = 0; i < n; i++) {
                scanf("%lf", &arr[i]);
            }
            printf("Массив заполнен.\n");
        } 
        else if (choice == 'c') {
            if (n == 0) { printf("Массив пуст!\n"); continue; }
            printf("Индекс | Значение | Адрес в памяти\n");
            for (size_t i = 0; i < n; i++) {
                printf("%6zu | %8.2f | %p\n", i, arr[i], (void*)&arr[i]);
            }
        } 
        else if (choice == 'd') {
            if (n == 0) { printf("Массив пуст!\n"); continue; }
            int idx = find_last_negative(arr, n);
            if (idx != -1) printf("Индекс последнего отрицательного: %d\n", idx);
            else printf("Отрицательных элементов нет.\n");
        } 
        else if (choice == 'e') {
            if (n == 0) { printf("Массив пуст!\n"); continue; }
            double k;
            printf("Введите число k: ");
            scanf("%lf", &k);
            int count = count_multiples(arr, n, k);
            printf("Количество элементов, кратных %.2f: %d\n", k, count);
        } 
        else if (choice == 'f') {
            if (n == 0) { printf("Массив пуст!\n"); continue; }
            double sum = sum_above_average(arr, n);
            printf("Сумма элементов выше среднего: %.2f\n", sum);
        } 
        else if (choice == 'g') {
            printf("Выход из программы...\n");
            break;
        } 
        else {
            printf("Неизвестный пункт меню!\n");
        }
    }
    return 0;
}