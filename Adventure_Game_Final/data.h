#ifndef DATA_H
#define DATA_H

#include "area.h"
#include <vector>
class Data
{
public:
    Data();
    static std::vector<Area> initializeMap();
};

#endif // DATA_H
