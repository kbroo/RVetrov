#include "processing.h"
#include <iostream>

double calculateAverageSpeedInMonth(WindRecord* records[], int size, int month)
{
    if (size == 0) {
        return -1.0; // Нет данных
    }

    double totalSpeed = 0.0;
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (records[i] != nullptr && records[i]->month == month) {
            totalSpeed += records[i]->speed;
            count++;
        }
    }

    if (count == 0) {
        return -1.0; // Нет данных для указанного месяца
    }

    return totalSpeed / count;
}