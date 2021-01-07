#include "Market.h"
#include "UI.h"

Market::Market(Util util){
    cout << "A new market has been created" << endl;
    srand(time(NULL));
    int j = rand() % 5;
    for(int i = 0; i < j; i++){
        int price = rand() % 15;
        int level = (rand() % 10) + 1;
        int defence = rand() % 80;
        Item* armor = util.spawnArmor(price, level, defence);
        this->items.push_back(armor);
    }

    j = rand() % 5;
    for(int i = 0; i < j; i++){
        int price = rand() % 15;
        int level = (rand() % 10) + 1;
        int damage = rand() % 80;
        int hands = (rand() % 2) + 1;
        Item* weapon = util.spawnWeapon(price, level, damage, hands);
        this->items.push_back(weapon);
    }

    j = rand() % 5;
    for(int i = 0; i < j; i++){
        int price = rand() % 15;
        int level = (rand() % 10) + 1;
        int use = rand() % 5;
        string useString="none";
        if(use==0)
            useString=HEALTHPOWER;
        else if(use==1)
            useString=MAGICPOWER;
        else if(use==2)
            useString=STRENGTH;
        else if(use==3)
            useString=DEXERITY;
        else if(use==4)
            useString=AGILITY;

        int amount = rand() % 60;
        Item* potion = util.spawnPotion(price, level, useString, amount, true);
        this->items.push_back(potion);
    }

    j = rand() % 5;
    for(int i = 0; i < j; i++){
        int price = rand() % 15;
        int level = (rand() % 10) + 1;
        int decrease = rand() % 80;
        Spell* ice = util.spawnIceSpell(price, level, decrease);
        this->spells.push_back(ice);
    }

    j = rand() % 5;
    for(int i = 0; i < j; i++){
        int price = rand() % 15;
        int level = (rand() % 10) + 1;
        int decrease = rand() % 80;
        Spell* fire = util.spawnFireSpell(price, level, decrease);
        this->spells.push_back(fire);
    }

    j = rand() % 5;
    for(int i = 0; i < j; i++){
        int price = rand() % 15;
        int level = (rand() % 10) + 1;
        int decrease = rand() % 80;
        Spell* light = util.spawnLightingSpell(price, level, decrease);
        this->spells.push_back(light);
    }
}

Market::~Market(){
    while(this->items.size()){
        Item* temp = this->items.back();
        this->items.pop_back();
        delete temp;
    }
    while(this->spells.size()){
        Spell* temp = this->spells.back();
        this->spells.pop_back();
        delete temp;
    }
}

void Market::printItems(void)const{
    cout << "The items the market contains are: " << endl;
    for(int i = 0; i < this->items.size(); i++){
        cout << i + 1 << ")";
        this->items.at(i)->print();
    }
}

void Market::printSpells(void)const{
    cout << "The spells the market contains are: " << endl;
    int k = this->items.size();
    for(int i = 0; i < this->spells.size(); i++){
        cout << k + i + 1 << ")";
        this->spells.at(i)->print();
    }
}

void Market::printMarket(void)const{
    this->printItems();
    this->printSpells();
}

void Market::buy(Hero* hero){
    this->printMarket();
    int index;
    cout << "Choose item or spell by entering index or press 0 to quit" << endl;
    index = readNumber("", 0, this->items.size() + this->spells.size());
    if(index == 0)
        return;
    index--;
    for(int i = 0; i < this->items.size(); i++){
        Item* item_temp = this->items.at(i);
        string name_item = item_temp->getName();
        if(index == i){
            hero->buy(item_temp);
            this->items.erase(this->items.begin() + index);
        }
    }

    int k = this->items.size();
    for(int i = 0; i < this->spells.size(); i++){
        Spell* spell_temp = this->spells.at(i);
        string name_spell = spell_temp->getName();
        if(index == k+i){
            hero->buy(spell_temp);
            this->spells.erase(this->spells.begin() + index - k);
        }
    }
}

void Market::sell(Hero* hero){
    hero->printInventory();
    int index;
    int in;
    cout << "Type 1 for Items and 2 for spells or press 0 to quit" << endl;
    index = readNumber("", 0, 2);
    if(index == 0)
        return;
    if(index == 1){
        hero->printItems();
        cout << "Choose item by nymber, press 0 to exit" << endl;
        in = readNumber("", 1, hero->getItemSize());
        if(in == 0){
            return;
        }
        in--;
        Item* temp = hero->getItem(in);
        hero->sell(temp);
        this->items.push_back(temp);
    }
    if(index == 2){
        hero->printSpells();
        cout << "Choose spell by nymber, press 0 to exit" << endl;
        in = readNumber("", 1, hero->getSpellSize());
        if(in == 0){
            return;
        }
        in--;
        Spell* temp = hero->getSpell(in);
        this->spells.push_back(temp);
        hero->sell(temp);
    }
}

void Market::useMarket(Hero* hero){
    cout << "Welcome to the market press:" << endl;
    cout << "0: To quit the store." << endl;
    cout << "1: To see the available products." << endl;
    cout << "2: To buy something." << endl;
    cout << "3: To sell something" << endl;
    cout << "4: To see wallet." << endl;
    cout << "5 to see inventory." << endl;
    int index;
    index = readNumber("", 0, 5);
    if(index == 0)
        return;
    else if(index == 1)
        this->printMarket();
    else if(index == 2)
        this->buy(hero);
    else if(index == 3)
        this->sell(hero);
    else if(index == 4)
        hero->printMoney();
    else if(index == 5)
        hero->printInventory();
    else{
        cout << "Wrong input please try again" << endl; 
        this->useMarket(hero);
    }
    cout << "Do you want something else? Press 1 for yes and 2 for no." << endl;
    index = readNumber("", 1, 2);
    if(index == 1)
        this->useMarket(hero); 
    return;
}