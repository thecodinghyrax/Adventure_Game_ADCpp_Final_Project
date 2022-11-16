#include "player.h"

// Initialize new player
Player::Player() {
    this->playerHealth = 20;
    this->playerDefense = 10;
    this->pWeaponDamage = 6;
}

void Player::setPlayerHealth(int health) {
    this->playerHealth = health;
}

void Player::setPlayerDefense(int defense) {
    this->playerDefense = defense;
}

void Player::setWeaponDamage(int damage) {
    this->pWeaponDamage = damage;
}

void Player::pushPlayerStats() {
    Player player;
    player.setPlayerHealth(20);
    player.setPlayerDefense(10);
    player.setWeaponDamage(6);
    p.push_back(player);
}

// Returns if the player has an item with the given name
bool Player::hasItemWithName(std::string itemName){
    for (Item i : inventory){
        if (i.getName() == itemName){
            return true;
        }
    }
    return false;
}
// Gives the player an item
void Player::giveItem(Item item){
    inventory.push_back(item);
}
