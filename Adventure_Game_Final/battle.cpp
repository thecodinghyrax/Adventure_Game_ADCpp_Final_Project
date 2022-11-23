#include "battle.h"
#include <ctime>

Battle::Battle() {

}

void Battle::setEnemies(std::vector<Enemy> enemies) {
    this->enemies = enemies;
}

void Battle::setWeapons(std::vector<Weapon> weapons) {
    this->weapons = weapons;
}

void Battle::setPlayers(std::vector<Player> players) {
    this->player = players;
}

// checks if the enemies vector is empty
bool Battle::isEnemiesEmpty() {
    return enemies.size() == 0;
}

// checks if the weapons vector is empty
bool Battle::isWeaponsEmpty() {
    return weapons.size() == 0;
}

// returns an enemy for the battle if the enemy vector is not empty
Enemy Battle::createEnemy() {
    if (!isEnemiesEmpty()) {
        srand(time(0));
        return enemies[rand() % enemies.size()];
    }
    return Enemy();
}

// returns a random weapon if the vector if weapons is not empty
Weapon Battle::createWeapon() {
    if (!isWeaponsEmpty()) {
        srand(time(0));
        return weapons[rand() % weapons.size()];
    }
    return Weapon();
}

// creates the player for the battle
void Battle::createPlayer() {
    testPlayer = player.front();

}

// sets the enemy for the battle
void Battle::setEnemy() {
    testEnemy = Battle::createEnemy();
}

// sets the enemy's weapon for the battle
void Battle::setWeapon() {
    testWeapon = Battle::createWeapon();
}

// sets the hp of the player for the battle
void Battle::setPlayerTemp() {
    playerTempHP = testPlayer.getEntityHealth();
    playerTempDef = testPlayer.getEntityDefense();
}

// sets the hp of the enemy for the battle
void Battle::setEnemyTemp() {
    enemyTempHP = testEnemy.getEntityHealth();
    enemyTempDef = testEnemy.getEntityDefense();
}

// function to determine if the player's attack hits and the damage
void Battle::playerAttack() {

    srand(time(0));
    int hitchance = (rand() % 20 + 1);

    // checks if enemy is defending
    if (enemyDefending) {
        // checks if attack hits
        if (hitchance > (testEnemy.getEntityDefense() * 2)) {
            // attack hits
            enemyTempHP = enemyTempHP - testPlayer.getWeaponDamage();
        }
    }
    else {
        if (hitchance > testEnemy.getEntityDefense()) {
            // attack hits
            enemyTempHP = enemyTempHP - testPlayer.getWeaponDamage();
        }
        else {
            // attack misses or is blocked
        }
    }

}

// function to change the defend variable should the player decide to defend for the round
void Battle::playerDefend() {

    bool playerDefending = true;

}

// function to decide and take the enemy's turn
void Battle::enemyTurn() {
    srand(time(0));
    int choice = (rand() % 10 + 1);

    if (choice < 7) {
        // enemy tries to hit the player
        int hitchance = (rand() % 20 + 1);

        // checks if the player is defending
        if (playerDefending) {
            // if player is defending, check if the attack hits
            if (hitchance > (testPlayer.getEntityDefense() * 2)) {
                // attack hits
                playerTempHP = playerTempHP - testWeapon.getDamage();
            }
            // player stops defending after attack
            playerDefending = false;
        }
        else {
            // checks if attack hits
            if (hitchance > testPlayer.getEntityDefense()) {
                // attack hits
                playerTempHP = playerTempHP - testWeapon.getDamage();
            }
        }

    }
    else {
        // enemy tries to defend against the player's next attack
        enemyDefending = true;
    }

}


