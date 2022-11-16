#include "weapons.h"
#include <ctime>
#include <vector>

Weapon::Weapon() {

}

void Weapon::setId(std::string id) {
    this->id = id;
}

void Weapon::setType(std::string type) {
    this->type = type;
}

//void Weapon::setHitChance(int hitchance) {
//    this->hitchance = hitchance;
//}

void Weapon::setDamage(int damage) {
    this->damage = damage;
}

// pushes the created weapons into the vector
void Weapon::pushWeapons() {

    Weapon shortSword;
    shortSword.setId("S1");
    shortSword.setType("Sword");
    shortSword.setDamage(5);
    weaponVector.push_back(shortSword);

    Weapon shortBow;
    shortBow.setId("B1");
    shortBow.setType("Bow");
    shortBow.setDamage(4);
    weaponVector.push_back(shortBow);

}
