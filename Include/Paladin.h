#pragma once
#include <iostream>
#include <string.h>
#include <Hero.h>
using namespace std;


class Paladin:public Hero{
    public:
        Paladin(string name);
        void levelUp();
};