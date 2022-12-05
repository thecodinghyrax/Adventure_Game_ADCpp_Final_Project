#ifndef WEAPONS_H
#define WEAPONS_H
#include <string>
#include <vector>

class Weapon {
private:
    // ID for identifying each weapon
    std::string id;
    // Type of the weapon (ex: shortbow, great sword)
    std::string type;
    // hit chance of the weapon
    int damage;


public:
    Weapon();
    Weapon(std::string id);
    Weapon(std::string id, std::string type, int hitchance, int damage);

    // vector holding weapon objects
    std::vector<Weapon> weaponVector;

    std::string getId() {return id;}
    std::string getType() {return type;}
    int getDamage() {return damage;}

    void setId(std::string);
    void setType(std::string);
    void setDamage(int);

    void pushWeapons();
};



#endif // WEAPONS_H
