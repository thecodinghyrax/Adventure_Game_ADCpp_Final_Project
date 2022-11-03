#include "data.h"
#include "enemy.h"
#include <vector>

static std::vector<Area> initializeMap(){
    std::vector<Area> mapData;
    std::vector<Enemy> noEnemy;
    mapData.push_back(Area("camp", "Starting Camp", "Placeholder text", "/assets/bkg-camp.png","forest1","forest2","highway","river",noEnemy));
    mapData.push_back(Area("forest1", "Thick Forest", "Placeholder text", "/assets/bkg-camp.png","0","plain","camp","0",noEnemy));
    mapData.push_back(Area("forest2", "Forest Clearing", "Placeholder text", "/assets/bkg-camp.png","plain","0","0","camp",noEnemy));
    mapData.push_back(Area("river", "Riverbank", "You find yourself at the bank of a large river. On the other side of it to the west you can see a large castle, but you cannot find any way to cross the river here.", "/assets/bkg-castle.png","0","camp","0","0",noEnemy));
    mapData.push_back(Area("highway", "Highway Junction", "You are at the junction of a paved highway which appears well-traveled. A sign pointing to the west reads \"Sylvar\", and the sign pointing east reads \"Thar\'gol\".", "/assets/bkg-castle.png","camp","0","0","0",noEnemy));
    mapData.push_back(Area("plain", "Open Plain", "Placeholder text", "/assets/bkg-castle.png","0","0","forest2","forest1",noEnemy));

    return mapData;
}
