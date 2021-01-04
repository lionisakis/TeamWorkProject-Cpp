#include "LightingSpell.h"

LightingSpell::LightingSpell(string name_init, int price_init, int level_init, int decrease_init):Spell(name_init, price_init, level_init){
    this->decrease_avoid = decrease_init;
    cout << "A new LightingSpell with name: " << Spell::getName() << " has been created" << endl; 
}

LightingSpell::~LightingSpell(){
    cout << "An LightingSpell with name: " << Spell::getName() << " is about to be destroyed" << endl; 
}