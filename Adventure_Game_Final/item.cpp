#include "item.h"

Item::Item()
{
    this->name = "No item";
    this->description = "No item";
}

Item::Item(std::string name, std::string description, std::string imagePath, bool canSell, int value)
{
    this->name = name;
    this->description = description;
    this->imagePath = imagePath;
    this->canSell = canSell;
    this->value = value;
}

void Item::setName(std::string name){
    this->name = name;
}
void Item::setDescription(std::string description){
    this->description = description;
}
void Item::setImagePath(std::string imagePath){
    this->imagePath = imagePath;
}
void Item::setCanSell(bool canSell){
    this->canSell = canSell;
}
void Item::setValue(int value){
    this->value = value;
}
