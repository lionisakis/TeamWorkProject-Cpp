#pragma once
#include <iostream>
#include <string.h>
#include <Monster.h>
using namespace std;


class Spirit:public Monster{
    public:
        Spirit(string name,int levelHero,int previousHealth=0);
};