#pragma once
#include "Spell.h"

class IceSpell:public Spell{
    private:
        int decrease_damage;
    public:
        IceSpell(string name_init = "Nothing", int price_init = 0, int level_init = 0, int decrease_init = 0);
        ~IceSpell();
        int getDecreaseDamage(void);
        void printInfo(void);
};