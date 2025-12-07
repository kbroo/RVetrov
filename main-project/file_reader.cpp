#include "file_reader.h"
#include "constants.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

bool readWindData(const char* filename, WindRecord* records[], int& count) {
    ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    count = 0;
    while (!file.eof() && count < MAX_RECORDS) {
        records[count] = new WindRecord();
        file >> records[count]->day
            >> records[count]->month
            >> records[count]->direction
            >> records[count]->speed;

        if (file.fail()) {
            delete records[count];
            break;
        }
        count++;
    }

    file.close();
    return true;
}

void displayRecords(WindRecord* records[], int count) {
    cout << "|------------------------------------|" << endl;
    cout << "| День| Месяц| Направление | Скорость|" << endl;
    cout << "|-----|------|-------------|---------|" << endl;

    for (int i = 0; i < count; i++) {
        cout << "| " << setw(4) << records[i]->day
            << " | " << setw(5) << records[i]->month
            << " | " << setw(11) << records[i]->direction
            << " | " << setw(7) << fixed << setprecision(1) << records[i]->speed
            << " |" << endl;
    }

    cout << "|-----|------|-------------|---------|" << endl;
}

void filterByDirection(WindRecord* records[], int count) {
    cout << "Дни с ветром West, NorthWest или North:" << endl;
    cout << "|------------------------------------|" << endl;
    cout << "| День| Месяц| Направление | Скорость|" << endl;
    cout << "|-----|------|-------------|---------|" << endl;
    
    for (int i = 0; i < count; i++) {
        if (records[i]->direction == "West" || 
            records[i]->direction == "NorthWest" || 
            records[i]->direction == "North") {
            cout << "| " << setw(4) << records[i]->day 
                 << " | " << setw(5) << records[i]->month 
                 << " | " << setw(11) << records[i]->direction 
                 << " | " << setw(7) << fixed << setprecision(1) << records[i]->speed 
                 << " |" << endl;
        }
    }
    
    cout << "|-----|------|-------------|---------|" << endl;
}

void filterBySpeed(WindRecord* records[], int count) {
    cout << "Дни с ветром более 5 м/с:" << endl;
    cout << "|------------------------------------|" << endl;
    cout << "| День| Месяц| Направление | Скорость|" << endl;
    cout << "|-----|------|-------------|---------|" << endl;
    
    for (int i = 0; i < count; i++) {
        if (records[i]->speed > 5.0) {
            cout << "| " << setw(4) << records[i]->day 
                 << " | " << setw(5) << records[i]->month 
                 << " | " << setw(11) << records[i]->direction 
                 << " | " << setw(7) << fixed << setprecision(1) << records[i]->speed 
                 << " |" << endl;
        }
    }
    
    cout << "|-----|------|-------------|---------|" << endl;
}

WindRecord** filterData(
    WindRecord* array[],
    int size,
    bool (*check)(WindRecord* element),
    int& result_size
)
{
    // Подсчет количества подходящих элементов
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (check(array[i])) {
            count++;
        }
    }

    // Создание нового массива
    WindRecord** result = new WindRecord * [count];
    result_size = 0;

    // Заполнение нового массива
    for (int i = 0; i < size; i++) {
        if (check(array[i])) {
            result[result_size++] = array[i];
        }
    }

    return result;
}

bool checkByDirection(WindRecord* element)
{
    return (element->direction == "West" ||
        element->direction == "NorthWest" ||
        element->direction == "North");
}

bool checkBySpeed(WindRecord* element)
{
    return element->speed > 5.0;
}