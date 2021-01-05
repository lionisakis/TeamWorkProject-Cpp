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

        int findItem(const Item* item)const;
    public:
        Hero(string nameHero,int strengthHero,int dexerityHero, int agilityHero);
        
        // combat
        void levelUp(int strengthHero,int dexerityHero, int agilityHero,int magicPowerHero=10);
        void attack(Monster* monster) const;
        bool spellcast(Monster* monster,Spell* spell) const;
        void takeDamage(int damage);

        // items of the hero
        bool buy(Item* item);
        const vector<Item*> inventory()const;
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
        void printEquipedItems() const;
        void printInventory() const;
        void print() const;
};