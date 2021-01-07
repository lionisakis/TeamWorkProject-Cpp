#include "Warrior.h"

Warrior::Warrior(string name):
    Hero(name,10,0,10)
{
    Item* weapon1 = new Weapon("Starting Armor1",0,1,10,1);
    Item* weapon2 = new Weapon("Starting Armor2",0,1,10,1);
    Hero::buy(weapon1);
    Hero::buy(weapon2);
    Hero::use(weapon1);
    Hero::use(weapon2);
    Hero::addMoney(20);
}
void Warrior::levelUp(){
    Hero::levelUp(10,0,10,10);
}