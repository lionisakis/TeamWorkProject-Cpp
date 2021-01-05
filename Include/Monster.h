#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Hero.h"
#include "Living.h"

using namespace std;

class Hero;
class Monster: public Living{
    private:
        const int maxDamage;
        const int minDamage;
        const int armor;
        const int doge;
        const string type;
    public:
        // stats
        Monster(string name,string type,int levelHero,int maxDamageMonster,int minDamageMonster, int armorMonster,int dogeMonster);

        void attack(Hero* hero)const;
        bool takeDamage(int damage);

        string getType() const;

        void printStats() const;
        void print() const;
};