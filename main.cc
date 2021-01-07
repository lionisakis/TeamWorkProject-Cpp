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
void quitGame(vector<Hero*>);
void names(Util);
void checkMarket(Util);

int main(void){
    Util util;
    // Spawn Heros
    vector<Hero*>heros = spawnHeros();
   
    // Check for Debug

    // Item* item = util.spawnPotion(1, 1, HEALTHPOWER, 10, false);
    // item->printCombat();

    battle(heros,util);
    // checkMarket(util);

    // Delete Heros
    // quitGame(heros);
}

void checkMarket(Util util){
    Market* market = new Market(util);
    Hero* hero = new Hero("AN", 100, 100, 100);
    hero->addMoney(100);
    market->buy(hero);
    market->printMarket();
    hero->printInventory();
}