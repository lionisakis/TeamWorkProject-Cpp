#include "FireSpell.h"

FireSpell::FireSpell(string name_init, int price_init, int level_init, int decrease_init, int damage_down, int damage_up, int magic_power):Spell(name_init, price_init, level_init, damage_up, damage_down, magic_power){
    this->decrease_defence = decrease_init;
    Spell::setType(FIRESPELL);
}

int FireSpell::getDecreaseDefence(void)const{
    return this->decrease_defence;
}

void FireSpell::printInfo(void)const{
    Spell::print();
    cout << "Decrease Defence: " << this->decrease_defence << endl;
}