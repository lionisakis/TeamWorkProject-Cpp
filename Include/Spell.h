#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Spell{
    private:
        string name;
        int price;
        int level;
        int damage_up;
        int damage_down;
        int magicPower;
    public:
        Spell(string name_init = "Nothing", int price_init = 0, int level_init = 0, int damage_up_init = 0, int damage_down_init = 0, int health = 0);
        ~Spell();
        string getName(void);
        int getPrice(void);
        int getLevel(void);
        int getHealth(void);
        int getMagicPower(void);
};