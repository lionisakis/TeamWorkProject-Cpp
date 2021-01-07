#include "Paladin.h"

Paladin::Paladin(string name):
    Hero(name,10,10,0)
{
    Item* weapon = new Weapon("Starting Sword",0,1,10,1);
    Item* armor = new Armor("Starting Armor",0,1,10);
    Hero::buy(weapon);
    Hero::buy(armor);
    Hero::use(weapon);
    Hero::use(armor);
    Hero::addMoney(20);
}
void Paladin::levelUp(){
    Hero::levelUp(10,0,10,10);
}