#include "Warrior.h"

Warrior::Warrior(string name):
    Hero(name,10,0,10)
{
}
void Warrior::levelUp(){
    Hero::levelUp(10,0,10,10);
}