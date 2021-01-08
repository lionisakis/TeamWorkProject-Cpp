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

#ifdef _WIN32
    #include <Windows.h>
    #define SLEEP true
#else
    #include <unistd.h>
    #define SLEEP false
#endif

vector<Monster*> createMonster(vector<Hero*> heros,vector<Monster*> monsters,Util util);
bool checkAlive(vector<Hero*> heros,vector<Monster*> monsters);
int moveHero(vector<Hero*> heros,vector<Monster*> monsters);
bool moveMonster(vector<Hero*> heros,vector<Monster*> monsters);  
void printTheBegining(vector<Hero*>,vector<Monster*>);

bool checkAliveHeros(vector<Hero*>heros);
bool checkAliveMonsters(vector<Monster*>monsters);
void restoreHP(vector<Hero*> heros,vector<Monster*> monsters);
void restoreMP(vector<Hero*> heros);
void herosLose(vector<Hero*> heros,vector<Monster*> monsters);
void herosWin(vector<Hero*> heros,vector<Monster*> monsters,int rounds);

bool battle(vector<Hero*> heros,Util util){
    srand(time(NULL));
    vector<Monster*> monsters;
    monsters=createMonster(heros,monsters,util);
    bool flag=true;
    int i=1;
    while(flag){
        printTheBegining(heros,monsters);
        if(checkAlive(heros,monsters))
            break;
        restoreHP(heros,monsters);
        restoreMP(heros);
        int results=moveHero(heros,monsters);
        if(results){
            if(results==2)
                flag=false;
            break;
        }
        if(checkAlive(heros,monsters))
            break;
        if(moveMonster(heros,monsters))
            break;
        i++;
    }
    if(flag){
        if(checkAliveHeros(heros))
            herosWin(heros,monsters,i);
        else 
            herosLose(heros,monsters);
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

vector<Monster*> createMonster(vector<Hero*> heros,vector<Monster*> monsters,Util util){
    
    int heroLevel=0;
    for (int i=0;i<heros.size();i++)
        heroLevel+=heros.at(i)->getLevel();
    heroLevel/=heros.size();
    int size;
    size=rand()%(heros.size()+1)+1;
    int previous=-1;
    int previousLevel=heroLevel;
    int previousHealth=0;
    for (int i=0;i<size;i++){
        int whichMonster;
        do{
            whichMonster=rand()%3;
        }while(previous==whichMonster);
        previous=whichMonster;
        int levelMonster;
        do{
            levelMonster=rand()%(heroLevel+2)+heroLevel-1;
        } while(levelMonster==previousLevel);
        if(levelMonster==0)
            levelMonster=1;
        previousLevel=levelMonster;
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
bool checkAliveHeros(vector<Hero*>heros){
    int i;
    for (i=0;i<heros.size();i++){
        if (heros.at(i)->getHP()!=0)
            break;
    }
    return !(heros.size()==i);
}
bool checkAliveMonsters(vector<Monster*>monsters){
    int i;
    for (i=0;i<monsters.size();i++){
        if (monsters.at(i)->getHP()!=0)
            break;
    }
    return !(monsters.size()==i);
}
bool checkAlive(vector<Hero*> heros,vector<Monster*> monsters){
    if(!checkAliveHeros(heros));
        return false;
    return checkAliveMonsters(monsters);
}
void help(Hero* hero){
    cout<< hero->getName()<<" is attacking. ";
    cout<< "HP:"<<hero->getHP()<<"\t";
    cout<< "Magic Power: "<<hero->getMagicPower()<<"\t";
    cout<< "Basic Damage: "<<hero->getDamage()<<"\n";
    cout<<"Choose one of the following move:\n";
    cout<<"1) To see the Stats of the current hero.\n";
    cout<<"2) To see the Info of the monsters.\n";
    cout<<"3) To Attack.\n";
    cout<<"4) To Cast Spell.\n";
    cout<<"5) To Use an Item.\n";
    cout<<"6) To See the Commands.\n";
    cout<<"0) To Quit.\n";
}
void printMonsters(vector<Monster*> monsters,bool flag=true){
    for (int i=0;i<monsters.size();i++){
        cout<<"\n";
        cout<<i+1<<")";
        monsters.at(i)->print();
        if(SLEEP){
            sleep(40);
        }
        else{
            usleep(500000);
        }
    }
    if(flag)
        cout<<"Write the number of the monster.\n";    
} 
int moveHero(vector<Hero*> heros,vector<Monster*> monsters){
    for(int i=0;i<heros.size();i++){
        
        if(heros.at(i)->getHP()==0)
            continue;
        bool flag=false;
        if(!checkAliveMonsters(monsters))
            return 3;

        if(SLEEP){
            sleep(40);
        }
        else{
            usleep(500000);
        }
        bool flag2=false;
        cout<<"Write your action\n";

        help(heros.at(i));
        do {
            if(flag2){
                cout<<"Write your action\n";
                cout<<"6) For seeing the COMANDS\n";
            }
            else
                flag2=true;
            int action=readNumber("",0,6);
            if (action==-1)
                return 1;
            if(action==1){
                heros.at(i)->printCharacter();
                heros.at(i)->printStats();
            }
            else if(action==2){
                printMonsters(monsters,false);
            }
            else if(action==3){
                int which;
                bool falg;
                cout<<"Choose a Monster\n";
                cout<<"0) For changing move\n";
                printMonsters(monsters);
                which=readNumber("",0,6);
                if(which==0)
                    continue;
                if(which>monsters.size()){
                    cout<<"There is not a monster with that number\n";
                    continue;
                }
                if(monsters.at(which-1)->getHP()<=0){
                    cout<<"That monster is dead. Chose something else\n";
                    continue;
                }
                flag=true;
                cout<<"\n";
                heros.at(i)->attack(monsters.at(which-1));
            }
            else if(action==4){
                int which;
                cout<<"Choose a Monster.\n";
                cout<<"0) To Change move.\n";
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
                if(!heros.at(i)->castSpell(monsters.at(which-1))){
                    flag=false;
                }
            }
            else if (action==5){
                flag=true;
                if(!heros.at(i)->useInventory()){
                    flag=false;
                }
            }
            else if (action==0){
                return 2;
            }
            else if (action==6){
                help(heros.at(i));
            }
            

        } while(!flag);
        cout<<"\n";
    }
    return 0;
}

bool moveMonster(vector<Hero*> heros,vector<Monster*> monsters){
    for (int i=0;i<monsters.size();i++){
        if(monsters.at(i)->getHP()==0)
            continue;
        if(SLEEP){
            sleep(40);
        }
        else{
            usleep(500000);
        }
        cout<<monsters.at(i)->getName()<<" "<<monsters.at(i)->getType()<<" is attacking.\n";
        if(!checkAliveHeros(heros))
            return true;
        int chooseHero;
        do{
            chooseHero=rand()%heros.size();
        }while(heros.at(chooseHero)->getHP()==0);
        monsters.at(i)->attack(heros.at(chooseHero));
        cout<<"\n";
    }
    return false;
}

void printTheBegining(vector<Hero*> heros,vector<Monster*> monsters){
    int indexh=0;
    int indexm=0;
    int middle=0;
    cout<<"------------------------------\n";
    if(monsters.size()>heros.size())
        middle=monsters.size()%2;
    else
        middle=heros.size()%2;
    
    while(true){
        if(indexh<heros.size()){
            if(indexh==middle)
                cout<<heros.at(indexh)->getName()<<" Level: "<<heros.at(indexh)->getLevel()<<" HP: "<<heros.at(indexh)->getHP()<<"\tvs\t\t";
            else
                cout<<heros.at(indexh)->getName()<<" Level: "<<heros.at(indexh)->getLevel()<<" HP: "<<heros.at(indexh)->getHP()<<"\t\t\t";
            indexh++;
        }
        else{
            if(indexm==middle)
                cout<<"\tvs\t\t\t\t\t";
            else
                cout<<"\t\t\t\t\t\t";
        }
        if(indexm<monsters.size()){
            cout<<monsters.at(indexm)->getName()<<" "<<monsters.at(indexm)->getType()<<" Level: "<<monsters.at(indexm)->getLevel()<<" HP: "<<monsters.at(indexm)->getHP();
            indexm++;
        }
        if(indexh==heros.size()&&indexm==monsters.size())
            break;
        cout<<"\n";
    }
    cout<<"\n";
    cout<<"------------------------------\n\n";
}

void restoreHP(vector<Hero*> heros,vector<Monster*> monsters){
    for (int i=0;i<heros.size();i++){
        if(heros.at(i)->getHP()!=0){
            int howMuch= heros.at(i)->getHPUsed();
            if(howMuch==0){
                heros.at(i)->restoreHP(0);
                continue;
            }
            if (howMuch<25)
                howMuch=rand()%((int)howMuch/2);
            else if (howMuch<50)
                howMuch=rand()%((int)howMuch/4);
            else
                howMuch=rand()%((int)howMuch/8);
            heros.at(i)->restoreHP(howMuch);
        }
    }
    for (int i=0;i<monsters.size();i++){
        if(monsters.at(i)->getHP()!=0){
            int howMuch= monsters.at(i)->getHPUsed();
            if(howMuch==0){
                monsters.at(i)->restoreHP(0);
                continue;
            }
            if (howMuch<25)
                howMuch=rand()%(howMuch/2);
            else if (howMuch<50)
                howMuch=rand()%(howMuch/4);
            else
                howMuch=rand()%(howMuch/8);
            monsters.at(i)->restoreHP(howMuch);
        }
    }
}
void restoreMP(vector<Hero*> heros){
    for (int i=0;i<heros.size();i++){
        if(heros.at(i)->getHP()!=0){
            int howMuch= heros.at(i)->getMPused();
            if(howMuch==0)
                continue;
            howMuch=rand()%(howMuch/8);
            heros.at(i)->restoreMP(howMuch);
        }
    }
}

void herosLose(vector<Hero*> heros,vector<Monster*> monsters){
    cout<<"HEROS HAVE LOST THE FIGHT!\n";
    for(int i=0;i<heros.size();i++){
        int money=heros.at(i)->getMoney();
        heros.at(i)->addMoney(-money/2);
        // maybe?
        for(int i=0;i<heros.size();i++)
            heros.at(i)->restoreHP(heros.at(i)->getHPUsed()/2);
    }
}
void herosWin(vector<Hero*> heros,vector<Monster*> monsters,int rounds){
    cout<<"HEROS HAVE WON THE FIGHT!\n";
    
    double levelMonsters=0;
    int max=0;
    for(int j=0;j<monsters.size();j++){
        levelMonsters+=monsters.at(j)->getLevel();        
        if(max<monsters.at(j)->getLevel())
            max=monsters.at(j)->getLevel();
    }
    int exp=levelMonsters;
    for(int i=0;i<heros.size();i++){
        int totalExp=(levelMonsters/heros.at(i)->getLevel())*(100/max)*(rounds/4);
        cout<<"Hero "<<heros.at(i)->getName()<<" get "<<totalExp<<" EXP.\n"; 
        heros.at(i)->addEXP(totalExp);       
    }
}