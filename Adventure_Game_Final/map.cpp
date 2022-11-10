#include "map.h"



Map::Map(){
    loadAreasFromFile(":/assests/map.txt");

};

// Returns a game area from an ID
// Returns an area with an ID of 0 if no area is found
Area Map::getAreaById(std::string id){
    for (int i = 0; i < mapData.size(); i++){
        if (mapData[i].getId() == id){
            return mapData[i];
        }
    }
    Area emptyArea("0");
    return emptyArea;

}

// Returns the connected areas to an area
// Vector index 0: North, 1: East, 2: South, 3: West
std::vector<Area> Map::getConnectedAreas(Area workingArea){
    std::vector<Area> connectedAreas;
    connectedAreas.push_back(getAreaById(workingArea.getNorthArea()));
    connectedAreas.push_back(getAreaById(workingArea.getEastArea()));
    connectedAreas.push_back(getAreaById(workingArea.getSouthArea()));
    connectedAreas.push_back(getAreaById(workingArea.getWestArea()));
    return connectedAreas;
}

void Map::setArea(Area area){
    mapData.push_back(area);
};

void Map::loadAreasFromFile(std::string fileName){
    QFile reader(QString::fromStdString(fileName));
    if(!reader.open(QIODevice::ReadOnly)){
        throw "Area file not found";
    }
    QTextStream stream(&reader);
    Area temp;
    int areaPosition = 0;
    while(!stream.atEnd()){
        QString line;
        line = stream.readLine();
        if(line == "+"){
            setArea(temp);
            areaPosition = 0;
            line = stream.readLine(); // throwaway line
        }
        switch(areaPosition){
        case 0: {
            temp.setId(line.toStdString());
            areaPosition++;
            break;
        }case 1:{
            temp.setName(line.toStdString());
            areaPosition++;
            break;
        }case 2:{
            temp.setText(line.toStdString());
            areaPosition++;
            break;
        }case 3:{
            temp.setSearchResult(line.toStdString());
            areaPosition++;
            break;
        }case 4:{
            temp.setBackgroundFile(line.toStdString());
            areaPosition++;
            break;
        }case 5:{
            //temp.setEnemyVector(line.toStdString());   //skipping for now
            areaPosition++;
            break;
        }case 6:{
            temp.setNorthArea(line.toStdString());
            areaPosition++;
            break;
        }case 7:{
            temp.setEastArea(line.toStdString());
            areaPosition++;
            break;
        }case 8:{
            temp.setSouthArea(line.toStdString());
            areaPosition++;
            break;
        }case 9:{
            temp.setWestArea(line.toStdString());
            areaPosition++;
            break;
        } default :{
            break;
        }
        }

    }
};
