#include "LightingSpell.h"

LightingSpell::LightingSpell(string name_init, int price_init, int level_init, int decrease_init, int damage_down, int damage_up, int magic_power):Spell(name_init, price_init, level_init, damage_up, damage_down, magic_power){
    this->decrease_avoid = decrease_init;
    Spell::setType(LIGHTINGSPELL);
}

int LightingSpell::getDecreaseAvoid(void)const{
    return this->decrease_avoid;
}

void LightingSpell::printInfo(void)const{
    Spell::print();
    cout << "Decrease Avoid: " << this->decrease_avoid << endl;
}