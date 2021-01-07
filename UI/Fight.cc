#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

#include "UI.h"
#include "Util.h"

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
bool moveHero(vector<Hero*> heros,vector<Monster*> monsters);
bool moveMonster(vector<Hero*> heros,vector<Monster*> monsters);  
void printTheBegining(vector<Hero*>,vector<Monster*>);

bool checkAliveHeros(vector<Hero*>heros);
bool checkAliveMonsters(vector<Monster*>monsters);
void restoreHP(vector<Hero*> heros,vector<Monster*> monsters);
void restoreMP(vector<Hero*> heros);
void herosLose(vector<Hero*> heros,vector<Monster*> monsters);
void herosWin(vector<Hero*> heros,vector<Monster*> monsters);

// Add Armor and Sword change

bool battle(vector<Hero*> heros,Util util){
    srand(time(NULL));
    vector<Monster*> monsters;
    monsters=createMonster(heros,monsters,util);
    printTheBegining(heros,monsters);
    cout<<"\n";
    bool flag=true;
    while(flag){
        if(checkAlive(heros,monsters))
            break;
        restoreHP(heros,monsters);
        if(moveHero(heros,monsters)){
            flag=false;
            break;
        }
        if(checkAlive(heros,monsters))
            break;
        if(moveMonster(heros,monsters))
            break;
    }
    if(flag){
        if(checkAliveHeros(heros))
            herosWin(heros,monsters);
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
    if (heros.size()<3)
        size=rand()%(heros.size()+2)+1;
    else
        size=rand()%(heros.size()+2)+1;
    int previous=-1;
    int previousLevel=heroLevel;
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
            monsters.push_back( util.spawnDragon(levelMonster));
        else if(whichMonster==1)
            monsters.push_back(util.spawnSpirit(levelMonster));
        else
            monsters.push_back(util.spawnExoskeleton(levelMonster));

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
    cout<<"Stats: For the stats of the hero\n";
    cout<<"Monsters: For the info of the monsters\n";
    cout<<"Attack: For the hero to attack\n";
    cout<<"CastSpell: For the hero to cast spell\n";
    cout<<"Use: For the hero to use a item\n";
    cout<<"Quit: For quiting the Game\n";
    cout<<"Help: For the availble comands\n";
}
void printMonsters(vector<Monster*> monsters){
    for (int i=0;i<monsters.size();i++){
        cout<<"\n";
        cout<<i+1<<")";
        monsters.at(i)->print();
        if(SLEEP){
            sleep(40);
        }
        else{
            usleep(1000000);
        }
    }
    cout<<"Write the number of the monster.\n";    
} 
bool moveHero(vector<Hero*> heros,vector<Monster*> monsters){
    for(int i=0;i<heros.size();i++){
        
        if(heros.at(i)->getHP()==0)
            continue;
        bool flag=false;
        if(!checkAliveMonsters(monsters))
            return true;

        if(SLEEP){
            sleep(40);
        }
        else{
            usleep(4000000);
        }

        help(heros.at(i));
        do {
            
            cout<<"Write your action\n";
            string action;
            cin>>action;
            if (cin.bad()) {
                cout<<"Problem With cin\n";
                // return false;
            }
            if(action=="Stats"){
                heros.at(i)->printCharacter();
                heros.at(i)->printStats();
            }
            else if(action=="Monsters"){
                printMonsters(monsters);
            }
            else if(action=="Attack"){
                cout<<"Choose a Monster\n";
                cout<<"0) Cancel action\n";
                printMonsters(monsters);
                int which;
                cin>>which;
                if (cin.bad()) {
                    cout<<"Problem With cin\n";
                    return false;
                }
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
            else if(action=="CastSpell"){
                cout<<"Choose a Monster\n";
                cout<<"0: For changing move\n";
                printMonsters(monsters);
                int which;
                cin>>which;
                if (cin.bad()) {
                    cout<<"Problem With cin\n";
                    return false;
                }
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

                cout<<"\n";
                flag=true;
                if(!heros.at(i)->castSpell(monsters.at(which-1))){
                    flag=false;
                }
            }
            else if (action=="Use"){
                if(!heros.at(i)->useInventory()){
                    flag=false;
                }
            }
            else if (action=="Help"){
                help(heros.at(i));
            }
            else if (action=="Quit"){
                return true;
            }

        } while(!flag);
        cout<<"\n";
    }
    return false;
}

bool moveMonster(vector<Hero*> heros,vector<Monster*> monsters){
    for (int i=0;i<monsters.size();i++){
        if(monsters.at(i)->getHP()==0)
            continue;
        if(SLEEP){
            sleep(40);
        }
        else{
            usleep(4000000);
        }
        cout<<monsters.at(i)->getName()<<" is attacking\n";
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
    cout<<"------------------------------\n";
}

void restoreHP(vector<Hero*> heros,vector<Monster*> monsters){
    for (int i=0;i<heros.size();i++){
        if(heros.at(i)->getHP()!=0){
            int howMuch= heros.at(i)->getHPUsed();
            if(howMuch==0)
                continue;
            if (howMuch<=25)
                howMuch=rand()%(((int)howMuch/4));
            else
                howMuch=rand()%((int)howMuch/2);
            heros.at(i)->restoreHP(howMuch);
        }
    }
    for (int i=0;i<monsters.size();i++){
        if(monsters.at(i)->getHP()!=0){
            int howMuch= monsters.at(i)->getHPUsed();
            if(howMuch==0)
                continue;
            howMuch=rand()%((int)howMuch/4);
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
            howMuch=rand()%(howMuch/4);
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
        // restoreHP(heros,monsters);
    }
}
void herosWin(vector<Hero*> heros,vector<Monster*> monsters){
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
        heros.at(i)->addEXP((levelMonsters/heros.at(i)->getLevel())*(100/max));       
    }
}