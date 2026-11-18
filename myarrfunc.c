#include "myarrfunc.h"

//  Поиск индекса последнего отрицательного
int find_last_negative(double *arrptr, size_t n) {
    int last_index = -1;
    for (size_t i = 0; i < n; i++) {
        if (*(arrptr + i) < 0) {
            last_index = i;
        }
    }
    return last_index;
}

// Количество элементов, кратных k
int count_multiples(double *arrptr, size_t n, double k) {
    if (k == 0.0) return 0;
    int count = 0;
    for (size_t i = 0; i < n; i++) {
        if ((int)*(arrptr + i) % (int)k == 0) {
            count++;
        }
    }
    return count;
}

// Сумма элементов выше среднего
double sum_above_average(double *arrptr, size_t n) {
    if (n == 0) return 0.0;
    double sum = 0.0;
    for (size_t i = 0; i < n; i++) {
        sum += *(arrptr + i);
    }
    double average = sum / n;

    double result = 0.0;
    for (size_t i = 0; i < n; i++) {
        if (*(arrptr + i) > average) {
            result += *(arrptr + i);
        }
    }
    return result;
}