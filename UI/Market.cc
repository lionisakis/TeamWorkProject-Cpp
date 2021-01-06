#include "Market.h"

Market::Market(Util util){
    cout << "A new market has been created" << endl;
    srand(time(NULL));
    int j = rand() % 15;
    for(int i = 0; i < j; i++){
        int price = rand() % 15;
        int level = rand() % 10;
        int defence = rand() % 80;
        Item* armor = util.spawnArmor(price, level, defence);
        this->items.push_back(*armor);
    }

    j = rand() % 15;
    for(int i = 0; i < j; i++){
        int price = rand() % 15;
        int level = rand() % 10;
        int damage = rand() % 80;
        int hands = (rand() % 2) + 1;
        Item* weapon = util.spawnWeapon(price, level, damage, hands);
        this->items.push_back(*weapon);
    }

    j = rand() % 15;
    for(int i = 0; i < j; i++){
        int price = rand() % 15;
        int level = rand() % 10;
        int use = rand() % 5;
        int amount = rand() % 60;
        Item* potion = util.spawnPotion(price, level, use, amount, true);
        this->items.push_back(*potion);
    }

    j = rand() % 15;
    for(int i = 0; i < j; i++){
        int price = rand() % 15;
        int level = rand() % 10;
        int decrease = rand() % 80;
        Spell* ice = util.spawnIceSpell(price, level, decrease);
        this->spells.push_back(*ice);
    }

    j = rand() % 15;
    for(int i = 0; i < j; i++){
        int price = rand() % 15;
        int level = rand() % 10;
        int decrease = rand() % 80;
        Spell* fire = util.spawnFireSpell(price, level, decrease);
        this->spells.push_back(*fire);
    }

    j = rand() % 15;
    for(int i = 0; i < j; i++){
        int price = rand() % 15;
        int level = rand() % 10;
        int decrease = rand() % 80;
        Spell* light = util.spawnLightingSpell(price, level, decrease);
        this->spells.push_back(*light);
    }

    this->printItems();
    this->printSpells();
}

Market::~Market(){

}

void Market::printItems(void){
    cout << "The items the market contains are: " << endl;
    for(int i = 0; i < this->items.size(); i++){
        this->items.at(i).print();
    }
}

void Market::printSpells(void){
    cout << "The spells the market contains are: " << endl;
    for(int i = 0; i < this->spells.size(); i++){
        this->spells.at(i).print();
    }
}

void Market::printMarket(void){
    this->printItems();
    this->printSpells();
}

void Market::buy(Hero* hero){
    string name;
    cout << "Choose item" << endl;
    getline(cin, name);
    for(int i = 0; i < this->items.size(); i++){
        Item* item_temp = &this->items.at(i);
        string name_item = item_temp->getName();
        if(name == name_item){
            hero->buy(item_temp);
        }
    }

    for(int i = 0; i < this->spells.size(); i++){
        Spell* spell_temp = &this->spells.at(i);
        string name_spell = spell_temp->getName();
        if(name == name_spell){
            hero->buy(spell_temp);
        }
    }

}