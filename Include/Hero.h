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

class Monster;
class Spell;

class Hero: public Living{
    private:
        Weapon* weapon1;
        Weapon* weapon2;
        Armor* armor;
        int magicPower;
        int mpUsed;
        int maxMP;
        int strength;
        int dexerity;
        int agility;
        int money;
        int experience;
        int hands;
        vector<Item*> items;
        vector<Spell*> spells;
        int findItem(const Item* item)const;

        bool spellcast(Monster* monster,Spell* spell);
        void printSpellsCombat() const;
    public:
        // stats
        Hero(string nameHero,int strengthHero,int dexerityHero, int agilityHero);
        ~Hero();
        bool levelUp(int strengthHero,int dexerityHero, int agilityHero,int magicPowerHero=10);
        void addToStat(string type,int increase);
        void restoreMP(int mp);
        int getDexterity(void)const;
        int getMP(void)const;
        int getMPused()const;
        int giveEXP(int exp);

        // combat
        void useMagicPower(int usemagicPowerHero);
        bool castSpell(Monster* monster);
        bool attack(Monster* monster) const;
        bool takeDamage(int damage);
        void addEXP(int exp);
        int getDamage()const;
        
        // items of the hero
        bool buy(Spell* spell);
        bool buy(Item* item);
        const vector<Item*> inventory()const;
        bool useInBattle();
        bool use(Item* item);
        bool sell(Item* item);
        void addMoney(int addMoney);
        int getMoney()const;
        
        // un/equip items
        bool equipWeapon(Item* item);
        bool equipArmor(Item* item);
        void usePotion(Item* item);
        void unequipWeapon();
        void unequipArmor();

        // get functions
        int getMagicPower(void)const;

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