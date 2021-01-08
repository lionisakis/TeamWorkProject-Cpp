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
vector<Hero*> spawnHeros(){

    if(true){        
        int howMany=readNumber("Type a number of how many heros do you want form 1-3\n",1,3);
        if(howMany==-1){
            vector<Hero*>heros;
            return heros;    
        }
        string output="Do you want the basic combo?\n No:1, Yes:2\nBasic Combo:\nIf Party is 1 then Hero is Pladin\n";
        output.append("If Party is 2 then Hero is Pladin and Sorcerer\nIf Party is 3 then Hero is Pladin and Sorcerer and Warior\n");
        int what=readNumber(output,1,2);
        if(what==-1){
            vector<Hero*>heros;
            return heros;    
        }
        else if(what==2){
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
        int type=readNumber("What Type the hero to be\n1)Paladin\n2)Sorcerer\n3)Warrior\n",1,3);
        if(type==-1){
            vector<Hero*>heros;
            return heros;    
        }
        int name=readNumber("What name the hero should have?\n1)I will give him a name\n2)His Type\n\n",1,3);
        if(name==-1){
            vector<Hero*>heros;
            return heros;    
        }
        string heroName="";
        if(name==1){
            bool flag=false;
            do{
                cout<<"Give Hero Name (one word)\n";
                string name;
                cin>> name;
                heroName.append(" ");
                heroName.append(name);
                cout<<"Do you want to add word to the hero name?\nNo:1 Yes:2\nHero Name:"<<heroName<<"\n";
                int answer=readNumber("",1,2);
                if(answer==-1){
                    vector<Hero*>heros;
                    return heros;    
                }
                else if(answer==1)
                    flag=false;
                else
                    flag=true;
            }while (flag);
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

int readNumber(string output,int down,int up){
    int number;
    bool flag;
    do{
        cout<<output;
        cin>>number;
        if (cin.bad()) {
            cout<<"Problem With cin\n";
            return -1;
        } 
        if(cin.fail()){
            cout<< "Data entered is not of int type\n"; 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            flag=true;
        }
        else{
            if(!(number>=down&&number<=up)){
                cout<<"Not acceptable ansewer!\n";
                flag=true;
            }
            else
                flag=false;
        }
    }while(flag);
    return number;
}

void quitGame(vector<Hero*> heros){
    int size=heros.size();
    for(int i=0;i<size;i++){
        Hero* temp=heros.at(0);
        heros.erase(heros.begin());
        delete temp;
    }
    cout<<"The Game is closing\n";
}