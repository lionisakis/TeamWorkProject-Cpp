#include "IceSpell.h"

IceSpell::IceSpell(string name_init, int price_init, int level_init, int decrease_init):Spell(name_init, price_init, level_init){
    this->decrease_damage = decrease_init;
    Spell::setType(ICESPELL);
}

IceSpell::~IceSpell(){
}

int IceSpell::getDecreaseDamage(void){
    return this->decrease_damage;
}

void IceSpell::printInfo(void){
    Spell::print();
    cout << "Decrease Damage: " << this->decrease_damage << endl;
}