#include "Market.h"

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
        cout << i << ")";
        this->items.at(i)->print();
    }
}

void Market::printSpells(void)const{
    cout << "The spells the market contains are: " << endl;
    int k = this->items.size();
    for(int i = 0; i < this->spells.size(); i++){
        cout << k + i << ")";
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
    cout << "Choose item by entering index" << endl;
    cin >> index;
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
    cout << "Type 1 for Items and 2 for spells" << endl;
    cin >> index;
    if(index == 1){
        hero->printItems();
        cout << "Choose item by nymber" << endl;
        cin >> in;
        in--;
        Item* temp = hero->getItem(in);
        hero->sell(temp);
    }
    if(index == 2){
        hero->printSpells();
        cout << "Choose spell by nymber" << endl;
        cin >> in;
         in--;
        Spell* temp = hero->getSpell(in);
        hero->sell(temp);
    }
}
