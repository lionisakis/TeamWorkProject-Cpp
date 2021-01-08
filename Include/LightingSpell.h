#pragma once
#include "Spell.h"

class LightingSpell:public Spell{
    private:
        int decrease_avoid;
    public:
        LightingSpell(string name_init = "Nothing", int price_init = 0, int level_init = 0, int decrease_init = 0, int damage_down = 0, int damage_up = 0, int magic_power = 0);
        int getDecreaseAvoid(void)const;
        void printInfo(void)const;
};