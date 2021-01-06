#include "Armor.h"

Armor::Armor(string name_init, int price_init, int level_init, int defence_init):Item(name_init, price_init, level_init){
    this->defence = defence_init;
    Item::setType(ARMOR);
}

Armor::~Armor(){
}

int Armor::getDefence(void){
    return this->defence;
}

void Armor::printInfo(void){
    Item::print();
    cout << "Defence: " << this->defence << endl;
}