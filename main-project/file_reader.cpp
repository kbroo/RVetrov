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
    cout << "??????????????????????????????????????" << endl;
    cout << "? День? Месяц? Направление ? Скорость?" << endl;
    cout << "??????????????????????????????????????" << endl;

    for (int i = 0; i < count; i++) {
        cout << "? " << setw(4) << records[i]->day
            << " ? " << setw(5) << records[i]->month
            << " ? " << setw(11) << records[i]->direction
            << " ? " << setw(7) << fixed << setprecision(1) << records[i]->speed
            << " ?" << endl;
    }

    cout << "??????????????????????????????????????" << endl;
}