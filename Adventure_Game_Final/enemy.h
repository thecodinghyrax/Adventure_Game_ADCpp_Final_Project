#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include <vector>
#include "weapons.h"

class Enemy
{
private:
    // ID for enemy
    std::string id;
    // type of enemy (ex: Skeleton, Bandit)
    std::string type;
    // health of the enemy
    int health;
    // defense of the enemy
    int defense;
    // vector holding weapons
    std::vector<Weapon> weaponVector;
    // vector holding enemies
    std::vector<Enemy> enemyVector;

public:
    Enemy();
    Enemy(std::string id);
    Enemy(std::string id, std::string type, int health, int defense, std::vector<Weapon> weaponVector);

    std::string getId() {return id;}
    std::string getType() {return type;}
    int getHealth() {return health;}
    int getDefense() {return defense;}

    void setId(std::string);
    void setType(std::string);
    void setHealth(int);
    void setDefense(int);
    void setWeapons(std::vector<Weapon>);

    void pushEnemies();

};

#endif // ENEMY_H
