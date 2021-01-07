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
#include "Util.h"
#include "Market.h"


void checkingForItems();
void checkingFighting(vector<Hero*> heros, Util util);
void quitGame(vector<Hero*>);
void names(Util);
void checkMarket(Util);

int main(void){
    Util util;
    // Spawn Heros
    vector<Hero*>heros = spawnHeros();
   
    // Check for Debug

    Item* item = util.spawnPotion(1, 1, HEALTHPOWER, 10, false);
    item->print();

    // checkingForItems();
    // checkingFighting(heros, util);
    // checkMarket(util);

    // Delete Heros
    // quitGame(heros);
}

void checkMarket(Util util){
    Market* market = new Market(util);
    Hero* hero = new Hero("AN", 100, 100, 100);
    hero->addMoney(100);
    market->buy(hero);
    // market->printMarket();
    hero->printInventory();
}

void checkingForItems(){
    Armor* item = new Armor("FirstItem", 2, 4, 3);
    item->use();
    item->printInfo();

    IceSpell* spell = new IceSpell("IceSpell", 5, 2, 10);
    spell->printInfo();
}


void checkingFighting(vector<Hero*> heros,Util util){

    Item* item = util.spawnWeapon(0,2,5,0);
    heros.at(0)->giveEXP(100);
    heros.at(0)->levelUp(0,0,0,0);
    Spell* spell = util.spawnIceSpell(0,1,10);
    heros.at(0)->addMoney(100);
    heros.at(0)->buy(item);
    heros.at(0)->buy(spell);
    heros.at(0)->use(item);
    heros.at(0)->printCombatStats();
    heros.at(0)->printInventory();
    cout<<"\n";
    // if false then quit game
    if(!battle(heros,util))
        return ;
    return ;    
}

