#include "IceSpell.h"

IceSpell::IceSpell(string name_init, int price_init, int level_init, int decrease_init):Spell(name_init, price_init, level_init){
    this->decrease_damage = decrease_init;
    Spell::setType(ICESPELL);
    cout << "A new IceSpell with name: " << Spell::getName() << " has been created" << endl; 
}

IceSpell::~IceSpell(){
    cout << "An IceSpell with name: " << Spell::getName() << " is about to be destroyed" << endl; 
}

int IceSpell::getDecreaseDamage(void){
    return this->decrease_damage;
}

void IceSpell::printInfo(void){
    Spell::print();
    cout << "Decrease Damage: " << this->decrease_damage << endl;
}