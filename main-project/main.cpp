#include <iostream>
#include "wind_record.h"
#include "file_reader.h"
#include "constants.h"

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

int main()
{

    setlocale(LC_ALL, "Russian");

    cout << "=== Vatiant 6: Roza Vetrov ===" << endl;
    cout << "Student: Kvit Ilya" << endl;
    cout << "Group: 25Pinzh1d" << endl;

    WindRecord* records[MAX_RECORDS];
    int count = 0;

    if (!readWindData("data.txt", records, count)) {
        cout << "Ошибка загрузки файла!" << endl;
        system("pause");
        return 1;
    }

    cout << "Успешно загружено записей: " << count << endl;

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
        case 0:
            cout << "Выход..." << endl;
            break;
        default:
            cout << "Неверный выбор!" << endl;
        }
    } while (choice != 0);

    for (int i = 0; i < count; i++) {
        delete records[i];
    }

    return 0;

}
