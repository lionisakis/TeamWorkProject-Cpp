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
void checkMarket(vector<Hero*>,Util);
void checkBlock(vector<Hero*>);
void checkGrid(vector<Hero*>, Util);

int main(void){
    Util util;
    // Spawn Heroes
    vector<Hero*>Heroes = spawnHeroes();
    if(Heroes.size()==0)
        return -1;

    PlayGame(util, Heroes);


    // Delete Heroes
    quitGame(Heroes);
}