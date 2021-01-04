#pragma once
#include <iostream>
#include <string.h>
using namespace std;


class Living{
    private:
        string name;
        int healthPower;
        int level;
    protected:
        void leveUp();
    public:
        Living(string nameLiving);
        void takeDamage(int damage);
        bool isActive()const;
        string getName(void)const;
};