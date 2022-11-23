#include "entity.h"

Entity::Entity() {

}

void Entity::setType(std::string type) {
    this->type = type;
}

void Entity::setEntityHealth(int health) {
    this->entityHealth = health;
}

void Entity::setEntityDefense(int defense) {
    this->entityDefense = defense;
}
