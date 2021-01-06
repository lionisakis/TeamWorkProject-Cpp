#include "Weapon.h"

Weapon::Weapon(string name_init, int price_init, int level_init, int damage_init, int hands_init):Item(name_init, price_init, level_init){
    this->damage = damage_init;
    this->hands = hands_init;
    Item::setType(WEAPON);
}

int Weapon::getDamage(void)const{
    return this->damage;
}

int Weapon::getHands(void)const{
    return this->hands;
}

void Weapon::printInfo(void)const{
    Item::print();
    cout << "Damage: " << this->damage << endl;
}