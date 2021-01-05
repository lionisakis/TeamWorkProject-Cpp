#include <stdlib.h>
#include <time.h>   
#include "Living.h"
#include "Hero.h"
#include "Monster.h"

#define STARTINGSTATS 10
#define MAGICPOWER 20

Monster::Monster(string name,int levelHero,int maxDamageMonster,int minDamageMonster, int armorMonster,int dogeMonster):
Living(name),maxDamage(maxDamageMonster+levelHero*10),minDamage(minDamageMonster+levelHero*10),
armor(armorMonster+levelHero*10),doge(dogeMonster+levelHero*10)
{
}

void Monster::attack(Hero* hero)const{
    srand(time(NULL));
    int damage=rand()%maxDamage+minDamage;
    cout<<"Attacking Hero with damage:"<<damage<<"\n";
    hero->takeDamage(damage);
}

bool Monster::takeDamage(int damage){
    srand(time(NULL));
    int prob= (int) rand()%100;
    if (prob<=doge){
        cout<<"Doged\n";
        return false;
    }
    cout<<"Taking damge: "<<damage-armor<<"\n";
    Living::takeDamage(damage-armor);
    return true;
}

void Monster::printStats() const{
    cout<<"Damage: ("<<minDamage<<","<<maxDamage<<")\n";
    cout<<"Armor: "<<armor<<"\n";
    cout<<"Doge propability: "<<doge<<"%\n";

}

void Monster::print() const{
    Living::printCharacter();
    printStats();
}