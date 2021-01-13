#include <stdlib.h>
#include <time.h>   
#include "Living.h"
#include "Hero.h"
#include "Monster.h"
#include "FireSpell.h"
#include "IceSpell.h"
#include "LightingSpell.h"
#include "Spell.h"

// a function to take a random hp 
int countHP(int level,int previous){
    srand(time(NULL));
    int current;
    do{
        current=rand()%(10*level+20)+25;
    }while(previous==current);
    return current;
}

Monster::Monster(string name,string typeMonster,int levelHero,int minDamageMonster,int maxDamageMonster, int armorMonster,int dogeMonster,int previousMonsterHealth):
Living(name,levelHero,countHP(levelHero,previousMonsterHealth)),type(typeMonster),maxDamage(maxDamageMonster+levelHero*5),minDamage(minDamageMonster+levelHero*5),
armor(armorMonster+levelHero*5),doge(dogeMonster+levelHero*5)
{
    for(int i=0;i<3;i++)
        rounds[i]=0;
    decreaseAvoid=0;
    decreaseDamage=0;
    decreanseDefence=0;
    cout<<"A monster has appeard with the following Stats:\n";
    print();
}

void Monster::getDepuff(Spell* spell){
    string type= spell->getType();
    int round= spell->getLevel()/2;
    // take the debuf
    if(type==FIRESPELL){
        FireSpell* fireSpell=(FireSpell*)spell;
        decreanseDefence+=fireSpell->getDecreaseDefence();
        rounds[0]=round;
        cout<<"Defence has fallen\n";
        if(round==0)
            cout<<"Defence Debuf has ended";
    }
    else if(type==FIRESPELL){
        IceSpell* iceSpell=(IceSpell*)spell;
        decreaseDamage+=iceSpell->getDecreaseDamage();
        rounds[1]=round;
        cout<<"Damage has fallen\n";
        if(round==0)
            cout<<"Damage Debuf has ended";
    }
    else{
        LightingSpell* lightingSpell=(LightingSpell*)spell;
        decreaseAvoid+=lightingSpell->getDecreaseAvoid();
        rounds[2]=round;
        cout<<"Doge has decreased\n";
        if(round==0)
            cout<<"Doge Debuf has ended";
    }
    
}

void Monster::attack(Hero* hero){
    srand(time(NULL));
    int damage=rand()%maxDamage+minDamage;
    cout<<"Attacking Hero("<<hero->getName()<<") with damage:"<<damage-decreaseDamage<<"\n";
    hero->takeDamage(damage-decreaseDamage);

    for(int i=0;i<3;i++){
        // reduce the debuf
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
    int totalDamage=damage-armor+decreanseDefence;
    if (totalDamage<0)
        totalDamage=0;
    cout<<"Taking damge: "<<totalDamage<<"\n";
    Living::takeDamage(totalDamage);
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
    for(int i=0;i<3;i++){
        if(rounds[i]>0){
            if(i==0){
                cout<<"There is a Defence Debuf with power:"<<decreanseDefence;
            }
            else if(i==1){
                cout<<"There is a Defence Debuf with power:"<<decreaseDamage;
            }
            else if (i==2){
                cout<<"There is a Defence Debuf with power:"<<decreaseAvoid;
            }
            cout<<" and is for "<<rounds[i]<<" round(s)\n";
        }
    }
}

void Monster::print() const{
    Living::printCharacter();
    cout<<"Type: "<<type<<"\n";
    printStats();
}