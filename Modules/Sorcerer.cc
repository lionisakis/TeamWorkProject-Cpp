#include "Sorcerer.h"

Sorcerer::Sorcerer(string name):
    Hero(name,0,10,10)
{
}
void Sorcerer::levelUp(){
    Hero::levelUp(10,0,10,10);
}