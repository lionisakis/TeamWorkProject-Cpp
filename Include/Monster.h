#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Hero.h"
#include "Living.h"

#include "Spell.h"

using namespace std;

class Hero;
class Spell;

class Monster: public Living{
    private:
        const int maxDamage;
        const int minDamage;
        const int armor;
        const int doge;
        const string type;
        int decreanseDefence;
        int decreaseDamage;
        int decreaseAvoid;
        int rounds[3];
    public:
        // stats
        Monster(string name,string type,int levelHero,int maxDamageMonster,int minDamageMonster, int armorMonster,int dogeMonster,int previousMonsterHealth=0);

        void attack(Hero* hero);
        bool takeDamage(int damage);
        void getDepuff(Spell* spell);

        string getType() const;

        void printStats() const;
        void print() const;
};