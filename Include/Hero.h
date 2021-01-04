#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Items.h"
#include "Living.h"
#include "Monster.h"

using namespace std;

class Monster;
class Hero: public Living{
    private:
        int magicPower;
        int strength;
        int dexerity;
        int agility;
        int money;
        int experience;
        vector<Item*> items;
    public:
        Hero(string nameHero,int strengthHero,int dexerityHero, int agilityHero);
        
        // combat
        void levelUp(int strengthHero,int dexerityHero, int agilityHero,int magicPowerHero=10);
        void attack(Monster* monster);
        void takeDamage(int damage);

        // items of the hero
        // void buy(const Item* item);
        // void addItem(const Item* item);
        // const vector<Item*> inventory()const;
        // void use(const Item);
        // void sell(const Item);
        
        // print functions
        void printStats() const;
        void printItems() const;
        void print() const;
};