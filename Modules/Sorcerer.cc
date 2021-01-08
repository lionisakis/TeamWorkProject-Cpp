#include "Sorcerer.h"
#include "Armor.h"
#include "FireSpell.h"
#include "IceSpell.h"
#include "LightingSpell.h"
#include "Potion.h"
#include "Items.h"
#include "Define.h"

Sorcerer::Sorcerer(string name):
    Hero(name,0,10,10)
{
    Item* weapon = new Weapon("Starting Wand",0,1,5,1);
    Spell* spell1 = new FireSpell("Amber",0,1,15,10,40,5);
    Spell* spell2 = new IceSpell("Ice Shard",0,1,15,10,40,5);
    Spell* spell3 = new LightingSpell("Lighting Ball",0,1,15,10,40,5);
    Item* potion1=new Potion("Health Potion",0,1,HEALTHPOWER,10,true);
    Item* potion2=new Potion("MP Potion",0,1,MAGICPOWER,10,true);
    Hero::buy(weapon);
    Hero::buy(spell1);
    Hero::buy(spell2);
    Hero::buy(spell3);
    Hero::buy(potion1);
    Hero::buy(potion2);
    Hero::use(weapon,false);
    Hero::addMoney(20);
}
void Sorcerer::levelUp(){
    Hero::levelUp(10,0,10,10);
}