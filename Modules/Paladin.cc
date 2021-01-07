#include "Paladin.h"
#include "Armor.h"
#include "Potion.h"
#include "Weapon.h"
#include "Items.h"
#include "Define.h"

Paladin::Paladin(string name):
    Hero(name,10,10,0)
{
    Item* weapon = new Weapon("Starting Sword",0,1,10,1);
    Item* armor = new Armor("Starting Armor",0,1,10);
    Item* potion1=new Potion("Health Potion",0,1,HEALTHPOWER,10,true);
    Hero::buy(weapon);
    Hero::buy(armor);
    Hero::buy(potion1);
    Hero::use(weapon,false);
    Hero::use(armor,false);
    Hero::addMoney(20);
}
void Paladin::levelUp(){
    Hero::levelUp(10,0,10,10);
}