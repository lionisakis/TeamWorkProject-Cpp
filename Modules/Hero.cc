#include "Hero.h"
#include "Items.h"
#include <limits>
#ifdef _WIN32
    #include <Windows.h>
    #define SLEEP true
#else
    #include <unistd.h>
    #define SLEEP false
#endif

Hero::Hero(string nameHero,int strengthHero,int dexerityHero, int agilityHero):
Living(nameHero,1,100)
{   
    mpUsed=0;
    strength=STARTINGSTATS+strengthHero;
    dexerity=STARTINGSTATS+dexerityHero;
    agility=STARTINGSTATS+agilityHero;
    weapon1=NULL;
    weapon2=NULL;
    armor=NULL;
    magicPower = 20;
    maxMP=20;
    money=0;
    experience=0;
    hands=2;
    cout<<"A hero has been created with Name: "<<nameHero<<"\n";
}
Hero::~Hero(){
    while(items.size()){
        Item* temp=items.at(0);
        items.erase(items.begin());
        delete temp;
    }
    while(spells.size()){
        Spell* temp=spells.at(0);
        spells.erase(spells.begin());
        delete temp;
    }
}

bool Hero::levelUp(int strengthHero,int dexerityHero,int agilityHero,int magicPowerHero){
    if (experience<100){
        return false;
    }
    Living::levelUp();
    cout<<"Hero "<<getName()<<" has leved up! Level: "<<getLevel()<<"\n";
    experience=experience-100;
    magicPower+=magicPowerHero;
    maxMP+=magicPowerHero;
    strength+=strengthHero;
    dexerity+=dexerityHero;
    agility+=agilityHero;
    return true;
}

void Hero::addToStat(string type,int increase){
    if(type==HEALTHPOWER){
        cout<<"HealthPower has increasd by "<<increase<<". ";
        increaseHealthPower(increase);
        cout<<"Total HealthPower: "<<getHP()<<"\n";
    }
    else if (type==MAGICPOWER){
        cout<<"Magic Power has increasd by "<<increase<<". ";
        magicPower+=increase;
        maxMP+=increase;
        cout<<"Total Magic Power: "<<magicPower<<"\n";
    }
    else if (type==STRENGTH){
        cout<<"Strength has increasd by "<<increase<<". ";
        strength+=increase;
        cout<<"Total Strength: "<<strength<<"\n";
    }
    else if (type==DEXERITY){
        cout<<"Dexerity has increasd by "<<increase<<". ";
        dexerity+=increase;
        cout<<"Total Dexerity: "<<dexerity<<"\n";
    }
    else if (type==AGILITY){
        cout<<"Agility has increasd by "<<increase<<". ";
        agility+=increase;
        cout<<"Total Agility: "<<agility<<"\n";
    }
}
void Hero::restoreMP(int mp){
    if(magicPower+mp<=maxMP){
        magicPower+=mp;
        cout<<getName()<<" is resotring Magic Power: "<<mp<<"the total Magic Power is:"<<magicPower<<"\n";
    }
}


int Hero::getDexterity(void)const{
    return dexerity;
}

int Hero::getMP(void)const{
    return magicPower;
}

bool Hero::castSpell(Monster* monster){
    cout<<"\n";
    while(true){
        int which;
        bool flag;
        do{
            cout<<"Magic power: "<<magicPower<<"\n";
            cout<<"Spells give enemy debufs accordingly to their type and the rounds is affected by their level. Debufs are:\n";
            cout<<"Fire Spell: Defence Dencrease,\t Ice Spell: Damage Dencrease,\t Lighting Spell Doge Propability Dencrease\n";
            cout<<"Choose a Spell to cast\n";
            cout<<"0) cansel action\n";
            printSpellsCombat();
            cin>>which;
            if (cin.bad()) {
                cout<<"Problem With cin\n";
                return false;
            } 
            if(cin.fail()){
                cout<< "Data entered is not of int type\n"; 
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                flag=true;
            }
            else{
                flag=false;
            }
        }while(flag);
        if(which==0)
            return false;
        if(which>spells.size()){
            cout<<"There is no spell with that number!\n";
            continue;
        }
        if(spells.at(which-1)->getLevel()>getLevel()){
            cout<<"You do not have enought level to cast this spell!\n";
            continue;
        }
        return spellcast(monster,spells.at(which-1));
    }    
}

bool Hero::attack(Monster* monster) const{
    cout<<getName()<<"is atacking "<<monster->getName()<<"\n";
    return monster->takeDamage(getDamage());
}

