#include "FireSpell.h"

FireSpell::FireSpell(string name_init, int price_init, int level_init, int decrease_init):Spell(name_init, price_init, level_init){
    this->decrease_defence = decrease_init;
    Spell::setType(FIRESPELL);
    cout << "A new FireSpell with name: " << Spell::getName() << " has been created" << endl; 
}

FireSpell::~FireSpell(){
    cout << "An FireSpell with name: " << Spell::getName() << " is about to be destroyed" << endl; 
}

int FireSpell::getDecreaseDefence(void){
    return this->decrease_defence;
}