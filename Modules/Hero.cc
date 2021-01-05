#include "Hero.h"
#include "Items.h"

#define STARTINGSTATS 10
#define MAGICPOWER 20

Hero::Hero(string nameHero,int strengthHero,int dexerityHero, int agilityHero):
Living(nameHero)
{
    strength=STARTINGSTATS+strengthHero;
    dexerity=STARTINGSTATS+dexerityHero;
    agility=STARTINGSTATS+agilityHero;
    weapon1=NULL;
    weapon2=NULL;
    armor=NULL;
    magicPower=MAGICPOWER;
    money=0;
    experience=0;
    hands=0;
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
    if (weapon1!=NULL)
        weaponDM+=weapon1->getDamage();
    if (weapon2!=NULL)
        weaponDM+=weapon2->getDamage();
    monster->takeDamage(10+strength+weaponDM);

}

bool Hero::spellcast(Monster* monster,Spell* spell) const{
    if (magicPower-spell->getMagicPower()<0){
        cout<<"Not enought Magic Power left for this spell\n";
        return false;
    }
    // spell->getDamage(10+);
    return true;
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
    if (item->getLevel()>getLevel()){
        cout<<"The hero has not enough level for this item\n";
        cout<<"Item level: "<<item->getLevel()<<"\n";
        cout<<"Hero level: "<<getLevel()<<"\n";
        return false;
    }
    if (index<0){
        cout<<"You do not have that item";
        return false;
    }
    if (item->getType()==1){
        equipWeapon(item);
    }
    else if (item->getType()==2){
        equipArmor(item);
    }
    else if (item->getType()==3){
        usePotion(item);
    }
    return true;
}   

bool Hero::sell(Item* item){
    int index=findItem(item);
    if (index<0){
        cout<<"Not enought money";
        return false;
    }
    items.erase(items.begin()+index);
    addMoney(item->getPrice());
    return true;
}
void Hero::addMoney(int addMoney){
    money+=addMoney;
}

bool Hero::equipWeapon(Item* item){
    if (findItem(item)<0 || item->getType()!=WEAPON){
        cout<<"You cannot equip that item!\n";
        return false;
    }
    Weapon* weapon=(Weapon*)item;
    if (hands-weapon->getHands()<0){
        cout<<"Not enough hands to cary this.\n";
        cout<<"Unequip the current Weapon\n";
        return false;
    }
    if(hands==0)
        weapon1=weapon;
    else
        weapon2=weapon;
    return true;
}
bool Hero::equipArmor(Item* item){
    if (findItem(item)<0 || item->getType()!=ARMOR){
        cout<<"You do cannot equip that item!\n";
        return false;
    }
    unequipArmor();
    armor=(Armor*)item;
    return true;
}

void Hero::usePotion(Item* item){
    Potion* potion=(Potion*)item;
    // potion->use();
}

void Hero::unequipWeapon(){
    if(hands==2){
        weapon2=NULL;
    }
    weapon1=NULL;
}
void Hero::unequipArmor(){
    armor=NULL;
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

void Hero::printEquipedItems() const{
    cout<<"Weapon at hand : ";
    if (weapon1!=NULL){
        weapon1->print();
        if(weapon2!=NULL){
            weapon2->print();
        }
    }
    else 
        cout<<" NONE";
    cout<<"\n";
    cout<<"Armor equipd : ";
    if (armor!=NULL)
        armor->print();
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
    }
    else{
        for (int i=0 ; i< items.size(); i++){
            cout<<"\t"<<i+1<<") ";
            items.at(i)->print();
        }
        printEquipedItems();
        cout<<"------------------------------\n";

    }
   
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