#pragma once
#include <iostream>
#include <string.h>
#include <Monster.h>
using namespace std;


class Exoskeleton:public Monster{
    public:
        Exoskeleton(string name,int levelHero,int previousHealth=0);
};