#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "item.h"

class Player {
private:
    // holds health
    int playerHealth;
    // holds defense
    int playerDefense;
    // holds weapon damage
    int pWeaponDamage;
    // vector to hold player object
    std::vector<Player> p;
    // Player item inventory
    std::vector<Item> inventory;
    // Number of health potions
    int healthPotions;
    // holds player max health
    int playerMaximumHP = 100;

public:
    Player();
    Player(int playerHealth, int playerDefense, int pWeaponDamage);

    int getPlayerHealth() {return playerHealth;}
    int getPlayerDefense() {return playerDefense;}
    int getWeaponDamage() {return pWeaponDamage;}
    std::vector<Item> getInventory() {return inventory;}
    int getHealthPotions(){return healthPotions;}

    void setPlayerHealth(int);
    void setPlayerDefense(int);
    void setWeaponDamage(int);
    void setHealthPotions(int);

    void pushPlayerStats();

    bool hasItemWithName(std::string);
    Item getItemByName(std::string);
    void giveItem(Item);
    void takeItem(std::string);
};

#endif // PLAYER_H
