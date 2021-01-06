#include "FireSpell.h"

FireSpell::FireSpell(string name_init, int price_init, int level_init, int decrease_init):Spell(name_init, price_init, level_init){
    this->decrease_defence = decrease_init;
    Spell::setType(FIRESPELL);
}

FireSpell::~FireSpell(){
}

int FireSpell::getDecreaseDefence(void){
    return this->decrease_defence;
}

void FireSpell::printInfo(void){
    Spell::print();
    cout << "Decrease Defence: " << this->decrease_defence << endl;
}