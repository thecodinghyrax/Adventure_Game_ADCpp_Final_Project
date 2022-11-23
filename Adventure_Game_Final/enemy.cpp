#include "enemy.h"

Enemy::Enemy()
{

}

void Enemy::setId(std::string id) {
    this->id = id;
}

void Enemy::setType(std::string type) {
    this->type = type;
}

// function to push the available enemies into the game upon startup
void Enemy::pushEnemies() {

    Enemy skeleton;
    skeleton.setId("S1");
    skeleton.setType("Skeleton");
    skeleton.setEntityHealth(10);
    skeleton.setEntityDefense(5);
    enemyVector.push_back(skeleton);

    Enemy bandit;
    bandit.setId("B1");
    bandit.setType("Bandit");
    bandit.setEntityHealth(7);
    bandit.setEntityDefense(8);
    enemyVector.push_back(bandit);

}
