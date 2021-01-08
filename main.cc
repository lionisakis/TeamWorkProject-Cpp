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
#include "Block.h"
#include "Grid.h"


void checkingForItems();
void quitGame(vector<Hero*>);
void names(Util);
void checkMarket(Util);
void checkBlock(vector<Hero*>);
void checkGrid(vector<Hero*>, Util);

int main(void){
    Util util;
    // Spawn Heros
    vector<Hero*>heros = spawnHeros();
    if(heros.size()==0)
        return -1;

    // checkGrid(heros, util);
    // checkBlock(heros);
    
    // Check for Debug

    battle(heros,util);

    // checkMarket(util);

    // Delete Heros
    quitGame(heros);
}

void checkGrid(vector <Hero*> heroes, Util util){
    Grid* block = new Grid(heroes, util);
    // block->move(heroes);
    block->place();
    block->print();
    // block->move(UP);
    // cout <<"MOVE TEST " <<  endl;
    // block->print();
}

void checkBlock(vector <Hero*> heroes){
    Block* block = new Block(C);
    block->move(heroes);
    block->print();
}

void checkMarket(Util util){
    Market* market = new Market(util);
    Hero* hero = new Hero("AN", 100, 100, 100);
    hero->addMoney(100);
    market->useMarket(hero);
    // market->buy(hero);
    // market->buy(hero);
    // // hero->printInventory();
    // market->sell(hero);
    market->printMarket();
    // hero->printInventory();
    delete market;
    delete hero;
}

void checkingFighting(vector<Hero*> heros,Util util){

    Item* item = util.spawnWeapon(0,2,5,1);
    Item* item1 = util.spawnWeapon(0,2,5,1);
    Item* item2 = util.spawnWeapon(0,2,5,2);
    Item* item3 = util.spawnArmor(0,1,20);
    Item* item4 = util.spawnPotion(0,1,HEALTHPOWER,20,true);

    heros.at(0)->giveEXP(100);
    heros.at(0)->levelUp(0,0,0,0);
    Spell* spell = util.spawnIceSpell(0,1,10);
    heros.at(0)->addMoney(100);
    heros.at(0)->buy(item);
    heros.at(0)->buy(item1);
    heros.at(0)->buy(item2);
    heros.at(0)->buy(item3);
    heros.at(0)->buy(item4);
    heros.at(0)->buy(spell);
    heros.at(0)->use(item);
    heros.at(0)->use(item3);
    heros.at(0)->printCombatStats();
    heros.at(0)->printInventory();
    cout<<"\n";
    // if false then quit game
    if(!battle(heros,util))
        return ;
    return ;    
}

