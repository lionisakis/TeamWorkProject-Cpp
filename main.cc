#include "Items.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"

#include "Hero.h"
#include "Monster.h"

#include "Paladin.h"
#include "Warrior.h"
#include "Sorcerer.h"

#include "IceSpell.h"
#include "FireSpell.h"
#include "LightingSpell.h"

#include "Spirit.h"
#include "Exoskeleton.h"
#include "Dragon.h"

void checkingForLivings();
void checkingForItems();

int main(void){
    // checkingForItems();
    checkingForLivings();
}

void checkingForItems(){
    Item* item = new Armor("FirstItem", 2, 4, 3);
    item->use();
}

void checkingForLivings(){
    Paladin pal=Paladin("Paladin");
    Warrior war=Warrior("Warrior");
    Sorcerer sorc=Sorcerer("Sorcerer");

    Dragon drag= Dragon("Dragaris",1);
    Spirit spirit= Spirit("Spirit",1);
    Exoskeleton exoskeleton= Exoskeleton("Exoskeleton",1);

    pal.print();
    pal.levelUp();
    Hero* hero=&pal;
    drag.print();
    drag.attack(hero);
    hero->print();
}