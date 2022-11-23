#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "item.h"
#include "entity.h"

class Player : public Entity{
private:

    // holds weapon damage
    int pWeaponDamage;
    // vector to hold player object
    std::vector<Player> p;
    // Player item inventory
    std::vector<Item> inventory;

public:
    Player();
    Player(int playerHealth, int playerDefense, int pWeaponDamage);

    // getter for weapon damage (only to be used in testing as weapon damage will later be determined by the item itself)
    int getWeaponDamage() {return pWeaponDamage;}
    std::vector<Item> getInventory() {return inventory;}

    // setter for weapon damage (only to be used in testing as weapon damage will later be determined by the item itself)
    void setWeaponDamage(int);

    // pushes the base player stats into the game upon startup
    void pushPlayerStats();

    bool hasItemWithName(std::string);
    Item getItemByName(std::string);
    void giveItem(Item);
};

#endif // PLAYER_H
