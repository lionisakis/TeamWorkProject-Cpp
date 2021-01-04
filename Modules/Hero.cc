#include "Hero.h"

#define STARTINGSTATS 10
#define MAGICPOWER 20

Hero::Hero(string nameHero,int strengthHero,int dexerityHero, int agilityHero):
Living(nameHero)
{
    strength=STARTINGSTATS+strengthHero;
    dexerity=STARTINGSTATS+dexerityHero;
    agility=STARTINGSTATS+agilityHero;
    
    magicPower=MAGICPOWER;
    money=0;
    experience=0;
}

void Hero::levelUp(int strengthHero,int dexerityHero,int agilityHero,int magicPowerHero){
    if (experience<100){
        cout<<"Cannot level up. Experience:"<<experience<<"%\n";
        return;
    }
    Living::levelUp();
    experience=experience-100;
    magicPower+=magicPowerHero;
    strength+=strengthHero;
    dexerity+=dexerityHero;
    agility+=agilityHero;
}

void Hero::attack(Monster* monster){
    srand(time(NULL));
    cout<<"Attacking Hero\n";
    monster->takeDamage(10+strength);
}

void Hero::takeDamage(int damage){
    int prob= (int) rand()%100;
    if (prob<=dexerity){
        cout<<"Doged\n";
        return;
    }
    cout<<"Taking damge: "<<damage<<"\n";
    Living::takeDamage(damage);
}

void Hero::printStats() const {
    cout<<"Magic Power: "<<magicPower<<"\n";
    cout<<"Strength: "<<strength<<"\n";
    cout<<"Dexerity: "<<dexerity<<"\n";
    cout<<"Agility: "<<agility<<"\n";
    cout<<"Experience: "<<experience<<"\n";
    cout<<"Money: "<<money<<"\n";
}

void Hero::printItems() const{
    if (items.size()==0){
        cout<<"No items\n";
        return;
    }
    cout<<"Items:\n";
    for (int i=0 ; i< items.size(); i++)
        // items.at(i)->print();
        cout<<i;
}

void Hero::print() const{
    Living::printCharacter();
    printStats();
    printItems();
}