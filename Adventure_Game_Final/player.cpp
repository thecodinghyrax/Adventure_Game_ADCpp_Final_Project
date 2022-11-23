#include "player.h"

// Initialize new player
Player::Player() {
    this->entityHealth = 20;
    this->entityDefense = 10;
    this->pWeaponDamage = 6;
}

void Player::setWeaponDamage(int damage) {
    this->pWeaponDamage = damage;
}

// pushes the player stats into the game upon startup
void Player::pushPlayerStats() {
    Player player;
    player.setEntityHealth(20);
    player.setEntityDefense(10);
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
