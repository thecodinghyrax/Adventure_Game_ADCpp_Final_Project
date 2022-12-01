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
// Returns an item from the player's inventory with the given name
Item Player::getItemByName(std::string itemName){
    for (Item i : inventory){
        if (i.getName() == itemName){
            return i;
        }
    }
    // If no item is found return a blank item
    return Item();

}


// Gives the player an item
void Player::giveItem(Item item){
    inventory.push_back(item);
}

// Take an item from the player
void Player::takeItem(std::string itemName){
    for (size_t i = 0; i < inventory.size(); i++){
        if (inventory[i].getName() == itemName){
            // Remove item at the i index
            inventory.erase(inventory.begin() + i);
        }
    }
}
