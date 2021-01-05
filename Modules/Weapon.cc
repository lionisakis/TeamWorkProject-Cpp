#include "Weapon.h"

Weapon::Weapon(string name_init, int price_init, int level_init, int damage_init, int hands_init):Item(name_init, price_init, level_init){
    this->damage = damage_init;
    this->hands = hands_init;
    Item::setType(WEAPON);
    cout << "A new weapon with name: " << Item::getName() << " has been created" << endl; 
}

Weapon::~Weapon(){
    cout << "A weapon with name: " << Item::getName() << " is about to be destroyed" << endl; 
}

int Weapon::getDamage(void){
    return this->damage;
}

int Weapon::getHands(void){
    return this->hands;
}