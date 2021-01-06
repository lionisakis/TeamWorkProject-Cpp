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
        string getName(void);
        int getPrice(void);
        int getLevel(void);
        int getHealth(void);
        int getMagicPower(void);
        int getDamage(Hero*);
        string getType(void);
        void setType(string);
        void print(void);
};