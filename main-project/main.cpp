#include <iostream>
#include "wind_record.h"
#include "file_reader.h"
#include "constants.h"
#include "sort.h"

using namespace std;

void showMenu() {
    cout << endl;
    cout << "=== МЕНЮ ===" << endl;
    cout << "1. Show all entries" << endl;
    cout << "2. Filter: West/NorthWest/North" << endl;
    cout << "3. Filter: скорость > 5 м/с" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose: ";
}

void showSortMenu() {
    cout << endl;
    cout << "=== ВЫБОР МЕТОДА СОРТИРОВКИ ===" << endl;
    cout << "1. Шейкерная сортировка" << endl;
    cout << "2. Сортировка слиянием" << endl;
    cout << "Выбор: ";
}

void showCriteriaMenu() {
    cout << endl;
    cout << "=== ВЫБОР КРИТЕРИЯ СОРТИРОВКИ ===" << endl;
    cout << "1. По убыванию скорости ветра" << endl;
    cout << "2. По возрастанию направления ветра" << endl;
    cout << "   (в рамках одного направления по возрастанию месяца," << endl;
    cout << "    в рамках одного месяца по возрастанию дня)" << endl;
    cout << "Выбор: ";
}

int main()
{

    setlocale(LC_ALL, "Russian");

    cout << "=== Vatiant 6: Roza Vetrov ===" << endl;
    cout << "Student: Kvit Ilya" << endl;
    cout << "Group: 25Pinzh1d" << endl;

    WindRecord* records[MAX_RECORDS];
    int count = 0;

    if (!readWindData("data.txt", records, count)) {
        cout << "File upload error!" << endl;
        system("pause");
        return 1;
    }

    cout << "Record successfully loaded: " << count << endl;

    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            displayRecords(records, count);
            break;
        case 2:
            filterByDirection(records, count);
            break;
        case 3:
            filterBySpeed(records, count);
            break;
        case 4: {
            int sortMethod, criteria;

            showSortMenu();
            cin >> sortMethod;

            showCriteriaMenu();
            cin >> criteria;

            // Выбор функции сравнения
            int (*compareFunc)(const WindRecord*, const WindRecord*) = nullptr;
            if (criteria == 1) {
                compareFunc = compareBySpeedDesc;
                cout << "Sort by speed descending..." << endl;
            }
            else if (criteria == 2) {
                compareFunc = compareByDirectionAsc;
                cout << "Sort by direction/month/day..." << endl;
            }

            // Выбор метода сортировки и выполнение
            if (sortMethod == 1) {
                shakerSort(records, count, compareFunc);
                cout << "Shaker sorting has been completed" << endl;
            }
            else if (sortMethod == 2) {
                mergeSort(records, 0, count - 1, compareFunc);
                cout << "Merge sort performed" << endl;
            }

            displayRecords(records, count);
            break;
        }
        case 0:
            cout << "Exit..." << endl;
            break;
        default:
            cout << "Uncorrect choose!" << endl;
        }
    } while (choice != 0);

    for (int i = 0; i < count; i++) {
        delete records[i];
    }

    return 0;

}
