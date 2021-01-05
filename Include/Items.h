#pragma once
#include <iostream>
#include <cstring>
using namespace std;

#define WEAPON 1;
#define ARMOR 2;
#define POTION 3;

class Item{
    private:
        string name;
        int price;
        int level;
        int type;
    public:
        Item(string name_init = "Nothing", int price_init = 0, int level_init = 0);
        ~Item();
        string getName(void);
        int getPrice(void);
        int getLevel(void);
        void use(void);
        int getType(void);
        void setType(int);
};