void Hero::useMagicPower(int usemagicPowerHero){
    magicPower-=usemagicPowerHero;
    if(magicPower<=0)
        magicPower=0;
    mpUsed+=usemagicPowerHero;
}
int Hero::getMPused()const{
    return mpUsed;
}
int Hero::giveEXP(int exp){
    return experience+=exp;
}
bool Hero::spellcast(Monster* monster,Spell* spell){
    if (magicPower-spell->getMagicPower()<0){
        cout<<"Not enought Magic Power left for this spell\n";
        return false;
    }
    
    if(monster->takeDamage(spell->getDamage(this)))
        monster->getDepuff(spell);
    return true;
}
bool Hero::takeDamage(int damage){
    srand(time(NULL));
    int prob= (int) rand()%100;
    if (prob<=agility){
        cout<<"Doged the attack\n";
        return false;
    }
    int armorDF=0;
    if (armor!=NULL)
        armorDF=armor->getDefence();
    cout<<"Taking damge: "<<damage-armorDF<<"\n";
    Living::takeDamage(damage-armorDF);
    cout<<getName()<<" has HP: "<<getHP()<<"\n";
    if(getHP()==0){
        cout<<getName()<<" was killed in combat\n";
    }
    return true;
}
void Hero::addEXP(int exp){
    experience+=exp;
    int level=getLevel();
    while(levelUp(strength/level,dexerity/level,agility/level,magicPower/level));
}

int Hero::getDamage()const{
    int weaponDM=0;
    if (weapon1!=NULL)
        weaponDM+=weapon1->getDamage();
    if (weapon2!=NULL)
        weaponDM+=weapon2->getDamage();
    return 10+strength+weaponDM;
}

bool Hero::buy(Spell* spell){
    if (money-spell->getPrice()<0)
        return false;
    money-=spell->getPrice();
    spells.push_back(spell);
    return true;
}

bool Hero::buy(Item* item){
    if (money-item->getPrice()<0)
        return false;
    money-=item->getPrice();
    items.push_back(item);
    return true;
}
const vector<Item*> Hero::inventory()const{
    return items;
}

void Hero::printItemsForInventory() const{
    cout<<"Items:\n";
    if (items.size()==0){
        cout<<"\tNo items\n";
        printEquipedItems();
    }
    else{
        for (int i=0 ; i< items.size(); i++){
            cout<<"\t"<<i+1<<") ";
            items.at(i)->printCombat();
        }
        printEquipedItems();
    }
}
bool Hero::useInventory(){
    int action;
    while(true){
        int which;
        bool flag=false;
        do{
            cout<<"Choose a item\n";
            cout<<"0) cansel action\n";
            printItemsForInventory();
            cout<<items.size()+1<<") Unequip Sword\n";
            cout<<items.size()+2<<") Unequip Armor\n";

            cin>>which;
            if (cin.bad()) {
                cout<<"Problem With cin\n";
                return false;
            } 
            if(cin.fail()){
                cout<< "Data entered is not of int type\n"; 
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                flag=true;
            }
            else{
                flag=false;
            }
        }while(flag);
        if (which==0){
            return false;
        }
        if(which<0||which>items.size()+2)
            continue;
        if(which==items.size()+1)
            unequipWeapon();
        else if(which==items.size()+2)
            unequipArmor();
        else
            return use(items.at(which-1));
    }
    return false;
}

bool Hero::use(Item* item){
    int index = findItem(item);
    if (item->getLevel() > getLevel()){
        cout<<"The hero has not enough level for this item\n";
        cout<<"Item level: "<<item->getLevel()<<"\n";
        cout<<"Hero level: "<<getLevel()<<"\n";
        return false;
    }
    if (index<0){
        cout<<"You do not have that item";
        return false;
    }
    if (item->getType()==WEAPON){
        return equipWeapon(item);
    }
    else if (item->getType()==ARMOR){
        return equipArmor(item);
    }
    else if (item->getType()==POTION){
        return usePotion(item);
    }
}   

bool Hero::sell(Item* item){
    int index=findItem(item);
    if (index<0){
        cout<<"Not enought money";
        return false;
    }
    if(items.at(index)==weapon1||items.at(index)==weapon2||items.at(index)==armor){
        cout<<"This item is equiped. Unequiped it first then Sell it.\n";
        return false;
    }  
    items.erase(items.begin()+index);
    addMoney(-item->getPrice()/2);
    delete item;
<<<<<<< HEAD
    return true;
}
int Hero::findSpell(Spell* spell)const{
    for (int i=0;i<spells.size();i++)
        if(spells.at(i)==spell)
            return i;
    return -1;
}
bool Hero::sell(Spell* spell){
    int index=findSpell(spell);
    if (index<0){
        cout<<"Not enought money";
        return false;
    }
    if(spells.at(index)==weapon1||spells.at(index)==weapon2||spells.at(index)==armor){
        cout<<"This item is equiped. Unequiped it first then Sell it.\n";
        return false;
    }  
    spells.erase(spells.begin()+index);
    addMoney(-spell->getPrice()/2);
    delete spell;
=======
    addMoney(item->getPrice() / 2);
>>>>>>> 2f36d1cd2e08d88ebf911deede12c1f1fff4ec56
    return true;
}

