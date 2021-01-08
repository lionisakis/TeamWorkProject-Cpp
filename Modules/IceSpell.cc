#include "IceSpell.h"

IceSpell::IceSpell(string name_init, int price_init, int level_init, int decrease_init, int damage_down, int damage_up, int magic_power):Spell(name_init, price_init, level_init, damage_up, damage_down, magic_power){
    this->decrease_damage = decrease_init;
    Spell::setType(ICESPELL);
}

int IceSpell::getDecreaseDamage(void)const{
    return this->decrease_damage;
}

void IceSpell::printInfo(void)const{
    Spell::print();
    cout << "Decrease Damage: " << this->decrease_damage << endl;
}