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
        void levelUp();
    public:
        Living(string nameLiving,int levelLiving=1);
        void increaseHealthPower(int increase);
        int getLevel() const;
        void takeDamage(int damage);
        bool isActive()const;
        string getName(void)const;
        void printCharacter()const;
};