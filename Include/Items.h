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
        int type;
    public:
        Item(string name_init = "Nothing", int price_init = 0, int level_init = 1);
        ~Item();
        string getName(void);
        int getPrice(void);
        int getLevel(void);
        void use(void);
        int getType(void);
        void setType(int);
        void print(void);
};