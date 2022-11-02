#include <vector>
#include "area.h"

class Map
{
private:
    // Vector containing the game's areas
    std::vector<Area> mapData;
    Area getAreaById(std::string id);
    std::vector<Area> getMapData();
public:
    Map();
    Map(std::vector<Area> areaVec);

    std::vector<Area> getConnectedAreas(Area workingArea);
};
