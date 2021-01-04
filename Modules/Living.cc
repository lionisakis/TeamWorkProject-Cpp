#include "Living.h"
#include <iostream>
Living::Living(string nameLiving)
{
    name=nameLiving;
    healthPower=100;
    level=1;
    cout<<"A new Living organism with name: "<<name<<" has been created\n";
}

void Living::takeDamage(int damage){
    healthPower-=damage;
    if (healthPower<0)
        healthPower=0;
}

void Living::leveUp(){
    level++;
}

bool Living::isActive()const{
    return healthPower==0;
}

string Living::getName()const{
    return name;
}