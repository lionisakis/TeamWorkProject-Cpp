#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

#include "Util.h"

#include "Items.h"
#include "Armor.h"
#include "Weapon.h"
#include "Potion.h"

#include "Spell.h"
#include "FireSpell.h"
#include "IceSpell.h"
#include "LightingSpell.h"

#include "Hero.h"

class Market{
    private:
        vector<Item*> items;

        vector<Spell*> spells;

    public:
        Market(Util,int);
        ~Market();

        void printItems(void)const;
        void printSpells(void)const;
        void printMarket(void)const;
        void useMarket(Hero*);
        void buy(Hero*);
        void sell(Hero*);
};