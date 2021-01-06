#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#include "Items.h"
#include "Spell.h"
#include "Hero.h"
#include "Monster.h"

using namespace std;


class Util{
    private:
        vector<string> namesLiving;
        vector<string> namesArmor;
        vector<string> namesWeapon; 
        vector<string> namesSpell;
        vector<string> namesPotion;         

    public:
        Util();

        string randomName(int indexType) ;

        Monster* spawnMonster(int indexType,int levelHero);
        Monster* spawnDragon(int levelHero);
        Monster* spawnExoskeleton(int levelHero);
        Monster* spawnSpirit(int levelHero);

        Item* spawnItem(int indexType,int price , int level , int  damage_defence_use,int hands_amount=0,bool available=false);
        Item* spawnArmor(int price , int level , int  defence);
        Item* spawnPotion(int price , int level , int  use,int amount,bool available=false);
        Item* spawnWeapon(int price , int level , int  damage,int hands);

        Spell* spawnSpell(int indexType, int price , int level , int decrease);
        Spell* spawnLightingSpell(int price , int level , int decrease);
        Spell* spawnFireSpell(int price , int level , int decrease);
        Spell* spawnIceSpell(int price , int level , int decrease);

};