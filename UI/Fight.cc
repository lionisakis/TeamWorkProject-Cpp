#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <limits>
#include <string>

using namespace std;

#include "UI.h"
#include "Util.h"
#include "stdlib.h"

#include "Define.h"

#include "Monster.h"
#include "Hero.h"

vector<Monster*> createMonster(vector<Hero*> heroes,vector<Monster*> monsters,Util util);
bool checkAlive(vector<Hero*> heroes,vector<Monster*> monsters);
int moveHero(vector<Hero*> heroes,vector<Monster*> monsters);
bool moveMonster(vector<Hero*> heroes,vector<Monster*> monsters);  
void printTheBegining(vector<Hero*>,vector<Monster*>);

bool checkAliveheroes(vector<Hero*>heroes);
bool checkAliveMonsters(vector<Monster*>monsters);
void restoreHP(vector<Hero*> heroes,vector<Monster*> monsters);
void restoreMP(vector<Hero*> heroes);
void heroesLose(vector<Hero*> heroes,vector<Monster*> monsters);
void heroesWin(vector<Hero*> heroes,vector<Monster*> monsters,int rounds);

// a function that combines all the other functions to have final result.
bool battle(vector<Hero*> heroes,Util util){
    srand(time(NULL));
    vector<Monster*> monsters;
    monsters=createMonster(heroes,monsters,util);
    bool flag=true;
    int i=1;
    while(flag){
        printTheBegining(heroes,monsters);
        if(checkAlive(heroes,monsters))
            break;
        restoreHP(heroes,monsters);
        restoreMP(heroes);
        int results=moveHero(heroes,monsters);
        if(results){
            // this if is to see if the user wants to quit the game
            if(results==2)
                flag=false;
            break;
        }
        if(checkAlive(heroes,monsters))
            break;
        if(moveMonster(heroes,monsters))
            break;
        i++;
    }
    if(flag){
        if(checkAliveheroes(heroes))
            heroesWin(heroes,monsters,i);
        else 
            heroesLose(heroes,monsters);
    }
    int size=monsters.size();
    while(size>0){
        Monster* temp=monsters.back();
        monsters.pop_back();
        delete temp;
        size=monsters.size();
    }
    
    return flag;
}

vector<Monster*> createMonster(vector<Hero*> heroes,vector<Monster*> monsters,Util util){
    
    int heroLevel=0;
    for (int i=0;i<heroes.size();i++)
        heroLevel+=heroes.at(i)->getLevel();
    heroLevel/=heroes.size();
    int size;
    size=rand()%(heroes.size()+1)+1;
    int previous=-1;
    int previousLevel=heroLevel;
    int previousHealth=0;
    for (int i=0;i<size;i++){
        int whichMonster;
        // see the type of the monster
        do{
            whichMonster=rand()%3;
        }while(previous==whichMonster);
        previous=whichMonster;
        int levelMonster;
        // see the level of the monster
        do{
            levelMonster=rand()%(heroLevel+2)+heroLevel-1;
        } while(levelMonster==previousLevel);
        if(levelMonster==0)
            levelMonster=1;
        previousLevel=levelMonster;
        // create a monster
        if(whichMonster==0)
            monsters.push_back( util.spawnDragon(levelMonster,previousHealth));
        else if(whichMonster==1)
            monsters.push_back(util.spawnSpirit(levelMonster,previousHealth));
        else
            monsters.push_back(util.spawnExoskeleton(levelMonster,previousHealth));
        previousHealth=monsters.at(i)->getHP();
    }
    return monsters;
}

// check if all the hereos are alive
bool checkAliveheroes(vector<Hero*>heroes){
    int i;
    for (i=0;i<heroes.size();i++){
        if (heroes.at(i)->getHP()!=0)
            break;
    }
    return !(heroes.size()==i);
}

// check if all the Monster are alive
bool checkAliveMonsters(vector<Monster*>monsters){
    int i;
    for (i=0;i<monsters.size();i++){
        if (monsters.at(i)->getHP()!=0)
            break;
    }
    return !(monsters.size()==i);
}

// check if all the hereos or the monsters are alive
bool checkAlive(vector<Hero*> heroes,vector<Monster*> monsters){
    if(!checkAliveheroes(heroes));
        return false;
    return checkAliveMonsters(monsters);
}

// help 
void help(Hero* hero){
    cout<< hero->getName()<<" is attacking. ";
    cout<< "HP:"<<hero->getHP()<<"\t";
    cout<< "Magic Power: "<<hero->getMagicPower()<<"\t";
    cout<< "Basic Damage: "<<hero->getDamage()<<"\n";
    cout<<"Choose one of the following moves:\n";
    cout<<"0) To Quit.\n";
    cout<<"1) To see the Stats of the current hero.\n";
    cout<<"2) To see the Info of the monsters.\n";
    cout<<"3) To Attack.\n";
    cout<<"4) To Cast Spell.\n";
    cout<<"5) To Use an Item.\n";
    cout<<"6) To See the Commands.\n";
}

