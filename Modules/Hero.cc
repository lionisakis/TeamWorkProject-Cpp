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

void Hero::leveUp(int magicPowerHero,int strengthHero,int dexerityHero,int agilityHero){
    Living::leveUp();
    experience=0;
    magicPower+=magicPowerHero;
    strength+=strengthHero;
    dexerity+=dexerityHero;
    agility+=agilityHero;
}
