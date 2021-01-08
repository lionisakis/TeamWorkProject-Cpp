#pragma once
#include <iostream>
#include <string.h>
#include <Monster.h>
using namespace std;


class Dragon:public Monster{
    public:
        Dragon(string name,int levelHero,int previousHealth=0);
};