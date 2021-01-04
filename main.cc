#include "Items.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"

#include "Paladin.h"
#include "Warrior.h"
#include "Sorcerer.h"

#include "IceSpell.h"
#include "FireSpell.h"
#include "LightingSpell.h"

int main(void){
    LightingSpell* item = new LightingSpell("Sward", 4, 2, 1);
    delete item;
    
    // Paladin("Paladin");
    // Warrior("Warrior");
    // Sorcerer("Sorcerer");

}