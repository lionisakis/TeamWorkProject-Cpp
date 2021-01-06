#include <stdlib.h>
#include <time.h>   
#include "Living.h"
#include "Hero.h"
#include "Monster.h"
#include "FireSpell.h"
#include "IceSpell.h"
#include "LightingSpell.h"
#include "Spell.h"


int countHP(int level){
    srand(time(NULL));
    return rand()%(10*level+20)+25;
}

Monster::Monster(string name,string typeMonster,int levelHero,int minDamageMonster,int maxDamageMonster, int armorMonster,int dogeMonster):
Living(name,levelHero,countHP(levelHero)),type(typeMonster),maxDamage(maxDamageMonster+levelHero*5),minDamage(minDamageMonster+levelHero*5),
armor(armorMonster+levelHero*5),doge(dogeMonster+levelHero*5)
{
    for(int i=0;i<3;i++)
        rounds[i]=0;
    decreaseAvoid=0;
    decreaseDamage=0;
    decreanseDefence=0;
}

void Monster::getDepuff(Spell* spell){
    int type= spell->getType();
    int round= spell->getLevel()/2;
    if(type==FIRESPELL){
        FireSpell* fireSpell=(FireSpell*)spell;
        decreanseDefence+=fireSpell->getDecreaseDefence();
        rounds[0]=round;
        cout<<"Defence has fallen\n";
    }
    else if(type==FIRESPELL){
        IceSpell* iceSpell=(IceSpell*)spell;
        decreaseDamage+=iceSpell->getDecreaseDamage();
        rounds[1]=round;
        cout<<"Damage has fallen\n";
    }
    else{
        LightingSpell* lightingSpell=(LightingSpell*)spell;
        decreaseAvoid+=lightingSpell->getDecreaseAvoid();
        rounds[2]=round;
        cout<<"Doge has decreased\n";
    }

}

void Monster::attack(Hero* hero){
    srand(time(NULL));
    int damage=rand()%maxDamage+minDamage;
    cout<<"Attacking Hero("<<hero->getName()<<") with damage:"<<damage-decreaseDamage<<"\n";
    hero->takeDamage(damage-decreaseDamage);

    for(int i=0;i<3;i++){
        if(rounds[i]>0){
            
            rounds[i]--;
            if(i==0){
                decreanseDefence=0;
                cout<<"Defence Debuf has ended";
            }
            else if(i==1){
                decreaseDamage=0;
                cout<<"Damage Debuf has ended";
            }
            else if (i==2){
                decreaseAvoid=0;
                cout<<"Doge Debuf has ended";
            }

        }
    }
}

bool Monster::takeDamage(int damage){
    srand(time(NULL));
    int prob= (int) rand()%100;
    if (prob<=doge-decreaseAvoid){
        cout<<"Doged the attacked\n";
        return false;
    }
    cout<<"Taking damge: "<<damage-armor+decreanseDefence<<"\n";
    Living::takeDamage(damage-armor+decreanseDefence);
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