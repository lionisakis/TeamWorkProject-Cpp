#include "Weapon.h"

Weapon::Weapon(string name_init, int price_init, int level_init, int damage_init, int hands_init):Item(name_init, price_init, level_init){
    this->damage = damage_init;
    this->hands = hands_init;
    cout << "A new weapon with name: " << Item::get_name() << " has been created" << endl; 
}

Weapon::~Weapon(){
    cout << "A weapon with name: " << Item::get_name() << " is about to be destroyed" << endl; 
}