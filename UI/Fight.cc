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
void moveMonster(vector<Hero*> heros,vector<Monster*> monsters);  
void printTheBegining(vector<Hero*>,vector<Monster*>);

int battle(vector<Hero*> heros){
    srand(time(NULL));
    vector<Monster*> monsters=createMonster(heros);
    printTheBegining(heros,monsters);
    while(true){
        if(checkAlive(heros,monsters))
            break;
        if(moveHero(heros,monsters))
            return -1;
        moveMonster(heros,monsters);
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
        size=rand()%(heros.size()*3);
    else
        size=rand()%(heros.size()*2);
    for (int i=0;i<size;i++){
        int whichMonster=rand()%3;
        int levelMonster=rand()%(heroLevel+4)+4;
        if(whichMonster==0)
            monsters.push_back( new Dragon("Dragon",levelMonster));
        else if(whichMonster==1)
            monsters.push_back(new Spirit("Spirit",levelMonster));
        else
            monsters.push_back(new Exoskeleton("Exoskeleton",levelMonster));

    }
    return monsters;
}

bool checkAlive(vector<Hero*> heros,vector<Monster*> monsters){
    int i;
    for (i=0;i<heros.size();i++){
        if (heros.at(i)->getHP()!=0)
            break;
    }
    if (heros.size()==i)
        return true;

    for (i=0;i<monsters.size();i++){
        if (monsters.at(i)->getHP()!=0)
            break;
    }
    if (monsters.size()==i)
        return true;
    return false;
}
void help(Hero* hero){
    cout<< hero->getName()<<"is attacking. Choose one of the following move:\n";
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
        cout<<i+1<<")";
        monsters.at(i)->print();
    }
} 
bool moveHero(vector<Hero*> heros,vector<Monster*> monsters){
    for(int i=0;i<heros.size();i++){
        if(heros.at(i)->getHP()==0)
            continue;
        help(heros.at(i));
        bool flag=false;
        do {
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

    }
    return false;
}

void moveMonster(vector<Hero*> heros,vector<Monster*> monsters){
    for (int i=0;i<monsters.size();i++){
        if(monsters.at(i)->getHP()==0)
            continue;
        cout<<monsters.at(i)->getName()<<" is attacking\n";
        if(!checkAlive)
            break;
        int chooseHero;
        do{
            chooseHero=rand()%heros.size();
        }while(heros.at(chooseHero)->getHP()==0);
        monsters.at(i)->attack(heros.at(chooseHero));
    }
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