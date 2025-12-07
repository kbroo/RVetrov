#ifndef SORT_H
#define SORT_H

#include "wind_record.h"

// Функции сравнения
int compareBySpeedDesc(const WindRecord* a, const WindRecord* b);
int compareByDirectionAsc(const WindRecord* a, const WindRecord* b);

// Функции сортировки
void shakerSort(WindRecord* records[], int n, int (*compare)(const WindRecord*, const WindRecord*));
void mergeSort(WindRecord* records[], int left, int right, int (*compare)(const WindRecord*, const WindRecord*));

// Вспомогательная функция для mergeSort
void merge(WindRecord* records[], int left, int mid, int right, int (*compare)(const WindRecord*, const WindRecord*));

#endif