#ifndef ENTITY_H
#define ENTITY_H
#include <string>
#include <vector>
#include "item.h"

class Entity {
protected:
    // variable made to hold the type of entity
    std::string type;
    // variable made to hold the health of the entity
    int entityHealth;
    // variable made to hold the defense of the entity
    int entityDefense;
    // variable made to hold the inventory (or drop table for enemies) of the entity
    // std::vector<Item> inventory;

public:
    Entity();
    Entity(int entityHealth, int entityDefense);

    // getters for basic stats of all entities
    std::string getType() {return type;}
    int getEntityHealth() {return entityHealth;}
    int getEntityDefense() {return entityDefense;}

    // setters for basic stats of all entities
    void setType(std::string);
    void setEntityHealth(int);
    void setEntityDefense(int);

};

#endif // ENTITY_H
