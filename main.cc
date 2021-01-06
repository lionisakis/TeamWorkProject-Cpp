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


void checkingForItems();
void checkingFighting(vector<Hero*>heros,Util util);

int main(void){
    Util util;
    vector<Hero*>heros=spawnHeros();
    // checkingForItems();
    checkingFighting(heros,util);
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
    Spell* spell = util.spawnSpell(LIGHTINGSPELL,0,1,10);
    heros.at(0)->addMoney(100);
    heros.at(0)->buy(item);
    heros.at(0)->buy(spell);
    heros.at(0)->use(item);
    heros.at(0)->printCombatStats();
    heros.at(0)->printInventory();
    cout<<"\n";
    if(!battle(heros,util))
        return quitGame(heros);
    // heros.at(0)->print();
    return quitGame(heros);    
}

