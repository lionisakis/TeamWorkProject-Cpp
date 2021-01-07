#include "Warrior.h"
#include "Armor.h"
#include "Potion.h"
#include "Weapon.h"
#include "Potion.h"
#include "Items.h"
#include "Define.h"

Warrior::Warrior(string name):
    Hero(name,10,0,10)
{
    Item* weapon1 = new Weapon("Starting Sword",0,1,10,1);
    Item* weapon2 = new Weapon("Starting Sword",0,1,10,1);
    Item* potion1=new Potion("Health Potion",0,1,HEALTHPOWER,10,true);
    Hero::buy(weapon1);
    Hero::buy(weapon2);
    Hero::buy(potion1);
    Hero::use(weapon1,false);
    Hero::use(weapon2,false);
    Hero::addMoney(20);
}
void Warrior::levelUp(){
    Hero::levelUp(10,0,10,10);
}