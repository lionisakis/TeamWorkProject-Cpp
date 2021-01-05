#include "Hero.h"
#include "Items.h"

#define STARTINGSTATS 10

Hero::Hero(string nameHero,int strengthHero,int dexerityHero, int agilityHero):
Living(nameHero)
{
    strength=STARTINGSTATS+strengthHero;
    dexerity=STARTINGSTATS+dexerityHero;
    agility=STARTINGSTATS+agilityHero;
    weapon1=NULL;
    weapon2=NULL;
    armor=NULL;
    magicPower = 20;
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

void Hero::addToStat(int type,int increase){
    if(type==HEALTHPOWER){
        increaseHealthPower(increase);
    }
    else if (type==MAGICPOWER){
        magicPower+=increase;
    }
    else if (type==STRENGTH){
        strength+=increase;
    }
    else if (type==DEXERITY){
        dexerity+=increase;
    }
    else if (type==AGILITY){
        agility+=increase;
    }
}

bool Hero::castSpell(Monster* monster)const{
    int action;
    while(true){
        cout<<"Magic power: "<<magicPower<<"\n";
        cout<<"Choose a Spell to cast\n";
        cout<<"0) cansel action\n";
        printSpells();
        cin>>action;
        if (cin.bad()) {
            cout<<"Problem With cin\n";
            return false;
        }
        if(action==0)
            return false;
        if(!spellcast(monster,spells.at(action-1)))
            return true;    
    }    

}

bool Hero::attack(Monster* monster) const{
    cout<<"Attacking Hero\n";
    int weaponDM=0;
    if (weapon1!=NULL)
        weaponDM+=weapon1->getDamage();
    if (weapon2!=NULL)
        weaponDM+=weapon2->getDamage();
    return monster->takeDamage(10+strength+weaponDM);
}

bool Hero::spellcast(Monster* monster,Spell* spell) const{
    if (magicPower-spell->getMagicPower()<0){
        cout<<"Not enought Magic Power left for this spell\n";
        return false;
    }
    return monster->takeDamage(spell->getDamage(dexerity));
}
bool Hero::takeDamage(int damage){
    srand(time(NULL));
    int prob= (int) rand()%100;
    if (prob<=agility){
        cout<<"Doged\n";
        return false;
    }
    int armorDF=0;
    if (armor!=NULL)
        armorDF=armor->getDefence();
    cout<<"Taking damge: "<<damage-armorDF<<"\n";
    Living::takeDamage(damage-armorDF);
    return true;
}

bool Hero::buy(Spell* spell){
    if (money-spell->getPrice()<0)
        return false;
    money-=spell->getPrice()/2;
    spells.push_back(spell);
    return true;
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

bool Hero::useInBattle(){
    vector<Potion*> potions;
    for(int i=0;i<items.size();i++){
        if(items.at(i)->getType()==3)
            potions.push_back((Potion*)items.at(i));
    }
    
    int which;
    do{

        cout<<"Choose a potion\n";
        cout<<"0) cansel action\n";

        for(int i=0;i<potions.size();i++){
            cout<<i+1<<")";
            potions.at(i)->print();
        }
        int action;
        cin>>action;
        if (cin.bad()) {
            cout<<"Problem With cin\n";
            return false;
        }
        if (action==0){
            return false;
        }
        return use((Item*) potions.at(action));

    }while(which!=0);
    return false;
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
    // potion->use(this);
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

void Hero::printCombatStats() const{
    Living::printCharacter();
    cout<<"Magic Power: "<<magicPower<<"\n";
    cout<<"Magic Power: "<<magicPower<<"\n";
    cout<<"Strength: "<<strength<<"\n";
    cout<<"Dexerity: "<<dexerity<<"\n";
    cout<<"Agility: "<<agility<<"\n";
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

void Hero::printSpells() const{
    cout<<"Spells:\n";
    if (spells.size()==0){
        cout<<"\tNo spells\n";
    }
    else{
        for (int i=0 ; i< items.size(); i++){
            cout<<"\t"<<i+1<<") ";
            spells.at(i)->print();
        }
    }
}
void Hero::printItems() const{
    cout<<"Items:\n";
    if (items.size()==0){
        cout<<"\tNo items\n";
        printEquipedItems();
    }
    else{
        for (int i=0 ; i< items.size(); i++){
            cout<<"\t"<<i+1<<") ";
            items.at(i)->print();
        }
        printEquipedItems();
    }
}

void Hero::printMoney() const{
    cout<<"------------------------------\n";
    cout<<"Money : "<<money<<"\n";
   
}
void Hero::printInventory() const{
    printMoney();
    printItems();
    printSpells();
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