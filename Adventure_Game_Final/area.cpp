#include "area.h"
#include <ctime>


Area::Area(){

};

void Area::setId(std::string id){
    this->id = id;
};
void Area::setName(std::string name){
    this->name = name;
};
void Area::setText(std::string text){
    this->text = text;
};
void Area::setSearchResult(std::string searchResult){
    this->searchResult = searchResult;
};
void Area::setBackgroundFile(std::string backgroundFile){
    this->backgroundFile = backgroundFile;
};

void Area::setNorthArea(std::string northArea){
    this->northArea = northArea;
};
void Area::setEastArea(std::string eastArea){
    this->eastArea = eastArea;
};
void Area::setSouthArea(std::string southArea){
    this->southArea = southArea;
};
void Area::setWestArea(std::string westArea){
    this->westArea = westArea;
};
void Area::setEnemies(std::vector<Enemy> enemies){
    this->enemyVector = enemies;
}
Area::Area(std::string id){
    this->id = id;
};
// Returns a random enemy from an area's vector of enemies
Enemy Area::createEnemy(){
    if (hasEnemies()){
        // Seed random with the current time
        srand(time(0));
        return enemyVector[rand() % enemyVector.size()];
    }
    // If there are no enemies, return a blank enemy
    return Enemy();
}

bool Area::hasEnemies(){
    return enemyVector.size() == 0;
}