// print all the Monsters 
void printMonsters(vector<Monster*> monsters,bool flag=true){
    for (int i=0;i<monsters.size();i++){
        cout<<"\n";
        cout<<i+1<<")";
        monsters.at(i)->print();
    }
    if(flag)
        cout<<"Write the number of the monster.\n";    
} 

// move a heroes
int moveHero(vector<Hero*> heroes,vector<Monster*> monsters){
    for(int i=0;i<heroes.size();i++){
        
        if(heroes.at(i)->getHP()==0)
            continue;
        bool flag=false;
        if(!checkAliveMonsters(monsters))
            return 3;

        bool flag2=false;
        cout<<"Write your action.\n";

        help(heroes.at(i));
        do {
            if(flag2){
                cout<<"Write your action.\n";
                cout<<"Press 6 for seeing the commands.\n";
            }
            else
                flag2=true;
            // take the number action
            int action=readNumber("",0,6);
            if (action==-1)
                return 1;
            if(action==1){
                heroes.at(i)->printCharacter();
                heroes.at(i)->printStats();
            }
            else if(action==2){
                printMonsters(monsters,false);
            }
            else if(action==3){
                // choose a Monster 
                int which;
                bool falg;
                cout<<"Choose a Monster.\n";
                cout<<"Press 0 to change your move.\n";
                printMonsters(monsters);
                which=readNumber("",0,6);
                if(which==0)
                    continue;
                if(which>monsters.size()){
                    cout<<"There is not a monster with that number.\n";
                    continue;
                }
                if(monsters.at(which-1)->getHP()<=0){
                    cout<<"That monster is dead. Chose something else.\n";
                    continue;
                }
                flag=true;
                cout<<"\n";
                // attack that Monster 
                heroes.at(i)->attack(monsters.at(which-1));
            }
            else if(action==4){
                // choose a Monster 
                int which;
                cout<<"Choose a Monster.\n";
                cout<<"Press 0 to change your move.\n";
                printMonsters(monsters);
                which=readNumber("",0,6);
                if(which==0)
                    continue;
                if(which>monsters.size()){
                    cout<<"There is not a monster with that number.\n";
                    continue;
                }
                if(monsters.at(which-1)->getHP()<=0){
                    cout<<"That monster is dead. Chose something else.\n";
                    continue;
                }

                cout<<"\n";
                flag=true;
                // cast a spell to that Monster 
                if(!heroes.at(i)->castSpell(monsters.at(which-1))){
                    // the user did not cast a spell
                    flag=false;
                }
            }
            else if (action==5){
                flag=true;
                // use an Item from the Inventory
                if(!heroes.at(i)->useInventory()){
                    // the user did not cast a spell
                    flag=false;
                }
            }
            else if (action==0){
                // quit the game
                return 2;
            }
            else if (action==6){
                help(heroes.at(i));
            }
            

        } while(!flag);
        cout<<"\n";
    }
    return 0;
}

bool moveMonster(vector<Hero*> heroes,vector<Monster*> monsters){
    int previousHero=-1;
    for (int i=0;i<monsters.size();i++){
        if(monsters.at(i)->getHP()==0)
            continue;
        cout<<monsters.at(i)->getName()<<" "<<monsters.at(i)->getType()<<" is attacking.\n";
        // check if there is a hero alive
        if(!checkAliveheroes(heroes))
            return true;
        int chooseHero;
        // choose a random hero
        do{
            chooseHero=rand()%heroes.size();
        }while(heroes.at(chooseHero)->getHP()==0||previousHero==chooseHero);
        previousHero=chooseHero;
        // see how many heroes are alive
        int count=0;
        for(int i=0;i<heroes.size();i++){
            if(heroes.at(i)->getHP()!=0)
                count++;
        }
        // if there are only one then you can choose the same hero again
        if(count==1)
            previousHero=-1;

        monsters.at(i)->attack(heroes.at(chooseHero));
        cout<<"\n";
    }
    return false;
}

