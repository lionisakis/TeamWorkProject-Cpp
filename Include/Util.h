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
        
        Monster* spawnDragon(int levelHero,int previousHealth=0);
        Monster* spawnExoskeleton(int levelHero,int previousHealth=0);
        Monster* spawnSpirit(int levelHero,int previousHealth=0);

        Item* spawnArmor(int price , int level , int  defence);
        Item* spawnPotion(int price , int level , string  use,int amount,bool available=false);
        Item* spawnWeapon(int price , int level , int  damage,int hands);

        Spell* spawnLightingSpell(int price , int level , int decrease, int damage_up, int damage_down, int magic_power);
        Spell* spawnFireSpell(int price , int level , int decrease, int damage_up, int damage_down, int magic_power);
        Spell* spawnIceSpell(int price , int level , int decrease, int damage_up, int damage_down, int magic_power);

};