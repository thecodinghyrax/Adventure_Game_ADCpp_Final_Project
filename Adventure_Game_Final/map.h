#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "area.h"
#include <QFile>
#include <QTextStream>
#include <QString>


class Map
{
private:
    // Vector containing the game's areas
    std::vector<Area> mapData;


    std::vector<Area> getMapData();
public:
    Map();
    Map(std::vector<Area> areaVec);

    std::vector<Area> getConnectedAreas(Area workingArea);
    Area getAreaById(std::string id);
    void setArea(Area);
    void loadAreasFromFile(std::string);
};
