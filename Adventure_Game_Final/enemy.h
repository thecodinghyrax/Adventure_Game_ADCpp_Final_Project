#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include <vector>
#include "weapons.h"
#include "entity.h"

class Enemy : public Entity
{
private:
    // ID for enemy
    std::string id;
    // type of enemy (ex: Skeleton, Bandit)
    std::string type;
    // vector holding weapons
    std::vector<Weapon> weaponVector;
    // vector holding enemies
    std::vector<Enemy> enemyVector;

public:
    Enemy();
    Enemy(std::string id);
    Enemy(std::string id, std::string type, int health, int defense, std::vector<Weapon> weaponVector);

    // getters for enemy id and type
    std::string getId() {return id;}
    std::string getType() {return type;}

    // setters for enemy id, type, and the weapons vector
    void setId(std::string);
    void setType(std::string);
    void setWeapons(std::vector<Weapon>);

    // function to push enemy entities into the game upon startup
    void pushEnemies();

};

#endif // ENEMY_H
