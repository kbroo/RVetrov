#include "sort.h"
#include <algorithm>

using namespace std;

// Сравнение по убыванию скорости
int compareBySpeedDesc(const WindRecord* a, const WindRecord* b) {
    if (a->speed > b->speed) return -1;
    if (a->speed < b->speed) return 1;
    return 0;
}

// Сравнение по возрастанию направления, месяца, дня
int compareByDirectionAsc(const WindRecord* a, const WindRecord* b) {
    // Сначала сравниваем направление
    int dirCompare = a->direction.compare(b->direction);
    if (dirCompare != 0) return dirCompare;

    // Если направление одинаковое, сравниваем месяц
    if (a->month != b->month) return a->month - b->month;

    // Если месяц одинаковый, сравниваем день
    return a->day - b->day;
}

// Шейкерная сортировка
void shakerSort(WindRecord* records[], int n, int (*compare)(const WindRecord*, const WindRecord*)) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = false;

        // Проход слева направо
        for (int i = start; i < end; ++i) {
            if (compare(records[i], records[i + 1]) > 0) {
                swap(records[i], records[i + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;

        swapped = false;
        --end;

        // Проход справа налево
        for (int i = end - 1; i >= start; --i) {
            if (compare(records[i], records[i + 1]) > 0) {
                swap(records[i], records[i + 1]);
                swapped = true;
            }
        }

        ++start;
    }
}

// Сортировка слиянием
void merge(WindRecord* records[], int left, int mid, int right, int (*compare)(const WindRecord*, const WindRecord*)) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Создаем временные массивы
    WindRecord** leftArr = new WindRecord * [n1];
    WindRecord** rightArr = new WindRecord * [n2];

    // Копируем данные во временные массивы
    for (int i = 0; i < n1; i++)
        leftArr[i] = records[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = records[mid + 1 + j];

    // Слияние временных массивов
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (compare(leftArr[i], rightArr[j]) <= 0) {
            records[k] = leftArr[i];
            i++;
        }
        else {
            records[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Копируем оставшиеся элементы
    while (i < n1) {
        records[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        records[k] = rightArr[j];
        j++;
        k++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(WindRecord* records[], int left, int right, int (*compare)(const WindRecord*, const WindRecord*)) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(records, left, mid, compare);
        mergeSort(records, mid + 1, right, compare);

        merge(records, left, mid, right, compare);
    }
}