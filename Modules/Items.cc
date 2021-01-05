#include "Items.h"

Item::Item(string name_init, int price_init, int level_init){
    this->name = name_init;
    this->price = price_init;
    this->level = level_init;
    this->type = 0;
    // cout << "A new item with name: " << this->name << " has been created" << endl;
}

Item::~Item(){
    // cout << "An item with name: " << this->name << " is about to be destroyed" << endl;
}

string Item::getName(){
    return this->name;
}

int Item::getPrice(void){
    return this->price;
}

int Item::getLevel(void){
    return this->level;
}

void Item::use(void){
    cout << "You are in items use finction" << endl;
}

int Item::getType(void){
    return this->type;
}

void Item::setType(int type){
    this->type = type;
}

void Item::print(void){
    cout <<  "Name: " << this->name << ", Price: " << this->price << ", Level: " << this->level << endl;
}