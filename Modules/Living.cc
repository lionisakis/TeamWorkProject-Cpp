#include "Living.h"
#include <iostream>
Living::Living(string nameLiving,int levelLiving,int heathlPowerLiving)
{
    name=nameLiving;
    healthPower=heathlPowerLiving;
    level=levelLiving;
    used=0;
    maxHP=healthPower;
}

void Living::increaseHealthPower(int increase){
    healthPower+=increase;
    maxHP+=increase;
}


void Living::takeDamage(int damage){
    healthPower-=damage;
    if (healthPower<0)
        healthPower=0;
    used+=damage;
}

void Living::levelUp(){
    level++;
}

bool Living::isActive()const{
    return healthPower==0;
}

string Living::getName()const{
    return name;
}
int Living::getLevel() const{
    return level;
}
int Living::getHP() const{
    return healthPower;
}
void Living::restoreHP(int hp){
    if(healthPower<maxHP){
        if(healthPower+hp<=maxHP)
            healthPower+=hp;
        else
            healthPower=maxHP;        
        cout<<name<<" is restoring Health Power: "<<hp<<" so the total Health Power(HP) is:"<<healthPower<<" previous HP:"<<healthPower-hp<<"\n";
    }
}
int Living::getHPUsed()const{
    return used;
}
void Living::printCharacter()const{
    cout<<"------------------------------\n";
    cout<<"Name:"<<name<<"\n";
    cout<<"Health Power(HP):"<<healthPower<<"\n";
    cout<<"Level:"<<level<<"\n";
    cout<<"------------------------------\n";
}