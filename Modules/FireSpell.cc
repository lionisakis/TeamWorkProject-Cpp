#include "FireSpell.h"

FireSpell::FireSpell(string name_init, int price_init, int level_init, int decrease_init):Spell(name_init, price_init, level_init){
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