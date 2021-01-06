#pragma once
#include "Items.h"

class Weapon:public Item{
    private:
        int damage;
        int hands;
    public:
        Weapon(string name_init = "Nothing", int price_init = 0, int level_init = 0, int damage = 0, int hands = 0);
        int getDamage(void)const;
        int getHands(void)const;
        void printInfo(void)const;
};