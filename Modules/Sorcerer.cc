#include "Sorcerer.h"
#include "FireSpell.h"
#include "IceSpell.h"
#include "LightingSpell.h"

Sorcerer::Sorcerer(string name):
    Hero(name,0,10,10)
{
    Item* weapon = new Weapon("Starting Sword",0,1,10,1);
    Spell* spell1 = new FireSpell("Amber",0,1,5);
    Spell* spell2 = new IceSpell("Ice Shard",0,1,5);
    Spell* spell3 = new LightingSpell("Lighting Ball",0,1,5);

    Hero::buy(weapon);
    Hero::buy(spell1);
    Hero::buy(spell2);
    Hero::buy(spell3);
    Hero::use(weapon);
    Hero::addMoney(20);
}
void Sorcerer::levelUp(){
    Hero::levelUp(10,0,10,10);
}