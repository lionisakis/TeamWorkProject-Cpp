#include "UI.h"
#include "Util.h"
#include "Paladin.h"
#include "Warrior.h"
#include "Hero.h"
#include "Sorcerer.h"
#include <vector>

#include <iostream>
#include <limits>

using namespace std;
vector<Hero*> basicCombo(int howMany);
vector<Hero*> yourChoise(int howMany);
vector<Hero*> spawnHeroes(){

    if(true){        
        int howMany=readNumber("Type a number of how many heroes do you want form 1-3\n",1,3);
        if(howMany==-1){
            vector<Hero*>heroes;
            return heroes;    
        }
        string output="Do you want the basic combo?\n1)Yes.\n2)No.\nBasic Combo: ";
        if (howMany==1)
            output.append("Pladin\n");
        else if (howMany==2)
            output.append("Sorcerer and Pladin\n");
        else
            output.append("Warior, Sorcerer and Pladin\n");
        
        int what=readNumber(output,1,2);
        if(what==-1){
            vector<Hero*>heroes;
            return heroes;    
        }
        else if(what==1){
            return basicCombo(howMany);
        }
        else{
            return yourChoise(howMany);
        }
    }
    return basicCombo(3);
}

vector<Hero*> basicCombo(int howMany){
    vector<Hero*> heroes;
    if(howMany==1)
        heroes.push_back(new Paladin("Paladin"));
    else if(howMany==2){
        heroes.push_back(new Sorcerer("Sorcerer"));
        heroes.push_back(new Paladin("Paladin"));
    }
    else {
        heroes.push_back(new Sorcerer("Sorcerer"));
        heroes.push_back(new Warrior("Warrior"));
        heroes.push_back(new Paladin("Paladin"));
    }
    return heroes;        
}
vector<Hero*> yourChoise(int howMany){
    vector<Hero*> heroes;
    for(int i=0;i<howMany;i++){
        int type=readNumber("What Type the hero to be.\n1)Paladin.\n2)Sorcerer.\n3)Warrior.\n",1,3);
        if(type==-1){
            vector<Hero*>heroes;
            return heroes;    
        }
        int name=readNumber("What name the hero should have?\n1)I will give him a name.\n2)His Type.\n",1,3);
        if(name==-1){
            vector<Hero*>heroes;
            return heroes;    
        }
        string heroName="";
        if(name==1){
            bool flag=false;
            do{
                cout<<"Give Hero Name (one word).\n";
                string name;
                cin>> name;
                heroName.append("");
                heroName.append(name);
                cout<<"Do you want to add word to the hero name?\n1)No.\n2)Yes.\nHero Name:"<<heroName<<"\n";
                int answer=readNumber("",1,2);
                if(answer==-1){
                    vector<Hero*>heroes;
                    return heroes;    
                }
                else if(answer==1)
                    flag=false;
                else
                    flag=true;
            }while (flag);
            if(type==1)
                heroes.push_back(new Paladin(heroName));
            else if (type==2)
                heroes.push_back(new Sorcerer(heroName));
            else
                heroes.push_back(new Warrior(heroName));
    
        }
        else{
            if(type==1)
                heroes.push_back(new Paladin("Paladin"));
            else if (type==2)
                heroes.push_back(new Sorcerer("Sorcerer"));
            else
                heroes.push_back(new Warrior("Warrior"));
        }
        
    }
    return heroes;
}

int readNumber(string output,int down,int up){
    int number;
    bool flag;
    do{
        cout<<output;
        cin>>number;
        if (cin.bad()) {
            cout<<"Problem With cin!\n";
            return -1;
        } 
        if(cin.fail()){
            cout<< "Data entered is not of int type.\n"; 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            flag=true;
        }
        else{
            if(!(number>=down&&number<=up)){
                cout<<"Not acceptable answer!\n";
                flag=true;
            }
            else
                flag=false;
        }
    }while(flag);
    return number;
}

void quitGame(vector<Hero*> heroes){
    int size=heroes.size();
    for(int i=0;i<size;i++){
        Hero* temp=heroes.at(0);
        heroes.erase(heroes.begin());
        delete temp;
    }
    cout<<"The Game is closing.\n";
}

int MOOfLevelOfHeroes(vector<Hero*> heroes){
    int level=0;
    for (int i=0;i<heroes.size();i++)
        level+=heroes.at(i)->getLevel();
    if(heroes.size()==0)
        return level;
    return level/heroes.size();
}

void recoverMap(vector<Hero*>heroes){
    for(int i=0;i<heroes.size();i++)
        heroes.at(i)->restoreHP(10);
    for(int i=0;i<heroes.size();i++)
        heroes.at(i)->restoreMP(10);
}