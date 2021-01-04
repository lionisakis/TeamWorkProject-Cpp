#pragma once
#include <iostream>
#include <string.h>
#include <Hero.h>
using namespace std;


class Sorcerer:public Hero{
    public:
        Sorcerer(string name);
        void levelUp();
};