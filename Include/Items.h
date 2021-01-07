#pragma once
#include <iostream>
#include <cstring>
using namespace std;
#include "Define.h"

class Item{
    private:
        string name;
        int price;
        int level;
        string type;
    protected:
        void setType(string);
    public:
        Item(string name_init = "Nothing", int price_init = 0, int level_init = 1);
        string getName(void)const;
        int getPrice(void)const;
        int getLevel(void)const;
        void use(void);
        string getType(void)const;
        void printCombat(void)const;
        void print(void)const;
};