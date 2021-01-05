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
    Armor* item = new Armor("FirstItem", 2, 4, 3);
    item->use();
    item->printInfo();

    IceSpell* spell = new IceSpell("IceSpell", 5, 2, 10);
    spell->printInfo();
}

void checkingForLivings(){
    Paladin pal=Paladin("Paladin");
    Warrior war=Warrior("Warrior");
    Sorcerer sorc=Sorcerer("Sorcerer");

    Dragon drag= Dragon("Dragaris",1);
    Spirit spirit= Spirit("Spirit",1);
    Exoskeleton exoskeleton= Exoskeleton("Exoskeleton",1);

    // pal.print();
    pal.levelUp();

    pal.addMoney(40);
    pal.printInventory();
    Item* item1 = new Armor("FirstItem", 20, 1, 1);
    Item* item2 = new Weapon("2Item", 20, 1, 1);
    pal.buy(item1);
    pal.buy(item2);
    pal.printInventory();
    pal.use(item2);
    pal.use(item1);
    pal.printInventory();
    pal.print();
    delete item1;
    delete item2;

}