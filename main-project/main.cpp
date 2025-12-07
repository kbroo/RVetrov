#include <iostream>
#include "wind_record.h"
#include "file_reader.h"
#include "constants.h"

using namespace std;

int main()
{

    setlocale(LC_ALL, "Russian");

    cout << "=== Vatiant 6: Roza Vetrov ===" << endl;
    cout << "Student: Kvit Ilya" << endl;
    cout << "Group: 25Pinzh1d" << endl;

    WindRecord* records[MAX_RECORDS];
    int count = 0;

    if (readWindData("data.txt", records, count)) {
        cout << "Успешно загружено записей: " << count << endl << endl;
        displayRecords(records, count);
    }
    else {
        cout << "Ошибка загрузки файла!" << endl;
    }

    for (int i = 0; i < count; i++) {
        delete records[i];
    }

    return 0;

}
