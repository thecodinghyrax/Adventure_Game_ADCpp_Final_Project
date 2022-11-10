#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>

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

public:
    Player();
    Player(int playerHealth, int playerDefense, int pWeaponDamage);

    int getPlayerHealth() {return playerHealth;}
    int getPlayerDefense() {return playerDefense;}
    int getWeaponDamage() {return pWeaponDamage;}

    void setPlayerHealth(int);
    void setPlayerDefense(int);
    void setWeaponDamage(int);

    void pushPlayerStats();
};

#endif // PLAYER_H
