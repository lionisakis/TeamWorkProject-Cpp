#pragma once
#include "Items.h"

class Weapon:public Item{
    private:
        int damage;
        int hands;
    public:
        Weapon(string name_init = "Nothing", int price_init = 0, int level_init = 0, int damage = 0, int hands = 0);
        ~Weapon();
        int getDamage(void);
        int getHands(void);
        void printInfo(void);
};