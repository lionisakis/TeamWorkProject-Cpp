#pragma once
#include <iostream>
#include <string.h>
#include <Hero.h>
using namespace std;


class Warrior:public Hero{
    public:
        Warrior(string name);
        void levelUp();
};