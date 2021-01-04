#pragma once
#include <iostream>
#include <string.h>
#include "Living.h"

using namespace std;


class Hero: public Living{
    private:
        int magicPower;
        int strength;
        int dexerity;
        int agility;
        int money;
        int experience;
    public:
        Hero(string nameHero,int strengthHero,int dexerityHero, int agilityHero);
        void leveUp(int magicPowerHero,int strengthHero,int dexerityHero, int agilityHero);
};