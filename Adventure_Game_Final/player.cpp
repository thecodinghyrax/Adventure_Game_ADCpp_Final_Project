#include "player.h"

Player::Player() {

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
