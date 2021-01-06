#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

#include "UI.h"

#include "Monster.h"
#include "Dragon.h"
#include "Spirit.h"
#include "Exoskeleton.h"

#include "Hero.h"

vector<Monster*> createMonster(vector<Hero*> heros);
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

int battle(vector<Hero*> heros){
    srand(time(NULL));
    vector<Monster*> monsters=createMonster(heros);
    printTheBegining(heros,monsters);
    cout<<"\n";
    while(true){
        if(checkAlive(heros,monsters))
            break;
        restoreHP(heros,monsters);
        if(moveHero(heros,monsters))
            return -1;
        if(checkAlive(heros,monsters))
            break;
        if(moveMonster(heros,monsters))
            break;
    }
    if(!checkAliveHeros(heros))
        herosWin(heros,monsters);
    else 
        herosLose(heros,monsters);

    // Wrong with delete
    for(int i=0;i<monsters.size();i++){
        Monster* temp=monsters.at(i);
        monsters.at(i)=NULL;
        delete temp;
    }
}

vector<Monster*> createMonster(vector<Hero*> heros){
    int heroLevel=0;
    for (int i=0;i<heros.size();i++)
        heroLevel+=heros.at(i)->getLevel();
    heroLevel/=heros.size();
    vector<Monster*> monsters;
    int size;
    if (heros.size()<3)
        size=rand()%(heros.size()*3)+1;
    else
        size=rand()%(heros.size()*2)+1;
    for (int i=0;i<size;i++){
        int whichMonster=rand()%3;
        int levelMonster=rand()%(heroLevel+2)+heroLevel-1;
        if(levelMonster==0)
            levelMonster=1;
        if(whichMonster==0)
            monsters.push_back( new Dragon("Dragon",levelMonster));
        else if(whichMonster==1)
            monsters.push_back(new Spirit("Spirit",levelMonster));
        else
            monsters.push_back(new Exoskeleton("Exoskeleton",levelMonster));

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
    cout<< hero->getName()<<" is attacking.\t";
    cout<< "HP:"<<hero->getHP()<<"\t";
    cout<< "Magic Power: "<<hero->getMagicPower()<<"\n";
    cout<<"\nChoose one of the following move:\n";
    cout<<"stats: For the stats of the hero\n";
    cout<<"monsters: For the info of the monsters\n";
    cout<<"attack: For the hero to attack\n";
    cout<<"castSpell: For the hero to cast spell\n";
    cout<<"use: For the hero to use a potion\n";
    cout<<"quit: For quiting the Game\n";
    cout<<"help: For the availble comands\n";
}
void printMonsters(vector<Monster*> monsters){
    for (int i=0;i<monsters.size();i++){
        cout<<"\n";
        cout<<i+1<<")";
        monsters.at(i)->print();
    }
    cout<<"\n";    
} 
bool moveHero(vector<Hero*> heros,vector<Monster*> monsters){
    for(int i=0;i<heros.size();i++){
        if(heros.at(i)->getHP()==0)
            continue;
        bool flag=false;
        if(!checkAliveMonsters(monsters))
            return true;
        help(heros.at(i));
        do {
            
            cout<<"Write your action\n";
            string action;
            cin>>action;
            if (cin.bad()) {
                cout<<"Problem With cin\n";
                return false;
            }
            if(action=="stats"){
                heros.at(i)->printCharacter();
                heros.at(i)->printStats();
            }
            else if(action=="monsters"){
                printMonsters(monsters);
            }
            else if(action=="attack"){
                cout<<"Choose a Monster\n";
                cout<<"0) cansel action\n";
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

                heros.at(i)->attack(monsters.at(which-1));
            }
            else if(action=="castSpell"){
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


                flag=true;
                if(!heros.at(i)->castSpell(monsters.at(which-1))){
                    flag=false;
                }
            }
            else if (action=="use"){
                if(!heros.at(i)->useInBattle()){
                    flag=false;
                }
            }
            else if (action=="help"){
                help(heros.at(i));
            }
            else if (action=="quit"){
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
    if(monsters.size()>heros.size())
        middle=monsters.size()%2;
    else
        middle=heros.size()%2;
    while(true){
        if(indexh<heros.size()){
            if(indexh==middle)
                cout<<heros.at(indexh)->getName()<<"\t\t\t\tvs\t";
            else
                cout<<heros.at(indexh)->getName()<<"\t\t\t\t\t";
            indexh++;
        }
        else{
            if(indexm==middle)
                cout<<"\t\t\t\tvs\t";
            else
                cout<<"\t\t\t\t\t";
        }
        if(indexm<monsters.size()){
            cout<<monsters.at(indexm)->getName()<<" "<<monsters.at(indexm)->getType()<<"\n";
            indexm++;
        }
        if(indexh==heros.size()&&indexm==monsters.size())
            break;
    }
}

void restoreHP(vector<Hero*> heros,vector<Monster*> monsters){
    cout<<"RESTORE\n";
    for (int i=0;i<heros.size();i++){
        if(heros.at(i)->getHP()!=0){
            int howMuch= heros.at(i)->getHPUsed();
            if(howMuch==0)
                continue;
            if (howMuch<=25)
                howMuch=rand()%(((int)howMuch/2));
            else if(howMuch<=75)
                howMuch=rand()%((int)howMuch);
            else 
                howMuch=rand()%((int)howMuch*2);
            heros.at(i)->restoreHP(howMuch);
        }
    }
    for (int i=0;i<monsters.size();i++){
        if(monsters.at(i)->getHP()!=0){
            int howMuch= monsters.at(i)->getHPUsed();
            if(howMuch==0)
                continue;
            howMuch=rand()%((int)howMuch/2);
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
            howMuch=rand()%(howMuch/2);
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