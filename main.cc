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

#include "UI.h"

void checkingForLivings();
void checkingForItems();
void checkingFighting();

int main(void){
    // checkingForItems();
    // checkingForLivings();
    checkingFighting();
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
    // Item* item1 = new Armor("FirstItem", 20, 1, 1);
    // Item* item2 = new Weapon("2Item", 20, 1, 1);
    // pal.buy(item1);
    // pal.buy(item2);
    // pal.printInventory();
    // pal.use(item2);
    // pal.use(item1);
    // pal.printInventory();
    // pal.print();
    Hero* p = new Hero("PAL", 1, 1, 1);
    Potion* potion = new Potion("Name", 3, 1, 2, 10, false);
    p->print();
    potion->use(p);
    p->print();
    // pal.print();
    // delete item1;
    // delete item2;

}

void checkingFighting(){
    vector<Hero*> heros;
    heros.push_back(new Paladin("Paladin"));
    heros.push_back(new Warrior("Warrior"));
    heros.push_back(new Sorcerer("Sorcerer"));

    Item* item = new Weapon("Basic Weapon",0,1,10,1);
    Spell* spell = new FireSpell("Fire Ball",0,1,0);
    heros.at(0)->addMoney(100);
    heros.at(0)->buy(item);
    heros.at(0)->buy(spell);
    heros.at(0)->use(item);
    heros.at(0)->printCombatStats();
    heros.at(0)->printInventory();
    cout<<"\n";
    battle(heros);
    heros.at(0)->print();
    delete item;
    delete spell;
    // for(int i=0;i<heros.size();i++)
    //     delete heros.at(i);
}