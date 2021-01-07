#pragma once
#include <iostream>
#include <cstring>
#include "Hero.h"
#include "Define.h"
using namespace std;

class Hero;
class Spell{
    private:
        string name;
        int price;
        int level;
        int damage_up;
        int damage_down;
        int magicPower;
        string type;
        int doge;
    public:
        Spell(string name_init = "Nothing", int price_init = 0, int level_init = 1, int damage_up_init = 0, int damage_down_init = 0, int magic_power_init = 0);
        ~Spell();
        string getName(void) const;
        int getPrice(void) const;
        int getLevel(void) const;
        int getHealth(void) const;
        int getMagicPower(void) const;
        int getDamage(Hero*) const;
        string getType(void) const;
        void setType(string);
        void printCombat(void)const;
        void print(void) const;
};