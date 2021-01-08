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

    checkGrid(heros, util);
    // checkBlock(heros);

    // checkMarket(util);

    // Delete Heros
    quitGame(heros);
}

void checkGrid(vector <Hero*> heroes, Util util){
    Grid* block = new Grid(heroes, util);
    // block->move(heroes);
    block->move(DOWN);
    block->print();
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
