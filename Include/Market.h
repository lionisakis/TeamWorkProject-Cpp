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
        vector<Item> items;

        vector<Spell> spells;

    public:
        Market(Util);
        ~Market();

        void printItems(void);
        void printSpells(void);
        void printMarket(void);
        void buy(Hero*);
};