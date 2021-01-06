#pragma once
#include <iostream>
#include <string.h>
using namespace std;


class Living{
    private:
        string name;
        int healthPower;
        int used;
        int level;
        int maxHP;
    protected:
        void levelUp();
    public:
        Living(string nameLiving,int levelLiving,int heathlPowerLiving);
        void increaseHealthPower(int increase);
        int getLevel() const;
        void takeDamage(int damage);
        bool isActive()const;
        int getHP() const;
        void restoreHP(int hp);
        int getHPUsed()const;
        string getName(void)const;
        void printCharacter()const;
};