void printTheBegining(vector<Hero*> heroes,vector<Monster*> monsters){
    int indexh=0;
    int indexm=0;
    int middle=0;
    cout<<"------------------------------\n";
    if(monsters.size()>heroes.size())
        middle=monsters.size()%2;
    else
        middle=heroes.size()%2;
    
    while(true){
        // print the heroes at the left
        if(indexh<heroes.size()){
            if(indexh==middle)
                cout<<heroes.at(indexh)->getName()<<" Level: "<<heroes.at(indexh)->getLevel()<<" HP: "<<heroes.at(indexh)->getHP()<<"\tvs\t\t";
            else
                cout<<heroes.at(indexh)->getName()<<" Level: "<<heroes.at(indexh)->getLevel()<<" HP: "<<heroes.at(indexh)->getHP()<<"\t\t\t";
            indexh++;
        }
        else{
            // there are no more heroes
            if(indexm==middle)
                cout<<"\tvs\t\t\t\t\t";
            else
                cout<<"\t\t\t\t\t\t";
        }
        // print the monsters at the right
        if(indexm<monsters.size()){
            cout<<monsters.at(indexm)->getName()<<" "<<monsters.at(indexm)->getType()<<" Level: "<<monsters.at(indexm)->getLevel()<<" HP: "<<monsters.at(indexm)->getHP();
            indexm++;
        }
        if(indexh==heroes.size()&&indexm==monsters.size())
            break;
        cout<<"\n";
    }
    cout<<"\n";
    cout<<"------------------------------\n\n";
}

void restoreHP(vector<Hero*> heroes,vector<Monster*> monsters){
    for (int i=0;i<heroes.size();i++){
        if(heroes.at(i)->getHP()!=0){
            // take the damage that it has taken
            int howMuch= heroes.at(i)->getHPUsed();
            if(howMuch==0){
                heroes.at(i)->restoreHP(0);
                continue;
            }
            // balance the restore hp
            if (howMuch<25)
                howMuch=rand()%((int)howMuch/2);
            else if (howMuch<50)
                howMuch=rand()%((int)howMuch/4);
            else
                howMuch=rand()%((int)howMuch/8);
            // restore that hp
            heroes.at(i)->restoreHP(howMuch);
        }
    }
    for (int i=0;i<monsters.size();i++){
        if(monsters.at(i)->getHP()!=0){
            // take the damage that it has taken
            int howMuch= monsters.at(i)->getHPUsed();
            if(howMuch==0){
                monsters.at(i)->restoreHP(0);
                continue;
            }
            // balance the restore hp
            if (howMuch<25)
                howMuch=rand()%(howMuch/2);
            else if (howMuch<50)
                howMuch=rand()%(howMuch/4);
            else
                howMuch=rand()%(howMuch/8);
            // restore that hp
            monsters.at(i)->restoreHP(howMuch);
        }
    }
}
void restoreMP(vector<Hero*> heroes){
    for (int i=0;i<heroes.size();i++){
        if(heroes.at(i)->getHP()!=0){
            // take the damage that it has taken
            int howMuch= heroes.at(i)->getMPused();
            if(howMuch==0)
                continue;
            // balance the restore hp
            if(howMuch/8==0)
                howMuch=rand()%(howMuch%8);
            else
                howMuch=rand()%(howMuch/8);
            // restore that hp
            heroes.at(i)->restoreMP(howMuch);
        }
    }
}

void heroesLose(vector<Hero*> heroes,vector<Monster*> monsters){
    cout<<"heroes HAVE LOST THE FIGHT!\n";
    for(int i=0;i<heroes.size();i++){
        int money=heroes.at(i)->getMoney();
        money=-money/2;
        // lose the money
        cout<<"Hero "<<heroes.at(i)->getName()<<" loses "<<money<<" MONEY.\n"; 
        heroes.at(i)->addMoney(-money/2);
    }
}
void heroesWin(vector<Hero*> heroes,vector<Monster*> monsters,int rounds){
    cout<<"heroes HAVE WON THE FIGHT!\n";
    
    double levelMonsters=0;
    int max=0;
    // find the total levels of the monsters
    for(int j=0;j<monsters.size();j++){
        levelMonsters+=monsters.at(j)->getLevel();        
        if(max<monsters.at(j)->getLevel())
            max=monsters.at(j)->getLevel();
    }
    int exp=levelMonsters;
    for(int i=0;i<heroes.size();i++){
        cout<<max<<"\n\n";
        int totalExp=(levelMonsters/heroes.at(i)->getLevel())*(100/max)*(rounds);
        if(totalExp/4!=0)
            totalExp/=4;
        cout<<"Hero "<<heroes.at(i)->getName()<<" get "<<totalExp<<" EXP.\n"; 
        // take the exp
        heroes.at(i)->addEXP(totalExp);
        // take the money
        int money= rand()%((int)levelMonsters*5)+levelMonsters;
        cout<<"Hero "<<heroes.at(i)->getName()<<" get "<<money<<" MONEY.\n"; 
        heroes.at(i)->addMoney(money);      
    }
}