bool Hero::sell(Spell* spell){
    int index=findSpell(spell);
    if (index<0){
        cout<<"Not enought money";
        return false;
    }
    spells.erase(spells.begin()+index);
    delete spell;
    addMoney(spell->getPrice() / 2);
    return true;
}

void Hero::addMoney(int addMoney){
    money+=addMoney;
}
int Hero::getMoney()const{
    return money;
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
    if(hands==2)
        weapon1=weapon;
    else if (hands==1){
        if(weapon1==weapon){
            cout<<"You have already equiped this weapon\n";
            return false;
        }
        weapon2=weapon;
    }
    hands-=weapon->getHands();
    cout<<"Weapon Equiped:";
    if (weapon1!=NULL){
        weapon1->print();
        if(weapon2!=NULL){
            weapon2->print();
        }
    }
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

bool Hero::usePotion(Item* item){
    Potion* potion=(Potion*)item;
    return potion->use(this);
}

void Hero::unequipWeapon(){
    if(weapon1!=NULL){
        cout<<"Weapon Unequiped:";
        weapon1->printCombat();
        if(weapon2!=NULL){
            weapon2->printCombat();
        }
    }
    else
        cout<<"No armor to Unequip\n";
    if(hands==0){
        weapon2=NULL;
    }
    weapon1=NULL;
    hands=2;
}
void Hero::unequipArmor(){
    if(armor!=NULL){
        cout<<"Armor Unequiped: ";
        armor->printCombat();
    }
    else
        cout<<"No armor to Unequip\n";
    armor=NULL;
}

int Hero::getMagicPower(void)const{
    return magicPower;
}

void Hero::printStats() const {
    cout<<"------------------------------\n";
    cout<<"Damage From Weapon: ";
    int dmg=0;
    if (weapon1!=NULL){
        dmg=weapon1->getDamage();
        if(weapon2!=NULL)
            dmg+=weapon2->getDamage();
    }
    cout<<dmg+10+strength<<"\n";
    cout<<"Weapon Equiped:";
    if (weapon1!=NULL){
        weapon1->print();
        if(weapon2!=NULL){
            weapon2->print();
        }
    }
    cout<<"Magic Power: "<<magicPower<<"\n";
    cout<<"Strength: "<<strength<<"\n";
    cout<<"Dexerity: "<<dexerity<<"\n";
    cout<<"Agility: "<<agility<<"\n";
    cout<<"Experience: "<<experience<<"\n";
    cout<<"------------------------------\n";
}

void Hero::printCombatStats() const{
    cout<<"------------------------------\n";
    Living::printCharacter();
    printStats();
    cout<<"------------------------------\n";
}

void Hero::printEquipedItems() const{
    cout<<"Weapon Equiped:";
    if (weapon1!=NULL){
        weapon1->print();
        if(weapon2!=NULL){
            weapon2->print();
        }
    }
    else 
        cout<<" NONE\n";
    cout<<"Armor equipd : ";
    if (armor!=NULL)
        armor->print();
    else 
        cout<<" NONE\n";
}

void Hero::printSpellsCombat() const{
    cout<<"Spells:\n";
    if (spells.size()==0){
        cout<<"\tNo spells\n";
    }
    else{
        for (int i=0 ; i< spells.size(); i++){
            cout<<"\t"<<i+1<<") ";
            spells.at(i)->printCombat();
            if(SLEEP){
                sleep(40);
            }
            else{
                usleep(1000000);
            }
        }
    }
}

void Hero::printSpells() const{
    cout<<"Spells:\n";
    if (spells.size()==0){
        cout<<"\tNo spells\n";
    }
    else{
        for (int i=0 ; i< spells.size(); i++){
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
    cout<<"Money : "<<money<<"\n";
   
}
void Hero::printInventory() const{
    cout<<"------------------------------\n";
    printMoney();
    printItems();
    printSpells();
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

int Hero::findSpell(const Spell* spell)const{
    for (int i=0;i<spells.size();i++)
        if(spells.at(i)==spell)
            return i;
    return -1;
}

Item* Hero::getItem(int index){
    return items.at(index);
}
    
Spell* Hero::getSpell(int index){
    return spells.at(index);
}