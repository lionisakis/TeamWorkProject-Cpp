#pragma once
#include "Items.h"
#include "Hero.h"

class Hero;

class Potion:public Item{
    private:
        int type; //what increases
        int amount; //amount of increasment
        bool available;
    public:
        Potion(string name_init = "Nothing", int price_init = 0, int level_init = 0, int use = 0, int amount = 0, bool available_init = false);
        ~Potion();
        int getUse(void);
        int getAmount(void);
        bool getAvailable(void);
        void printInfo(void);
        void use(Hero*);
};