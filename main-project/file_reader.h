#ifndef FILE_READER_H
#define FILE_READER_H

#include "wind_record.h"

bool readWindData(const char* filename, WindRecord* records[], int& count);
void displayRecords(WindRecord* records[], int count);

void filterByDirection(WindRecord* records[], int count);
void filterBySpeed(WindRecord* records[], int count);

#endif