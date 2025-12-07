#ifndef WIND_RECORD_H
#define WIND_RECORD_H

#include <string>

using namespace std;

struct WindRecord {
    int day;
    int month;
    string direction;
    double speed;
};

enum WindDirection {
    NORTH,
    NORTHEAST,
    EAST,
    SOUTHEAST,
    SOUTH,
    SOUTHWEST,
    WEST,
    NORTHWEST
};

#endif