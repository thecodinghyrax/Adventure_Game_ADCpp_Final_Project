#include "enemy.h"
#include "battle.h"

Enemy::Enemy()
{

}

void Enemy::setId(std::string id) {
    this->id = id;
}

void Enemy::setType(std::string type) {
    this->type = type;
}

void Enemy::setHealth(int health) {
    this->health = health;
}

void Enemy::setDefense(int defense) {
    this->defense = defense;
}

void Enemy::pushEnemies() {



    Enemy skeleton;
    skeleton.setId("S1");
    skeleton.setType("Skeleton");
    skeleton.setHealth(100);
    skeleton.setDefense(5);
    enemyVector.push_back(skeleton);

    Enemy bandit;
    bandit.setId("B1");
    bandit.setType("Bandit");
    bandit.setHealth(100);
    bandit.setDefense(8);
    enemyVector.push_back(bandit);

}
