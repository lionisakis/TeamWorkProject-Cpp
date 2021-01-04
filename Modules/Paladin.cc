#include "Paladin.h"

Paladin::Paladin(string name):
    Hero(name,10,10,0)
{
}
void Paladin::levelUp(){
    Hero::levelUp(10,0,10,10);
}