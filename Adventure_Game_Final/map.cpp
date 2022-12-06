#include "map.h"



Map::Map(){
    loadAreasFromFile(":/assets/map.txt");
    addSearchItems();
};

// Returns a game area from an ID
// Returns an area with an ID of 0 if no area is found
Area Map::getAreaById(std::string id){
    for (size_t i = 0; i < mapData.size(); i++){
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
            std::vector<std::string> enemyIds;
            std::vector<Enemy> enemyObjects;
            //TODO: Read enemy IDs from map.txt; get enemies from an enemies.txt file

            temp.setEnemies(enemyObjects);
            areaPosition++;
            break;
        }case 6:{
            std::vector<std::string> connections;
            std::string curLine = line.toStdString();
            // For each direction, split the line string to get the IDs
            for (int i = 0; i < 4; i++){
                connections.push_back(curLine.substr(0,curLine.find(",")));
                std::string a = curLine.substr(0,curLine.find(","));
                curLine = curLine.substr(curLine.find(",") + 1, curLine.size());
            }
            temp.setNorthArea(connections[0]);
            temp.setEastArea(connections[1]);
            temp.setSouthArea(connections[2]);
            temp.setWestArea(connections[3]);

            areaPosition++;
            break;
        }case 7:{
            // Add the area to the map data vector
            setArea(temp);
            areaPosition = 0;
        } default :{
             break;
         }
        }

    }
};

void Map::addSearchItems(){
    for (size_t i = 0; i < mapData.size(); i++){
        if(mapData[i].getId() == "0"){
            mapData[i].setSearchItem(Item("Hammer", "This hammer has seen better days, but appears perfectly usable.", "noImage", false, 0));
        }
        if(mapData[i].getId() == "4"){
            mapData[i].setSearchItem(Item("Old key", "A black key with an ornate design.", "noImage", false, 0));
        }
        if(mapData[i].getId() == "7"){
            mapData[i].setSearchItem(Item("Fishing rod", "A simple fishing rod.", "noImage", false, 0));
        }
        if(mapData[i].getId() == "11"){
            mapData[i].setSearchItem(Item("Woodcutter's axe", "A well-worn axe, it still looks sharp enough to cut down a tree.", "noImage", false, 0));
        }
        if(mapData[i].getId() == "35"){
            mapData[i].setSearchItem(Item("Letter", "A hastily written letter which reads: \"Adventurer, beware the vampire who lies within this room! He cannot be killed by ordinary means. Make sure you are prepared before facing him!\"", "noImage", false, 0));
        }
    }
}

void Map::setAreaSearched(std::string id){
    for (size_t i = 0; i < mapData.size(); i++){
        if (mapData[i].getId() == id){
            mapData[i].setSearched(true);
            return;
        }
    }
}
