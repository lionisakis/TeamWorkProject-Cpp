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
        int findSpell(const Spell* spell)const;

        bool spellcast(Monster* monster,Spell* spell);
        void printSpellsCombat() const;
        void printItemsForInventory() const;
        int findSpell(Spell* spell)const;
        void throwAway(int indexItem);
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
        bool useInventory();
        bool use(Item* item,bool flag=true);
        bool sell(Item* item);
        bool sell(Spell* spell);
        void addMoney(int addMoney);
        int getMoney()const;
        void give(Item* item);
        bool giveItem(Hero* otherHero,int index);
        
        // un/equip items
        bool equipWeapon(Item* item,bool flag=true);
        bool equipArmor(Item* item,bool flag=true);
        bool usePotion(Item* item);
        void unequipWeapon();
        void unequipArmor();

        // get functions
        int getMagicPower(void)const;
        Item* getItem(int);
        Spell* getSpell(int);
        int getItemSize(void);
        int getSpellSize(void);

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