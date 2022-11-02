#include <string>
#include <vector>
#include "enemy.h"


class Area
{
private:
    // ID for identifying and referring to an area
    std::string id;
    // Area name shown to the player
    std::string name;
    // Text description of the area shown to the player
    std::string text;
    // Filename of the area's background image
    std::string backgroundFile;
    // Vector of enemies that can be fought in the area
    std::vector<Enemy> enemyVector;
    // IDs of connected areas for each direction
    std::string northArea;
    std::string eastArea;
    std::string southArea;
    std::string westArea;


public:
    Area();
    Area(std::string id);
    Area(std::string id, std::string name, std::string text, std::string backgroundFile, std::string northArea
         , std::string eastArea, std::string southArea, std::string westArea, std::vector<Enemy> enemyVector);

    std::string getId(){return id;}
    std::string getName(){return name;}
    std::string getText(){return text;}
    std::string getBackgroundFile(){return backgroundFile;}
    std::string getNorthArea(){return northArea;}
    std::string getEastArea(){return eastArea;}
    std::string getSouthArea(){return southArea;}
    std::string getWestArea(){return westArea;}

    Enemy createEnemy();

};
