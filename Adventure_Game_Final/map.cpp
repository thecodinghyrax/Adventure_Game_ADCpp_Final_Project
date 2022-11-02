#include "map.h"
#include <vector>


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
