#include "Weapon.h"

Weapon::Weapon(string name_init, int price_init, int level_init, int damage_init, int hands_init):Item(name_init, price_init, level_init){
    this->damage = damage_init;
    this->hands = hands_init;
    Item::setType(WEAPON);
}

Weapon::~Weapon(){
}

int Weapon::getDamage(void){
    return this->damage;
}

int Weapon::getHands(void){
    return this->hands;
}

void Weapon::printInfo(void){
    Item::print();
    cout << "Damage: " << this->damage << endl;
}