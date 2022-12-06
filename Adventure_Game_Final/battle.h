#ifndef BATTLE_H
#define BATTLE_H
#include <string>
#include <vector>
#include "weapons.h"
#include "enemy.h"
#include "player.h"

class Battle {
private:
    // boolean to tell if the player is defending
    bool playerDefending;
    // boolean to tell if the enemy is defending
    bool enemyDefending;
    // player temp defense
    int playerTempDef;
    // enemy temp defense
    int enemyTempDef;
    // enemy
    Enemy testEnemy;
    // weapon
    Weapon testWeapon;
    // player
    Player testPlayer;
    // vector for weapons
    std::vector<Weapon> weapons;
    // vector for enemies
    std::vector<Enemy> enemies;
    // vector for player
    std::vector<Player> player;

public:
    Battle();
    Battle(bool defending, std::vector<Weapon> weapons, std::vector<Enemy> enemies);

    // player temp health
    int playerTempHP = 100;
    // enemy temp health
    int enemyTempHP;
    // variable to hold type of enemy
    std::string enemyType;
    // variable to hold type of weapon enemy weilds
    std::string enemyWeaponType;

    void setEnemies(std::vector<Enemy>);
    void setWeapons(std::vector<Weapon>);
    void setPlayers(std::vector<Player>);

    bool isEnemiesEmpty();
    bool isWeaponsEmpty();

    Enemy createEnemy();
    Weapon createWeapon();
    void createPlayer();

    void setEnemy();
    void setWeapon();
    void setPlayer();
    void setEnemyType();
    void setEnemyWeaponType();

    void setPlayerTemp();
    void setEnemyTemp();

    bool isEnemyDefending();

    void playerAttack();
    void playerDefend();
    void playerHeavyAttack();
    //void playerItem();
    void enemyTurn();

    void endBattle();
    void start();

};

#endif // BATTLE_H
