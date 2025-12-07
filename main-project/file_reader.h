#ifndef FILE_READER_H
#define FILE_READER_H

#include "wind_record.h"
#include "constants.h"

bool readWindData(const char* filename, WindRecord* records[], int& count);
void displayRecords(WindRecord* records[], int count);

void filterByDirection(WindRecord* records[], int count);
void filterBySpeed(WindRecord* records[], int count);

WindRecord** filterData(
    WindRecord* array[],
    int size,
    bool (*check)(WindRecord* element),
    int& result_size
);

bool checkByDirection(WindRecord* element);
bool checkBySpeed(WindRecord* element);

#endif