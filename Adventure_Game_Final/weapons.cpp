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

void Weapon::setDamage(int damage) {
    this->damage = damage;
}

// pushes the created weapons into the vector
void Weapon::pushWeapons() {

    Weapon shortSword;
    shortSword.setId("S1");
    shortSword.setType("Short Sword");
    shortSword.setDamage(25);
    weaponVector.push_back(shortSword);

    Weapon shortBow;
    shortBow.setId("B1");
    shortBow.setType("Short Bow");
    shortBow.setDamage(20);
    weaponVector.push_back(shortBow);

}

void Weapon::pushBossWeapon() {

    Weapon bloodMagic;
    bloodMagic.setId("M1");
    bloodMagic.setType("Blood Magic");
    bloodMagic.setDamage(34);
    weaponVector.push_back(bloodMagic);

}
