#pragma once
#include <string>
#include <vector>
#include "enemy.h"
#include "item.h"


class Area
{
private:
    // ID for identifying and referring to an area
    std::string id;
    // Area name shown to the player
    std::string name;
    // Text description of the area shown to the player
    std::string text;
    // Text description of the results of searching area
    std::string searchResult;
    // The area has been searched by the player
    bool searched = false;
    // The item to give the player when searching. Defaults to no item
    Item searchItem = Item();
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
    std::string getSearchResult();
    bool hasBeenSearched(){return searched;}
    Item getSearchItem(){return searchItem;}
    std::string getNorthArea(){return northArea;}
    std::string getEastArea(){return eastArea;}
    std::string getSouthArea(){return southArea;}
    std::string getWestArea(){return westArea;}


    void setId(std::string);
    void setName(std::string);
    void setText(std::string);
    void setBackgroundFile(std::string);
    void setSearchResult(std::string);
    void setSearched(bool);
    void setSearchItem(Item);
    void setNorthArea(std::string);
    void setEastArea(std::string);
    void setSouthArea(std::string);
    void setWestArea(std::string);
    void setEnemies(std::vector<Enemy>);
    Enemy createEnemy();
    bool hasEnemies();

};
