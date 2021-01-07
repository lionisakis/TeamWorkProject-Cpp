#include "Items.h"
#include "Armor.h"
#include "Potion.h"
#include "Weapon.h"

Item::Item(string name_init, int price_init, int level_init){
    this->name = name_init;
    this->price = price_init;
    this->level = level_init;
    this->type = "None";
    // cout << "A new item with name: " << this->name << " has been created" << endl;
}

Item::~Item(){
    // cout << "An item with name: " << this->name << " is about to be destroyed" << endl;
}

string Item::getName()const{
    return this->name;
}

int Item::getPrice(void)const{
    return this->price;
}

int Item::getLevel(void)const{
    return this->level;
}

void Item::use(void){
    cout << "You are in items use finction" << endl;
}

string Item::getType(void)const{
    return this->type;
}

void Item::setType(string type){
    this->type = type;
}
void Item::printCombat(void)const{
    if(type==WEAPON){
        Weapon* weapon=(Weapon*)this;
        cout <<  "Name: " << this->name << ", Level: " << this->level <<", Damage: "<<weapon->getDamage()<<", Hands needed: "<<weapon->getHands()<<  endl;
    }
    else if (type==ARMOR){
        Armor* armor=(Armor*)this;
        cout <<  "Name: " << this->name << ", Level: " << this->level <<", Defence: "<<armor->getDefence()<< endl;
    }
    else if (type==POTION){
        Potion* potion=(Potion*)this;
        cout <<  "Name: " << this->name << ", Level: " << this->level <<", Increase Type: "<<potion->getType()<<", Amount: "<<potion->getAmount()<<", Used"<<potion->getAvailable()<<  endl;
    }
}
void Item::print(void)const{
    if(type==WEAPON){
        Weapon* weapon=(Weapon*)this;
        cout <<  "Name: " << this->name << ", Price: "<<this->price<< ", Level: " << this->level <<", Damage: "<<weapon->getDamage()<<", Hands needed: "<<weapon->getHands()<<  endl;
    }
    else if (type==ARMOR){
        Armor* armor=(Armor*)this;
        cout <<  "Name: " << this->name << ", Price: "<<this->price<<", Level: " << this->level <<", Defence: "<<armor->getDefence()<< endl;
    }
    else if (type==POTION){
        Potion* potion=(Potion*)this;
        cout <<  "Name: " << this->name << ", Price: "<<this->price<< ", Level: " << this->level <<", Increase Type: "<<potion->getType()<<", Amount: "<<potion->getAmount()<<", Used"<<potion->getAvailable()<<  endl;
    }}