#include "UI.h"
#include "Util.h"
#include "Paladin.h"
#include "Warrior.h"
#include "Hero.h"
#include "Sorcerer.h"
#include <vector>

#include <iostream>
using namespace std;
vector<Hero*> basicCombo(int howMany);
vector<Hero*> yourChoise(int howMany);
vector<Hero*> spawnHeros(){
    if(false){
        int howMany=0;
        do{
            cout<<"Type a number of how many heros do you want form 1-3\n";
            cin>>howMany;
            if(!(howMany>0&&howMany<4))
                cout<<"Not acceptable ansewer!\n";
        }while(!(howMany>0&&howMany<4));
        int what;
        do{
            cout<<"Do you want the basic combo?\n No:0, Yes:1\n";
            cout<<"Basic Combo:\nIf Party is 1 then Hero is Pladin\n";
            cout<<"If Party is 2 then Hero is Pladin and Sorcerer\n";
            cout<<"If Party is 3 then Hero is Pladin and Sorcerer and Warior\n";
            cin>>what;
            if(!(what>-1&&what<2))
                cout<<"Not acceptable ansewer!\n";
        }while(!(what>-1&&what<2));
        if(what==1){
            return basicCombo(howMany);
        }
        else{
            return yourChoise(howMany);
        }
    }
    return basicCombo(3);
}

vector<Hero*> basicCombo(int howMany){
    vector<Hero*> heros;
    if(howMany==1)
        heros.push_back(new Paladin("Paladin"));
    else if(howMany==2){
        heros.push_back(new Paladin("Paladin"));
        heros.push_back(new Sorcerer("Sorcerer"));
    }
    else {
        heros.push_back(new Paladin("Paladin"));
        heros.push_back(new Sorcerer("Sorcerer"));
        heros.push_back(new Warrior("Warrior"));
    }
    return heros;        
}
vector<Hero*> yourChoise(int howMany){
    vector<Hero*> heros;
    for(int i=0;i<howMany;i++){
        int type;
        do{
            cout<<"What Type the hero to be\n";
            cout<<"1)Paladin\n2)Sorcerer\n3)Warrior\n";
            cin>>type;
            if(!(type>=1&&type<=4))
                cout<<"Not acceptable ansewer!\n";
        }while(!(type>=1&&type<=4));
        
        int name;
        do{
            cout<<"What name the hero should have?\n";
            cout<<"1)I will give him a name\n2)His Type\n\n";
            cin>>name;
            if(!(name>=1&&name<=2))
                cout<<"Not acceptable ansewer!\n";
        }while(!(name>=1&&name<=2));

        string heroName;
        if(name==1){
            cout<<"Give Hero Name\n";
            cin>>heroName;
            if(type==1)
                heros.push_back(new Paladin(heroName));
            else if (type==2)
                heros.push_back(new Sorcerer(heroName));
            else
                heros.push_back(new Warrior(heroName));
    
        }
        else{
            if(type==1)
                heros.push_back(new Paladin("Paladin"));
            else if (type==2)
                heros.push_back(new Sorcerer("Sorcerer"));
            else
                heros.push_back(new Warrior("Warrior"));
        }
        
    }
    return heros;
}

void quitGame(vector<Hero*> heros){
    int size=heros.size();
    for(int i=0;i<size;i++){
        Hero* temp=heros.back();
        heros.pop_back();
        delete temp;
    }
}