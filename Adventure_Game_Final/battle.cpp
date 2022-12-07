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

bool Battle::isEnemiesEmpty() {
    return enemies.size() == 0;
}

bool Battle::isWeaponsEmpty() {
    return weapons.size() == 0;
}

Enemy Battle::createEnemy() {
    if (!isEnemiesEmpty()) {
        srand(time(0));
        return enemies[rand() % enemies.size()];
    }
    return Enemy();
}

Weapon Battle::createWeapon() {
    if (!isWeaponsEmpty()) {
        srand(time(0));
        return weapons[rand() % weapons.size()];
    }
    return Weapon();
}

void Battle::createPlayer() {
    testPlayer = player.front();

}

void Battle::setEnemy() {
    testEnemy = Battle::createEnemy();
}

void Battle::setWeapon() {
    testWeapon = Battle::createWeapon();
}

void Battle::setEnemyType() {
    enemyType = testEnemy.getType();
}

void Battle::setEnemyWeaponType() {
    enemyWeaponType = testWeapon.getType();
}

void Battle::setPlayerTemp() {
    playerTempHP = testPlayer.getPlayerHealth();
    playerTempDef = testPlayer.getPlayerDefense();
}

void Battle::setEnemyTemp() {
    enemyTempHP = testEnemy.getHealth();
    enemyTempDef = testEnemy.getDefense();
}

bool Battle::isEnemyDefending() {

    return enemyDefending;

}

void Battle::playerAttack() {

    srand(time(0));
    int hitchance = (rand() % 20 + 1);

    // checks if enemy is defending
    if (enemyDefending) {
        // checks if attack hits
        if (hitchance > (testEnemy.getDefense() * 2)) {
            // attack hits
            enemyTempHP = enemyTempHP - testPlayer.getWeaponDamage();
        }
        enemyDefending = false;
    }
    else {
        if (hitchance > testEnemy.getDefense()) {
            // attack hits
            enemyTempHP = enemyTempHP - testPlayer.getWeaponDamage();
        }
        else {
            // attack misses or is blocked
        }
    }

}

void Battle::playerDefend() {

    playerDefending = true;
    enemyDefending = false;

}

void Battle::playerHeavyAttack() {

    int hitchance1 = (rand() % 20 + 1);
    int hitchance2 = (rand() % 20 + 1);
    int attack = testPlayer.getWeaponDamage() * 2;

    if (enemyDefending) {

        if (hitchance1 > (testEnemy.getDefense() * 2) || hitchance2 > (testEnemy.getDefense() * 2)) {

            enemyTempHP = enemyTempHP - attack;

        }

        enemyDefending = false;

    }
    else {
        if (hitchance1 > testEnemy.getDefense() || hitchance2 > testEnemy.getDefense()) {

            enemyTempHP = enemyTempHP - attack;

        }
    }

}

void Battle::enemyTurn() {
    srand(time(0));
    int choice = (rand() % 10 + 1);

    if (choice < 7) {
        // enemy tries to hit the player
        int hitchance = (rand() % 20 + 1);

        // checks if the player is defending
        if (playerDefending) {
            // if player is defending, check if the attack hits
            if (hitchance > (testPlayer.getPlayerDefense() * 2)) {
                // attack hits
                playerTempHP = playerTempHP - testWeapon.getDamage();
            }
            // player stops defending after attack
            playerDefending = false;
        }
        else {
            // checks if attack hits
            if (hitchance > testPlayer.getPlayerDefense()) {
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



