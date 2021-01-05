#pragma once
#include <iostream>
#include <cstring>
using namespace std;

#define ICESPELL 4
#define FIRESPELL 5
#define LIGHTINGSPELL 6

class Spell{
    private:
        string name;
        int price;
        int level;
        int damage_up;
        int damage_down;
        int magicPower;
        int type;
    public:
        Spell(string name_init = "Nothing", int price_init = 0, int level_init = 1, int damage_up_init = 0, int damage_down_init = 0, int magic_power_init = 0);
        ~Spell();
        string getName(void);
        int getPrice(void);
        int getLevel(void);
        int getHealth(void);
        int getMagicPower(void);
        int getDamage(void);
        int getType(void);
        void setType(int);
        void print(void);
};