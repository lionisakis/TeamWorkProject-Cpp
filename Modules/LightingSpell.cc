#include "LightingSpell.h"

LightingSpell::LightingSpell(string name_init, int price_init, int level_init, int decrease_init):Spell(name_init, price_init, level_init){
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