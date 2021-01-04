#include "Living.h"
#include <iostream>
Living::Living(string nameLiving,int levelLiving)
{
    name=nameLiving;
    healthPower=100;
    level=levelLiving;
    cout<<"A new Living organism with name: "<<name<<" has been created\n";
}

void Living::takeDamage(int damage){
    healthPower-=damage;
    if (healthPower<0)
        healthPower=0;
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

void Living::printCharacter()const{
    cout<<"Name:"<<name<<"\n";
    cout<<"Health Power(HP):"<<healthPower<<"\n";
    cout<<"Level:"<<level<<"\n";

}