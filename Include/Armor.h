#pragma once
#include "Items.h"

class Armor:public Item{
    private:
        int defence;
    public:
        Armor(string name_init = "Nothing", int price_init = 0, int level_init = 0, int defence_init = 0);
        int getDefence(void)const;
        void printInfo(void)const;
};