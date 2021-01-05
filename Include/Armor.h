#pragma once
#include "Items.h"

class Armor:public Item{
    private:
        int defence;
    public:
        Armor(string name_init = "Nothing", int price_init = 0, int level_init = 0, int defence = 0);
        ~Armor();
        int getDefence(void);
};