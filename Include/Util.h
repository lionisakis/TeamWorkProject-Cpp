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
        vector<string> namesArmor;
        vector<string> namesLiving;
        vector<string> namesPotion;         
        vector<string> namesSpell;
        vector<string> namesWeapon; 

        vector<int> previous[5];
        
        string takeRandomName(vector<string> item,int vec);
        bool checkTheNumber(int number,vector<string> item,int vec);

    public:
        Util();

        string randomName(string indexType) ;
        
        // Monster* spawnMonster(string indexType,int levelHero);
        Monster* spawnDragon(int levelHero);
        Monster* spawnExoskeleton(int levelHero);
        Monster* spawnSpirit(int levelHero);

        // Item* spawnItem(string indexType,int price , int level , int  damage_defence_use,int hands_amount=0,bool available=false);
        Item* spawnArmor(int price , int level , int  defence);
        Item* spawnPotion(int price , int level , string  use,int amount,bool available=false);
        Item* spawnWeapon(int price , int level , int  damage,int hands);

        // Spell* spawnSpell(string indexType, int price , int level , int decrease);
        Spell* spawnLightingSpell(int price , int level , int decrease);
        Spell* spawnFireSpell(int price , int level , int decrease);
        Spell* spawnIceSpell(int price , int level , int decrease);

};