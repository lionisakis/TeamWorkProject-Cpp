#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Items.h"
#include "Armor.h"
#include "Potion.h"
#include "Weapon.h"
#include "Living.h"
#include "Monster.h"
#include "Spell.h"


using namespace std;

#define HEALTHPOWER 0
#define MAGICPOWER 1
#define STRENGTH 2
#define DEXERITY 3
#define AGILITY 4

class Monster;
class Hero: public Living{
    private:
        Weapon* weapon1;
        Weapon* weapon2;
        Armor* armor;
        int magicPower;
        int strength;
        int dexerity;
        int agility;
        int money;
        int experience;
        int hands;
        vector<Item*> items;
        vector<Spell*> spells;

        int findItem(const Item* item)const;
    public:
        // stats
        Hero(string nameHero,int strengthHero,int dexerityHero, int agilityHero);
        void levelUp(int strengthHero,int dexerityHero, int agilityHero,int magicPowerHero=10);
        void addToStat(int type,int increase);

        // combat
        bool castSpell(Monster* monster)const;
        bool attack(Monster* monster) const;
        bool spellcast(Monster* monster,Spell* spell) const;
        bool takeDamage(int damage);

        // items of the hero
        bool buy(Spell* spell);
        bool buy(Item* item);
        const vector<Item*> inventory()const;
        bool useInBattle();
        bool use(Item* item);
        bool sell(Item* item);
        void addMoney(int addMoney);
        
        // un/equip items
        bool equipWeapon(Item* item);
        bool equipArmor(Item* item);
        void usePotion(Item* item);
        void unequipWeapon();
        void unequipArmor();

        // print functions
        void printStats() const;
        void printCombatStats() const;
        void printEquipedItems() const;
        void printSpells() const;
        void printItems() const;
        void printMoney() const;
        void printInventory() const;
        void print() const;
};