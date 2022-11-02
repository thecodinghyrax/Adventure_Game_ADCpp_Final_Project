#include "area.h"
#include <ctime>

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
