#include "Items.h"
#include "Weapon.h"
#include "Armor.h"

#include "Hero.h"
#include "Monster.h"

#include "Paladin.h"
#include "Warrior.h"
#include "Sorcerer.h"

#include "Spirit.h"
#include "Exoskeleton.h"
#include "Dragon.h"

void checkingForLivings();

int main(void){
    Armor* item = new Armor("Sward", 4, 2, 1000);
    delete item;
    // checkingForLivings();
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