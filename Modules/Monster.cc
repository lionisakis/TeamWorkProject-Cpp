#include <stdlib.h>
#include <time.h>   
#include "Living.h"
#include "Hero.h"
#include "Monster.h"

#define STARTINGSTATS 10

int countHP(int level){
    srand(time(NULL));
    return rand()%(10*level+20)+25;
}

Monster::Monster(string name,string typeMonster,int levelHero,int minDamageMonster,int maxDamageMonster, int armorMonster,int dogeMonster):
Living(name,levelHero,countHP(levelHero)),type(typeMonster),maxDamage(maxDamageMonster+levelHero*5),minDamage(minDamageMonster+levelHero*5),
armor(armorMonster+levelHero*5),doge(dogeMonster+levelHero*5)
{
}

void Monster::attack(Hero* hero)const{
    srand(time(NULL));
    int damage=rand()%maxDamage+minDamage;
    cout<<"Attacking Hero("<<hero->getName()<<") with damage:"<<damage<<"\n";
    hero->takeDamage(damage);
}

bool Monster::takeDamage(int damage){
    srand(time(NULL));
    int prob= (int) rand()%100;
    if (prob<=doge){
        cout<<"Doged the attacked\n";
        return false;
    }
    cout<<"Taking damge: "<<damage-armor<<"\n";
    Living::takeDamage(damage-armor);
    cout<<getName()<<" has HP: "<<getHP()<<"\n";
    if(getHP()==0){
        cout<<getName()<<" was killed\n";
    }
    return true;
}

string Monster::getType() const{
    return type;
}

void Monster::printStats() const{
    cout<<"Damage: ("<<minDamage<<","<<maxDamage<<")\n";
    cout<<"Armor: "<<armor<<"\n";
    cout<<"Doge propability: "<<doge<<"%\n";

}

void Monster::print() const{
    Living::printCharacter();
    cout<<"Type: "<<type<<"\n";
    printStats();
}