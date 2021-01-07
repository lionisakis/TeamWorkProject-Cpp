#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#pragma once

#include "Define.h"
#include "Living.h"
#include "Hero.h"
#include "Market.h"

class Block{
    private:
        string name;
        vector <Hero*> heroes;
    public:
        Block(string name_init = "Nothing");
        ~Block();
        void move(vector <Hero*>);
        void print(void);
        int getSize(void);
        void setName(string);
        string getName(void);
        void clear(void);
};