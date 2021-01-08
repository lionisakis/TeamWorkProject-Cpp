#pragma once
#include "Items.h"
#include "Hero.h"

class Hero;

class Potion:public Item{
    private:
        string type; //what increases
        string usefull;
        int amount; //amount of increasment
        bool available;
    public:
        Potion(string name_init = "Nothing", int price_init = 0, int level_init = 0, string use = 0, int amount = 0, bool available_init = true);
        string getUse(void);
        int getAmount(void)const;
        bool getAvailable(void)const;
        void printInfo(void)const;
        bool use(Hero*);
        string getUsefull(void)const;
};