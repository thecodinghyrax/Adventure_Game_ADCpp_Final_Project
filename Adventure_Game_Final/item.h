#include <string>
#ifndef ITEM_H
#define ITEM_H


class Item
{
private:
    // Name of the item
    std::string name;
    // Text description of the item
    std::string description;
    // Path to the item's icon
    std::string imagePath;
    // True if the item can be sold at a shop
    bool canSell;
    // Shop value of an item
    int value;

public:
    Item();
    Item(std::string name, std::string description, std::string imagePath, bool canSell, int value);

    std::string getName(){return name;}
    std::string getDescription(){return description;}
    std::string getImagePath(){return imagePath;}
    bool getCanSell(){return canSell;}
    int getValue(){return value;}

    void setName(std::string);
    void setDescription(std::string);
    void setImagePath(std::string);
    void setCanSell(bool);
    void setValue(int);

};

#endif // ITEM_H
