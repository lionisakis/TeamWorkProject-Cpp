#include "Hero.h"

#define STARTINGSTATS 10
#define MAGICPOWER 20

Hero::Hero(string nameHero,int strengthHero,int dexerityHero, int agilityHero):
Living(nameHero)
{
    strength=STARTINGSTATS+strengthHero;
    dexerity=STARTINGSTATS+dexerityHero;
    agility=STARTINGSTATS+agilityHero;
    weapon=NULL;
    armor=NULL;
    magicPower=MAGICPOWER;
    money=0;
    experience=0;
}

void Hero::levelUp(int strengthHero,int dexerityHero,int agilityHero,int magicPowerHero){
    if (experience<100){
        cout<<"Cannot level up. Experience:"<<experience<<"%\n";
        return;
    }
    Living::levelUp();
    experience=experience-100;
    magicPower+=magicPowerHero;
    strength+=strengthHero;
    dexerity+=dexerityHero;
    agility+=agilityHero;
}

void Hero::attack(Monster* monster) const{
    cout<<"Attacking Hero\n";
    int weaponDM=0;
    if (weapon!=NULL)
        weaponDM=weapon->getDamage();
    monster->takeDamage(10+strength+weaponDM);

}

bool Hero::spellcast(Monster* monster,Spell* spell) const{
    // if (magicPower-spell->getMagic()<0){
    //     cout<<"Not enought Magic Power left for this spell\n"
    //     return false;
    // }
    // spell->getDamage(10+);
    return false;
}
void Hero::takeDamage(int damage){
    int prob= (int) rand()%100;
    if (prob<=dexerity){
        cout<<"Doged\n";
        return;
    }
    int armorDF=0;
    if (armor!=NULL)
        armorDF=armor->getDefence();
    cout<<"Taking damge: "<<damage-armorDF<<"\n";
    Living::takeDamage(damage-armorDF);
}

void Hero::printStats() const {
    cout<<"------------------------------\n";
    cout<<"Magic Power: "<<magicPower<<"\n";
    cout<<"Strength: "<<strength<<"\n";
    cout<<"Dexerity: "<<dexerity<<"\n";
    cout<<"Agility: "<<agility<<"\n";
    cout<<"Experience: "<<experience<<"\n";
    cout<<"Money: "<<money<<"\n";
    cout<<"------------------------------\n";
}

bool Hero::buy(Item* item){
    if (money-item->getPrice()<0)
        return false;
    money-=item->getPrice()/2;
    items.push_back(item);
    return true;
}
const vector<Item*> Hero::inventory()const{
    return items;
}

bool Hero::use(Item* item){
    int index = findItem(item);
    if (index<0){
        cout<<"You do not have that item";
        return false;
    }
    return true;
    // if (item->type()=="Weapon"){
        
    // }
    // else if (item->type()=="Armor"){

    // }
    // else{
    //     item->use();
    // }
}

bool Hero::sell(Item* item){
    int index=findItem(item);
    if (index<0){
        cout<<"Not enought money";
        return false;
    }
    items.erase(items.begin()+index);
    addMoney(item->getPrice());
}
void Hero::addMoney(int addMoney){
    money+=addMoney;
}
        
void Hero::printEquipedItems() const{
    cout<<"Weapon : ";
    if (weapon!=NULL)
        weapon->getName();
    else 
        cout<<" NONE";
    cout<<"\n";
    cout<<"Armor  : ";
    if (armor!=NULL)
        armor->getName();
    else 
        cout<<" NONE";
    cout<<"\n";
}

void Hero::printInventory() const{
    cout<<"------------------------------\n";
    cout<<"Money : "<<money<<"\n";
    cout<<"Items:\n";
    if (items.size()==0){
        cout<<"\tNo items\n";
        printEquipedItems();
        cout<<"------------------------------\n";
        return;
    }
    for (int i=0 ; i< items.size(); i++)
        cout<<"\t"<<i+1<<") "<<items.at(i)->getName()<<"\n";
        // items.at(i)->print();
    printEquipedItems();
    cout<<"------------------------------\n";

}

void Hero::print() const{
    Living::printCharacter();
    printStats();
    printInventory();
}

int Hero::findItem(const Item* item)const{
    for (int i=0;i<items.size();i++)
        if(items.at(i)==item)
            return i;
    return -1;
}